//***********************************************************************************
//	File		:	NtlResourceEffect.cpp
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	ⓒ 2005 by agebreak CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************
#include "precomp_ntlpresentation.h"
#include ".\ntlresourceeffect.h"

#include "NtlResourceParticleSystem.h"
#include "NtlResourceMeshSystem.h"
#include "NtlResourceBeamSystem.h"
#include "NtlResourceHurricaneSystem.h"
#include "NtlResourceLightningSystem.h"
#include "NtlResourceDecalSystem.h"
#include "NtlResourcePostEffectSystem.h"
#include "NtlResourceLineSystem.h"

#include "NtlDebug.h"

#include "NtlAnimEventData.h"

RwUInt32    CNtlResourceEffect::m_nVersion;
RwBool      CNtlResourceEffect::m_bUpdateBoundingSphere = FALSE;      

CNtlResourceEffect::CNtlResourceEffect(const RwChar* strName)
{
	SetName(strName);
//#SetAddColor // To enable effects --Kalisto
	m_bShow	= TRUE;
//#endif

	m_fScaleForTool = 1.0f;
  
}

CNtlResourceEffect::~CNtlResourceEffect(void)
{
	Destroy();
}


//------------------------------------------------------------------
//	FuncName	: Destroy
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
RwBool CNtlResourceEffect::Destroy()
{
	if (!m_svResourceSystem.empty())
	{
		svdef_ResourceComponentSystem::iterator it;
		for (it = m_svResourceSystem.begin(); it != m_svResourceSystem.end(); ++it)
		{
			NTL_DELETE(*it);
		}
		m_svResourceSystem.clear();
	}

	return TRUE;
}


//------------------------------------------------------------------
//	FuncName	: CreateResourceSystem
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
//template <size_t S> class Sizer { };
//Sizer<sizeof(CNtlResourceLightningSystem)> foo;
CNtlResourceComponentSystem* CNtlResourceEffect::CreateResourceSystem(RwInt8 nType, const RwChar* strName)
{
	CNtlResourceComponentSystem* pResourceSystem = NULL;
	switch(nType)
	{
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE:
		pResourceSystem = NTL_NEW CNtlResourceParticleSystem(strName);
		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_MESH:
		pResourceSystem = NTL_NEW CNtlResourceMeshSystem(strName);
		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_BEAM:
		pResourceSystem = NTL_NEW CNtlResourceBeamSystem(strName);
		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_HURRICANE:
		pResourceSystem = NTL_NEW CNtlResourceHurricaneSystem(strName);
		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LIGHTNING:
		pResourceSystem = NTL_NEW CNtlResourceLightningSystem(strName);
		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_DECAL:
		pResourceSystem = NTL_NEW CNtlResourceDecalSystem(strName);
		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_POST_EFFECT:
		pResourceSystem = NTL_NEW CNtlResourcePostEffectSystem(strName);
		break;    
    case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LINE:
        pResourceSystem = NTL_NEW CNtlResourceLineSystem(strName);
        break;
	}
	NTL_ASSERTE(pResourceSystem);
	return pResourceSystem;
}


//------------------------------------------------------------------
//	FuncName	: GetResourceSystem
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
CNtlResourceComponentSystem* CNtlResourceEffect::GetResourceSystem(const RwChar* strSystemName)
{
	svdef_ResourceComponentSystem::iterator it;
	for (it = m_svResourceSystem.begin(); it != m_svResourceSystem.end(); ++it)
	{
		if (_stricmp((*it)->GetSystemName(), strSystemName) == 0)
		{
			return (*it);
		}
	}
	return NULL;
}

//------------------------------------------------------------------
//	FuncName	: ResetSubSystem
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
void CNtlResourceEffect::ResetSubSystem()
{
	svdef_ResourceComponentSystem::iterator it;
	for (it = m_svResourceSystem.begin(); it != m_svResourceSystem.end(); ++it)
	{
		(*it)->m_bSubSystem = FALSE;
	}

	for (it = m_svResourceSystem.begin(); it != m_svResourceSystem.end(); ++it)
	{
		if ((*it)->GetSystemType() == CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE)
		{
			CNtlResourceParticleSystem* pResourceParticleSystem = (CNtlResourceParticleSystem*)(*it);
			if (pResourceParticleSystem->IsEmitterDataFlag(rpPRTADVEMITTERDATAFLAGPRTEMITTER) && !pResourceParticleSystem->m_strSubSystem.empty())
			{
				CNtlResourceComponentSystem* pResourceComponentSystem = GetResourceSystem(pResourceParticleSystem->m_strSubSystem.c_str());
				NTL_ASSERTE(pResourceComponentSystem->GetSystemType() == CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE);

				pResourceComponentSystem->m_bSubSystem = TRUE;
			}
		}
	}
}


//------------------------------------------------------------------
//	FuncName	: Load
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
RwBool CNtlResourceEffect::Load(FILE* pFile)
{
    if(!pFile)
        return FALSE;
       
	RwInt32 nSystemCount;
	fread(&nSystemCount,					sizeof(RwInt32),						1,			pFile);
	if (nSystemCount > 0)
	{
		RwChar strName[NTL_MAX_DIR_PATH];
		for (RwInt32 i = 0; i < nSystemCount; ++ i)
		{
            
			RwInt32 nSystemType;
			fread(&nSystemType,				sizeof(RwInt32),						1,			pFile);

			RwInt32 length;
			fread(&length,					sizeof(RwInt32),						1,			pFile);

			memset(strName, 0, NTL_MAX_DIR_PATH);
			fread(strName,					sizeof(RwChar),							length,		pFile);

			CNtlResourceComponentSystem* pResourceSystem = CNtlResourceEffect::CreateResourceSystem(nSystemType, strName);
            
            if(pResourceSystem->Load(pFile))
            {
                m_svResourceSystem.push_back(pResourceSystem);
            }
            else
            {
                NTL_DELETE(pResourceSystem);
            }
		}
	}

    // Sound 
	if (CNtlResourceEffect::m_nVersion >= 0x00000018)
	{

		fread(&m_EffectSound, sizeof(SEffectSoundEx), 1, pFile);

		DWORD* someByte = nullptr;
		fread(someByte, sizeof(DWORD), 1, pFile);

	}
	else
	{
		if (CNtlResourceEffect::m_nVersion >= 0x00000014)
		{
			fread(&m_EffectSound, sizeof(SEffectSoundEx), 1, pFile);
		}
		else
		{
			fread(&m_EffectSound, sizeof(SEffectSound), 1, pFile);
		}
		
	}
    fread(&m_EffectBoundingSphere, sizeof(m_EffectBoundingSphere), 1, pFile);
    

	return TRUE;
}

RwBool CNtlResourceEffect::IsAutoDelete() 
{
    for each(CNtlResourceComponentSystem* pSystem in m_svResourceSystem)
    {
        // 하나라도 루프라면 이펙트 전체가 루프 이펙트이다.
        if(pSystem && pSystem->m_bEternity)
        {
            return FALSE;
        }
    }

    return TRUE;
}