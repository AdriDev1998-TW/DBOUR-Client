#ifndef _DBO_TSACTOUTMSG_H_
#define _DBO_TSACTOUTMSG_H_


#include "DboTSCoreDefine.h"


/**
	Direction action
	�뵵 : Client quest, client trigger, Server quest, server trigger pc
	���� : ������ Ŭ���̾�Ʈ���� ���� ���·� �ٲٶ�� �޽����� �����ش�.
		   Ŭ���̾�Ʈ, ������ TS���� m_tcJump�� ���� ó���� ���ش�
*/


class CDboTSActOutMsg : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

		// Member variables
protected:
	unsigned int						m_uiTblidx;
	unsigned int						m_uiActionId;

	// Constructions
public:
	CDboTSActOutMsg(void);

	// Methods
public:
	virtual unsigned int				GetEntityType(void) const { return DBO_ACT_ID_ACT_OUT_MSG; }

	// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript(const CNtlTSScrProperty& clProperty);
	virtual	void						TakeScriptDataForScript(CNtlTSScrProperty& clProperty);
};


#endif