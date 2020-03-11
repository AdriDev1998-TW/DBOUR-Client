//***********************************************************************************
//
//	File		:	NtlClientNet.h
//
//	Begin		:	2006-01-17
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	NTL Client Library header file
//
//***********************************************************************************

#pragma once

#include "ClentNetCompileOption.h"
#include "..\..\DboClient\Lib\NtlCore\NtlConsole.h"
#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
#include "BotsystemLog_Client.h"
#endif

/*-------------------------------------------------------------------------------------
	[1/10/2007 zeroera] 
---------------------------------------------------------------------------------------

@ Ŭ���̾�Ʈ ��Ʈ��ũ ���̺귯���� ����ϴ� ����� ������ �ΰ��� ��ϴ�.

	1. Windows Message Base 

		ClientNetwork ��ü�� �����ϰ� Create�� �޽����� ���� ������ �ڵ��� �����մϴ�.
		
	2. Event Base

		ClientNetwork ��ü�� �����ϰ� Create�� ������ �ڵ��� NULL�� ���� �մϴ�.

---------------------------------------------------------------------------------------*/


//---------------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------------
#define WM_NETWORK_IO						(WM_USER + 0x1000) // WM_USER = 0x0400
#define WM_INCOMING_PACKET					(WM_USER + 0x1001)
#define WM_CONNECTED						(WM_USER + 0x1002)
#define WM_DISCONNECTED						(WM_USER + 0x1003)
#define WM_CONNECT_FAIL						(WM_USER + 0x1004)

#define NETCLIENT_EVENT_CONNECTED			0x0001
#define NETCLIENT_EVENT_DISCONNECTED		0x0002
#define NETCLIENT_EVENT_CONNECT_FAIL		0x0003

#define INVALID_HSERVER						INVALID_SOCKET
//---------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------
const unsigned int ALIVE_PACKET_FREQUENCY	= 3 * 1000; // ������ Alive Ping�� ������ �ð� ����
//---------------------------------------------------------------------------------------
typedef SOCKET HSERVER;	// ���� �ڵ� �� ( = ���� �� )
typedef void (*NtlClientNetLogCallback)(const char * format); // Application Log Callback
typedef void (*NtlClientNetEventCallback)(HSERVER hServer, int nEvent);	// Application Event Callback
//-- define -------------------------------------------------------------------------
class CRecvPacketProcess
{
public:
	CRecvPacketProcess( const HSERVER hServer )
		: m_hServer( hServer )
	{
	}

	~CRecvPacketProcess(){};

public:
	virtual bool RecvPacketProcess( void* const pData ) = 0;
	virtual bool IsActivePop( void ) { return true; }

public:
	HSERVER m_hServer;

};//end of class CRecvPacketProcess
//---------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------
enum eNETCLIENT_ENCODE_TYPE
{
	NETCLIENT_ENCODE_NONE = 0,
	NETCLIENT_ENCODE_XOR,
	NETCLIENT_ENCODE_RANDKEY,

	MAX_NETCLIENT_ENCODE_TYPE
};
//---------------------------------------------------------------------------------------

void NtlClientNetSetPrintFlag( unsigned int dwFlag );
//class CPacketConsole
//{
//public:
//	CNtlConsole m_clConsole;
//
//public:
//	CPacketConsole(void)	{ m_clConsole.Create("Packet"); m_clConsole.Show(); m_clConsole.Color(FOREGROUND_GREEN | FOREGROUND_BLUE); }
//	~CPacketConsole(void)	{ m_clConsole.Close(); }
//	
//	
//
//#define OUT_QMSG_0(s)					g_clConsole.m_clConsole.Output(s"\n");
//#define OUT_QMSG_1(s,p1)				g_clConsole.m_clConsole.Output(s"\n",p1)
//#define OUT_QMSG_2(s,p1,p2)				g_clConsole.m_clConsole.Output(s"\n",p1,p2)
//#define OUT_QMSG_3(s,p1,p2,p3)			g_clConsole.m_clConsole.Output(s"\n",p1,p2,p3)
//#define OUT_QMSG_4(s,p1,p2,p3,p4)		g_clConsole.m_clConsole.Output(s"\n",p1,p2,p3,p4)
//#define OUT_QMSG_5(s,p1,p2,p3,p4,p5)	g_clConsole.m_clConsole.Output(s"\n",p1,p2,p3,p4,p5)
//#define OUT_QMSG_6(s,p1,p2,p3,p4,p5,p6)	g_clConsole.m_clConsole.Output(s"\n",p1,p2,p3,p4,p5,p6)
//};
//---------------------------------------------------------------------------------------
// NtlClientNet Class
//---------------------------------------------------------------------------------------
class CClientNetImp;
class CNtlClientNet
{
public:

	CNtlClientNet();

	virtual ~CNtlClientNet();

public:

	// �ݹ��Լ��� ����ϸ� �� �Լ��� ���̻� ȣ����� �ʽ��ϴ�.
	virtual void				OnNetEventProc(HSERVER hServer, int nEvent) { UNREFERENCED_PARAMETER(hServer), UNREFERENCED_PARAMETER(nEvent); }


public:


	bool						Create(HWND hWnd = NULL, NtlClientNetEventCallback EventCallback = NULL, NtlClientNetLogCallback LogCallback = NULL, DWORD dwAliveTime = ALIVE_PACKET_FREQUENCY, int nMaxConnection = WSA_MAXIMUM_WAIT_EVENTS);

	void						Destroy();


public:

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
	bool						Connect( __int64 nBotID, char* szServerAddress, WORD wPort, HSERVER * pServerHandle, bool bAsync = false, eNETCLIENT_ENCODE_TYPE encode = NETCLIENT_ENCODE_RANDKEY, int nMaxPacketCount = 0, int nMaxPacketSize = 0 );

	bool						Connect( __int64 nBotID, WCHAR* pwszServerAddress, WORD wPort, HSERVER * pServerHandle, bool bAsync /* = false */, eNETCLIENT_ENCODE_TYPE encode /* = NETCLIENT_ENCODE_RANDKEY */, int nMaxPacketCount /* = 0 */, int nMaxPacketSize /* = 0 */);

	void *						SGPeekPacket(HSERVER hServer);

#else
	bool						Connect(char* szServerAddress, WORD wPort, HSERVER * pServerHandle, bool bAsync = false, eNETCLIENT_ENCODE_TYPE encode = NETCLIENT_ENCODE_NONE, int nMaxPacketCount = 0, int nMaxPacketSize = 0 );

	bool						Connect(WCHAR* pwszServerAddress, WORD wPort, HSERVER * pServerHandle, bool bAsync /* = false */, eNETCLIENT_ENCODE_TYPE encode /* = NETCLIENT_ENCODE_RANDKEY */, int nMaxPacketCount /* = 0 */, int nMaxPacketSize /* = 0 */);

#endif

public:

	bool						Disconnect(HSERVER hServer);

	bool						NetMsgProc(WPARAM wParam, LPARAM lParam);		

	void *						PeekPacket(HSERVER hServer);	

	void 						PopPacket(HSERVER hServer);

	bool						PushPacket(HSERVER hServer, void * pData, int nDataSize);

	bool						IsProgress(HSERVER hServer);


public:

	LPCSTR						GetServerAddress(HSERVER hServer);

	WORD						GetServerPort(HSERVER hServer);

	LPCSTR						GetLocalAddress(HSERVER hServer);

	DWORD						GetLocalAddr(HSERVER hServer);

	WORD						GetLocalPort(HSERVER hServer);

public:

	void						RecvPacketProcess( CRecvPacketProcess& rProc );

private:

	CClientNetImp *				m_pImp;

};