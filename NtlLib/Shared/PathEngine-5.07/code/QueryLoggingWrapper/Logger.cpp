//**********************************************************************
//
// Copyright (c) 2005
// PathEngine
// Lyon, France
//
// All Rights Reserved
//
//**********************************************************************

#include "platform_common/Header.h"
#include "Logger.h"
#include "WrapperManagement.h"
#include "platform_common/ToAndFromByteBuffer.h"
#include "platform_common/Timer.h"
#include "platform_common/LoadSaveBinary.h"
#include "common/VectorBuildingOutputStream.h"
#include "common/interface/Error.h"
#include "common/interface/Assert.h"
#include "common/STL/sstream.h"
#include "i_pathengine.h"

cLogger gLogger;

void
cLogger::writeBuffer()
{
    if(_file)
    {
        long entrySize = SizeL(_buffer);
        assertD(entrySize < 0xffffL);
        UnsignedToByteBuffer(static_cast<unsigned long>(entrySize), 2, &_buffer.front());
        size_t written = fwrite(&_buffer.front(), 1, _buffer.size(), _file);
        if(written != _buffer.size())
        {
            Error("Warning", "Query Logging Wrapper: fwrite failed, switching to pass-through mode.");
            fclose(_file); // already an error, so no point really in checking return value
            _file = 0;
        }
        else
        {
            int error = fflush(_file);
            if(error)
            {
                Error("Warning", "Query Logging Wrapper: fflush() returned non-zero.");
            }
        }
    }
    _buffer.resize(0);
}
void
cLogger::signedToBuffer(long value, long tokenSize)
{
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(sizeBefore + tokenSize);
    SignedToByteBuffer(value, tokenSize, &_buffer[sizeBefore]);
}
void
cLogger::unsignedToBuffer(unsigned long value, long tokenSize)
{
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(sizeBefore + tokenSize);
    UnsignedToByteBuffer(value, tokenSize, &_buffer[sizeBefore]);
}
void
cLogger::boolToBuffer(bool value)
{
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(sizeBefore + 1);
    SignedToByteBuffer(value, 1, &_buffer[sizeBefore]);
}
void
cLogger::pointerToBuffer(void* voidPointer)
{
    assertC(sizeof(voidPointer) == 4);
    unsigned long asUL = (unsigned long)voidPointer;
    assertD((asUL & 1) == 0);
    unsignedToBuffer(asUL, 4);
}

void
cLogger::initialise()
{
    _file = fopen("queryLog.bin", "wb");
    if(!_file)
    {
        Error("Warning", "Query Logging Wrapper: Could not open 'queryLog.bin' for writing, switching to pass-through mode.");
    }
    _queryCount = 0;
    _fileIndex_DataBuffer = 1;
    _fileIndex_SourceContent = 1;
}
void
cLogger::shutdown()
{
    if(_file)
    {
        int error = fclose(_file);
        if(error)
        {
            Error("Warning", "Query Logging Wrapper: Error closing 'queryLog.bin'.");
        }
    }
}

unsigned long
cLogger::methodEntry(long interfaceIndex, long methodIndex, void* interfacePointer)
{
    _mutex.lock();
    assertD(_buffer.empty());
    assertD(interfaceIndex < 128);
    _buffer.resize(2); // reserve space for entry size
    signedToBuffer(interfaceIndex, 1);
    signedToBuffer(methodIndex, 1);
    unsignedToBuffer(_queryCount, 4);
    pointerToBuffer(interfacePointer);
    assertC(TIMESTAMP_BYTE_SIZE == 6);
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(_buffer.size() + TIMESTAMP_BYTE_SIZE);
    GetTimeStamp(&_buffer[sizeBefore]);
    return _queryCount;
}
void
cLogger::methodEntry_Completed()
{
    writeBuffer();
    ++_queryCount;
    _mutex.unlock();
}
void
cLogger::methodExit(long interfaceIndex, long methodIndex, unsigned long queryCount, void* interfacePointer)
{
    _mutex.lock();
    assertD(_buffer.empty());
    assertD(interfaceIndex < 128);
    _buffer.resize(2); // reserve space for entry size
    signedToBuffer(-1 - interfaceIndex, 1);
    signedToBuffer(methodIndex, 1);
    unsignedToBuffer(queryCount, 4);
    pointerToBuffer(interfacePointer);
    assertC(TIMESTAMP_BYTE_SIZE == 6);
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(_buffer.size() + TIMESTAMP_BYTE_SIZE);
    GetTimeStamp(&_buffer[sizeBefore]);
}
void
cLogger::methodExit_Completed()
{
    writeBuffer();
    _mutex.unlock();
}

void
cLogger::log(bool value)
{
    long valueAsLong = value ? 1 : 0;
    signedToBuffer(valueAsLong, 1);
}
void
cLogger::log(long value)
{
    signedToBuffer(value, 4);
}
void
cLogger::log(unsigned long value)
{
    unsignedToBuffer(value, 4);
}
void
cLogger::log(float value)
{
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(sizeBefore + FLOAT_BYTE_SIZE);
    FloatToByteBuffer(value, &_buffer[sizeBefore]);
}
void
cLogger::log(const char* string)
{
    size_t len = strlen(string);
    assertD(len <= 0xffffUL);
    unsignedToBuffer(static_cast<unsigned long>(len), 2);
    long sizeBefore = SizeL(_buffer);
    _buffer.resize(sizeBefore + len);
    strcpy(&_buffer[sizeBefore], string);
}

void
cLogger::log(const char *const* attributes)
{
    if(attributes)
    {
        while(*attributes)
        {
            assertD(attributes[1]);
            size_t nameLen = strlen(attributes[0]);
            assertD(nameLen > 0);
            assertD(nameLen <= 0xffffUL);
            unsignedToBuffer(static_cast<unsigned long>(nameLen), 2);
            {
                long sizeBefore = SizeL(_buffer);
                _buffer.resize(sizeBefore + nameLen);
                strcpy(&_buffer[sizeBefore], attributes[0]);
            }
            size_t valueLen = strlen(attributes[1]);
            assertD(valueLen <= 0xffffUL);
            unsignedToBuffer(static_cast<unsigned long>(valueLen), 2);
            {
                long sizeBefore = SizeL(_buffer);
                _buffer.resize(sizeBefore + valueLen);
                strcpy(&_buffer[sizeBefore], attributes[1]);
            }
            attributes += 2;
        }
    }
    unsigned long endMarker = 0;
    unsignedToBuffer(endMarker, 2);
}

void
cLogger::log(const long* point)
{
    signedToBuffer(point[0], 4);
    signedToBuffer(point[1], 4);
    signedToBuffer(point[2], 4);
}

void
cLogger::log(const float* point)
{
    log(point[0]);
    log(point[1]);
    log(point[2]);
}

void
cLogger::log(const cPosition& position)
{
    signedToBuffer(position.cell, 4);
    signedToBuffer(position.x, 4);
    signedToBuffer(position.y, 4);
}
void
cLogger::log(const cHorizontalRange& range)
{
    signedToBuffer(range.minX, 4);
    signedToBuffer(range.minY, 4);
    signedToBuffer(range.maxX, 4);
    signedToBuffer(range.maxY, 4);
}

void
cLogger::log(void* voidPointer)
{
    pointerToBuffer(voidPointer);
}
void
cLogger::logCollidingLine(long* coords)
{
    long i;
    for(i = 0; i != 4; ++i)
    {
        signedToBuffer(coords[i], 4);
    }
}
void
cLogger::logCollisionShape(long numberOfPoints, const long* coordinateData)
{
    signedToBuffer(numberOfPoints, 4);
    long i;
    for(i = 0; i != numberOfPoints * 2; ++i)
    {
        signedToBuffer(coordinateData[i], 4);
    }
}
void
cLogger::logDataBuffer(const char* dataBuffer, unsigned long bufferSize)
{
    std::stringstream oss;
    oss << "loggedDataBuffer" << _fileIndex_DataBuffer << ".bin";
    bool success = SaveBinary(oss.str().c_str(), dataBuffer, bufferSize);
    unsignedToBuffer(_fileIndex_DataBuffer, 2);    
    _fileIndex_DataBuffer++;
}
void
cLogger::logPathBuffers(const cPosition* positionsBuffer, const long* connectionIndicesBuffer, long pathLength)
{
    signedToBuffer(pathLength, 4);
    long i;
    for(i = 0; i != pathLength; ++i)
    {
        signedToBuffer(positionsBuffer[i].cell, 4);
        signedToBuffer(positionsBuffer[i].x, 4);
        signedToBuffer(positionsBuffer[i].y, 4);
    }
    bool connectionIndicesBufferNonZero = (connectionIndicesBuffer != 0);
    boolToBuffer(connectionIndicesBufferNonZero);
    if(connectionIndicesBufferNonZero)
    {
        for(i = 0; i + 1 < pathLength; ++i)
        {
            signedToBuffer(connectionIndicesBuffer[i], 4);
        }
    }
}
void
cLogger::logSourceContent(const iFaceVertexMesh* const* geometryObjectPointers, long numberOfGeometryObjects)
{
    iPathEngine* pathEngine = ExtractWrappedSingleton();
    cVectorBuildingOutputStream os;
    pathEngine->saveContentData(geometryObjectPointers, numberOfGeometryObjects, "tok", &os);
    std::stringstream oss;
    oss << "loggedSourceContent" << _fileIndex_SourceContent << ".bin";
    bool success = SaveBinary(oss.str().c_str(), os._buffer);
    unsignedToBuffer(_fileIndex_SourceContent, 2);
    _fileIndex_SourceContent++;
}
void
cLogger::logAgentVector(iAgent** resultsBuffer, long& numberOverlapped)
{
    signedToBuffer(numberOverlapped, 4);
    long i;
    for(i = 0; i != numberOverlapped; ++i)
    {
        pointerToBuffer(static_cast<void*>(resultsBuffer[i]));
    }
}
void
cLogger::logContentChunkInstanceVector(const iContentChunkInstance* const* instancePointers, long numberOfInstances)
{
    signedToBuffer(numberOfInstances, 4);
    long i;
    for(i = 0; i != numberOfInstances; ++i)
    {
        iContentChunkInstance* nonConstPointer = const_cast<iContentChunkInstance*>(instancePointers[i]);
        pointerToBuffer(static_cast<void*>(nonConstPointer));
    }
}
void
cLogger::logLongVector(long* resultsBuffer, long& numberOverlapped)
{
    signedToBuffer(numberOverlapped, 4);
    long i;
    for(i = 0; i != numberOverlapped; ++i)
    {
        signedToBuffer(resultsBuffer[i], 4);
    }
}
