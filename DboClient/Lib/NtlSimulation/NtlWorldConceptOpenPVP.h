#pragma once

#include "NtlWorldConceptController.h"

class CNtlPLCharacter;
class CNtlPLEntity;

/**
 * \ingroup NtlSimulation
 * \brief PVP�� �Ҷ��� ���� Ŭ���� 
 * \date 2007-06-14
 * \author agebreak
 */
typedef std::map<RwUInt32, RwUInt32>				MAP_OPENBATTLE;		// first SerialID
typedef std::map<RwUInt32, RwUInt32>::iterator		MAP_OPENBATTLE_ITER;

class CNtlWorldConceptOpenPVP : public CNtlWorldConceptController
{
public:
	CNtlWorldConceptOpenPVP(void);
	~CNtlWorldConceptOpenPVP(void);

	virtual void	Update(RwReal fElapsedTime);	
	virtual void	ChangeState(RwInt32 iState);

	RwBool IsAttackableEnemy(RwUInt32 uiHandle);

	CNtlSobActor * GetNearAttackableEnemy(CNtlSobActor * pActor);
	void			EventHandler_BattleStart(void * pData);
	void			EventHandler_BattleEnd(void * pData);
	MAP_OPENBATTLE*		GetBattlers(VOID) { return &m_mapMembers; }

	//---- PVP ���� �޼ҵ�
	void				SetFreePvPTarget(SERIAL_HANDLE hTarget);					///< PVP Ÿ���� �����Ѵ�.
	SERIAL_HANDLE		GetFreePvPTarget(void) const;								///< ���� ������ PVP Target�� Serail ID�� ��ȯ�Ѵ�.

	void				SetFreePvPReferPos(RwV3d vPos);
	RwV3d				GetFreePvPReferPos(void) const;

	void				CreateFreePvPMark(void);							///< PVP ��ũ(����� ����)�� �����Ѵ�.
	void				DestroyFreePvPMark(void);							///< PVP ��ũ�� �����Ѵ�.

protected:
	/// PVP ���� ���� ����ü
	struct FreeBattleInfo
	{
		CNtlPLCharacter		*pCharacter;
        CNtlPLEntity*       pBoundEffect;
		SERIAL_HANDLE		hFreePvPTarget;
		RwV3d				vFreePvPPos;
	};

protected:
	FreeBattleInfo		m_FreeBattleInfo;		///< PVP ���� ����ü
	MAP_OPENBATTLE		m_mapMembers;

};


// �ζ��� �Լ���

inline void	CNtlWorldConceptOpenPVP::SetFreePvPTarget(SERIAL_HANDLE hTarget)
{
	m_FreeBattleInfo.hFreePvPTarget = hTarget;
}

inline SERIAL_HANDLE CNtlWorldConceptOpenPVP::GetFreePvPTarget(void) const
{
	return m_FreeBattleInfo.hFreePvPTarget;
}

inline void	CNtlWorldConceptOpenPVP::SetFreePvPReferPos(RwV3d vPos)
{
	m_FreeBattleInfo.vFreePvPPos = vPos;
}

inline RwV3d CNtlWorldConceptOpenPVP::GetFreePvPReferPos(void) const
{
	return m_FreeBattleInfo.vFreePvPPos;
}