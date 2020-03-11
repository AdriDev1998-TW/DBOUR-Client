#pragma once

#include "NtlPacketCommon.h"
#include "NtlCharacter.h"
#include "NtlDragonBall.h"
#include "NtlRankBattle.h"
#include "NtlMail.h"
#include "NtlAdmin.h"
#include "NtlTimeQuest.h"
#include "NtlTeleport.h"
#include "NtlBudokai.h"
#include "NtlMatch.h"
#include "NtlPetition.h"
#include "NtlDojo.h"
#include "NtlHlsItem.h"

enum eOPCODE_QG
{
	QG_OPCODE_BEGIN = 39000,

	QG_LOAD_PC_DATA_RES = QG_OPCODE_BEGIN,
	QG_ITEM_CREATE_RES,
	QG_ITEM_MOVE_RES,
	QG_ITEM_MOVE_STACK_RES,
	QG_ITEM_UPDATE_RES,
	QG_ITEM_DELETE_RES,
	QG_ITEM_EQUIP_REPAIR_RES,
	QG_ITEM_REPAIR_RES,
	QG_ITEM_DUR_UPDATE_RES,
	QG_ITEM_USE_RES,
	QG_ITEM_UPGRADE_RES,
	QG_ITEM_IDENTIFY_RES,
	QG_ITEM_CREATE_EX_RES,						// ������ ���� Ȯ����(������ ���� ����)
	QG_ITEM_DELETE_EX_RES,						// ������ ���� Ȯ����(������ ���� ����)
	QG_ITEM_AUTO_EQUIP_RES,						// ������ �ڵ� ����(Quest���� ���)
	QG_ITEM_AUTO_EQUIP_ROLLBACK_RES,			// ������ �ڵ� ���� RollBack(Quest���� ���)

	QG_ITEM_PICK_RES,
	QG_ZENNY_PICK_RES,

	QG_SKILL_RP_BONUS_SETTING_RES,
	QG_SKILL_LOAD_RES,
	QG_BUFF_LOAD_RES,
	QG_HTB_SKILL_LOAD_RES,
	
	QG_LOAD_PC_BANK_DATA_RES,
	QG_BANK_MOVE_RES,
	QG_BANK_MOVE_STACK_RES,
	QG_BANK_ZENNY_RES,
	QG_BANK_BUY_RES,
	QG_BANK_ITEM_DELETE_RES,

	QG_PC_UPDATE_POSITION_RES,
	QG_PC_UPDATE_EXP_RES,
	QG_PC_UPDATE_LPEPRP_RES,
	QG_PC_UPDATE_LEVEL_RES,
	QG_SAVE_PC_DATA_RES,
	QG_SAVE_SKILL_DATA_RES,
	QG_SAVE_HTB_DATA_RES,
	QG_SAVE_BUFF_DATA_RES,

	QG_PC_EXIT_RES,
	//QG_MAKE_AUTH_KEY_RES,

	QG_SHOP_BUY_RES,
	QG_SHOP_SELL_RES,	

	QG_PARTY_ACTIVATE_CHARM_RES,
	QG_PARTY_LOOTING_ITEM_RES,
	QG_PARTY_LOOTING_ZENNY_RES,

	QG_PC_UPDATE_BIND_RES,
	QG_CHAR_CONVERT_CLASS_RES,
	QG_CHAR_PUNISH_RES,						// PUNISH CHARACTER
	QG_CHAR_AWAY_RES,
	QG_CHAR_KEY_UPDATE_RES,

	QG_UPDATE_CHAR_ZENNY_RES,

	QG_QUEST_ITEM_CREATE_RES,					// ����Ʈ ������ ����
	QG_QUEST_ITEM_DELETE_RES,					// ����Ʈ ������ ����
	QG_QUEST_ITEM_MOVE_RES,					// ����Ʈ ������ �̵�
	QG_QUEST_PROGRESS_DATA_CREATE_RES,			// ����Ʈ ���� ���� ����
	QG_QUEST_PROGRESS_DATA_DELETE_RES,			// ����Ʈ ���� ���� ����
	QG_QUEST_COMPLETE_DATA_UPDATE_RES,			// ����Ʈ �Ϸ� ���� ������Ʈ
	QG_QUEST_DATA_RESET_RES,					// ����Ʈ ������ ������ ������ŭ �����Ѵ�.
	QG_QUEST_STATE_UPDATE_RES,					// ������ ����
	QG_QUEST_TSP_UPDATE_RES,					// TS �������� ����
	QG_QUEST_EXCEPTION_TIMER_UPDATE_RES,		// ���� Ÿ�̸��� ��� �� ����-> ��� �� ����??
	QG_QUEST_SSM_UPDATE_RES,					// �޸� ������ ������Ʈ
	QG_QUEST_SERVER_EVENT_UPDATE_RES,			// ���� �̺�Ʈ �������� ������Ʈ
	QG_QUEST_EXC_CLIENT_GROUP_RES,				// Ŭ���̾�Ʈ ���� �׷� ���̵�
	QG_QUEST_INFO_UPDATE_RES,					// ����Ʈ ���� ��� �������� ������Ʈ
	//------------------------------------------------------------------

	QG_QUICK_SLOT_UPDATE_RES,
	QG_QUICK_SLOT_DEL_RES,

	QG_SAVE_SPAWNED_SUMMON_PET_DATA_RES,		// ��ȯ�Ǿ� �ִ� summon pet�� ����
	QG_SAVE_SPAWNED_ITEM_PET_DATA_RES,			// ��ȯ�Ǿ� �ִ� item pet�� ����
	QG_LOAD_SUMMON_PET_DATA_RES,				// ��ȯ�� summon pet ����
	QG_LOAD_ITEM_PET_DATA_RES,					// ��ȯ�� item pet ����
	QG_LOAD_PET_BUFF_RES,						// ��ȯ�� pet�� ������ �ִ� buff ����
	QG_DELETE_ALL_TEMPORARY_PET_DATA_RES,		// �ӽ÷� ����� �� ������ ����

	QG_TRADE_RES,
	
	QG_SCHEDULE_INFO,
	QG_TUTORIAL_HINT_UPDATE_RES,
	QG_BALL_ITEM_PICK_RES,
	QG_BALL_ITEM_PARTY_PICK_RES,
	QG_BALL_ITEM_REWARD_RES,

	QG_PRIVATESHOP_ITEM_BUYING_RES,				
	QG_PRIVATESHOP_ITEM_INSERT_RES, 			
	QG_PRIVATESHOP_ITEM_DELETE_RES, 			
	QG_PRIVATESHOP_ITEM_UPDATE_RES, 			
	QG_PRIVATESHOP_SHOP_LOADING_RES,			
	QG_PRIVATESHOP_ITEM_DATA_INFO,				
	QG_PRIVATESHOP_CREATE_RES,					
	QG_PRIVATESHOP_UPDATE_RES,					

	QG_RANKBATTLE_SCORE_UPDATE_RES,

	QG_TMQ_DAYRECORD_RESET_RES,			// DayRecord ���� ��û ����
	QG_TMQ_DAYRECORD_UPDATE_RES,		// DayRecord ��� ��û ����
	QG_TMQ_DAYRECORD_LIST_RES,			// DayRecord ����Ʈ ��û(�Խ���) ����
	QG_TMQ_DAYRECORD_RES,				// DayRecord ����

	QG_MAIL_START_RES,
	QG_MAIL_SEND_RES,
	QG_MAIL_READ_RES,
	QG_MAIL_DEL_RES,
	QG_MAIL_RETURN_RES,
	QG_MAIL_RELOAD_RES,
	QG_MAIL_LOAD_RES,
	QG_MAIL_ITEM_RECEIVE_RES,
	QG_MAIL_LOCK_RES,
	QG_MAIL_EVENT_SEND_RES,
	QG_MAIL_MULTI_DEL_RES,

	QG_PORTAL_START_RES,
	QG_PORTAL_ADD_RES,

	QG_WAR_FOG_UPDATE_RES,	

	QG_ITEM_UPGRADE_ALL_RES,

	QG_GUILD_BANK_LOAD_RES,
	QG_GUILD_BANK_MOVE_RES,
	QG_GUILD_BANK_MOVE_STACK_RES,
	QG_GUILD_BANK_ZENNY_RES,

	QG_SHOP_ITEM_IDENTIFY_RES,

	QG_BUDOKAI_DATA_RES,
	QG_BUDOKAI_INIT_DATA_NFY,
	QG_BUDOKAI_INIT_DATA_RES,
	QG_BUDOKAI_UPDATE_STATE_RES,
	QG_BUDOKAI_UPDATE_MATCH_STATE_RES,
	QG_BUDOKAI_UPDATE_CLEAR_RES,
	QG_RANKPOINT_RESET_RES,
	QG_RANKBATTLE_ALLOW_RES,

	QG_BUDOKAI_INDIVIDUAL_ALLOW_REGISTER_RES,
	QG_BUDOKAI_JOIN_INDIVIDUAL_RES,
	QG_BUDOKAI_LEAVE_INDIVIDUAL_RES,
	QG_BUDOKAI_INDIVIDUAL_SELECTION_RES,
	QG_BUDOKAI_INDIVIDUAL_LIST_START,
	QG_BUDOKAI_INDIVIDUAL_LIST_DATA,
	QG_BUDOKAI_INDIVIDUAL_LIST_END,
	QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_ENTRY_LIST_RES,	// ��ʸ�Ʈ ������ �߰�
	QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_START,		// ��ʸ�Ʈ ������ ����Ʈ ����
	QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_DATA,		// ��ʸ�Ʈ ������ ����Ʈ ����Ÿ
	QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_END,		// ��ʸ�Ʈ ������ ����Ʈ ��
	QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_MATCH_RESULT_RES,	// ��ʸ�Ʈ ��� ��� �߰�
	QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_MATCH_RESULT_RES,		// ��ʸ�Ʈ ��� ��� ����Ʈ ��û

	QG_BUDOKAI_TEAM_ALLOW_REGISTER_RES,
	QG_BUDOKAI_JOIN_TEAM_RES,
	QG_BUDOKAI_LEAVE_TEAM_RES,
	QG_BUDOKAI_LEAVE_TEAM_MEMBER_RES,
	QG_BUDOKAI_TEAM_SELECTION_RES,
	QG_BUDOKAI_TEAM_LIST_START,
	QG_BUDOKAI_TEAM_LIST_DATA,
	QG_BUDOKAI_TEAM_LIST_END,
	QG_BUDOKAI_TOURNAMENT_TEAM_ADD_ENTRY_LIST_RES,		// ��ʸ�Ʈ ������ �߰�
	QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_START,		// ��ʸ�Ʈ ������ ����Ʈ ����
	QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_DATA,			// ��ʸ�Ʈ ������ ����Ʈ ����Ÿ
	QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_END,			// ��ʸ�Ʈ ������ ����Ʈ ��
	QG_BUDOKAI_TOURNAMENT_TEAM_ADD_MATCH_RESULT_RES,	// ��ʸ�Ʈ ��� ��� �߰�
	QG_BUDOKAI_TOURNAMENT_TEAM_MATCH_RESULT_RES,		// ��ʸ�Ʈ ��� ��� ����Ʈ ��û

	QG_BUDOKAI_JOIN_INFO_RES,
	QG_BUDOKAI_JOIN_STATE_RES,
	QG_BUDOKAI_HISTORY_WRITE_RES,						// ������ season history ���� ����
	QG_BUDOKAI_HISTORY_WINNER_PLAYER_RES,				// �ش� season �� player info ����
	QG_BUDOKAI_JOIN_STATE_LIST_RES,						// ����Ʈ ��û ����
	QG_BUDOKAI_JOIN_STATE_LIST_DATA,					// ����Ʈ ������(������ŭ �ݺ�)
	QG_BUDOKAI_SET_OPEN_TIME_RES,						// Set Open Time

	QG_MATCH_REWARD_RES,				// ��� ����

	QG_SCOUTER_ITEM_SELL_RES,
	QG_SCOUTER_CHIP_REMOVE_ALL_RES,

	QG_SHOP_EVENTITEM_BUY_RES,

	QG_SHOP_GAMBLE_BUY_RES, 

	QG_BUDOKAI_UPDATE_MUDOSA_POINT_RES,
	
	QG_ITEM_REPLACE_RES,

	QG_UPDATE_MARKING_RES,

	QG_SKILL_ADD_RES,
	QG_SKILL_UPGRADE_RES,
	QG_HTB_SKILL_ADD_RES,
	QG_SKILL_BUY_RES,
	
	QG_SKILL_INIT_RES,

	QG_RECIPE_REG_RES,
	QG_HOIPOIMIX_JOB_SET_RES,
	QG_HOIPOIMIX_JOB_RESET_RES,
	QG_HOIPOIMIX_ITEM_MAKE_RES,

	QG_ITEM_STACK_UPDATE_RES,

	QG_DOJO_BANK_HISTORY_RES,
	QG_DOJO_BANK_ZENNY_UPDATE_RES,
	QG_WORLD_SCHEDULE_SET_RES,

	QG_SWITCH_CHILD_ADULT_RES,
	QG_SET_CHANGE_CLASS_AUTHORITY_RES,

	QG_ITEM_CHANGE_ATTRIBUTE_RES,

	QG_CHANGE_NETP_RES,

	QG_ITEM_CHANGE_DURATIONTIME_RES,

	QG_SHOP_NETPYITEM_BUY_RES,

	QG_DURATION_ITEM_BUY_RES,
	QG_DURATION_RENEW_RES,

	QG_GM_COMMAND_LOG_RES,

	QG_CASHITEM_INFO_RES,
	QG_CASHITEM_MOVE_RES,
	QG_CASHITEM_DEL_RES,
	QG_CASHITEM_UNPACK_RES,
	QG_CASHITEM_BUY_RES,

	QG_GMT_UPDATE_RES,

	QG_PC_DATA_LOAD_RES,
	QG_PC_ITEM_LOAD_RES,
	QG_PC_SKILL_LOAD_RES,		
	QG_PC_BUFF_LOAD_RES,
	QG_PC_HTB_LOAD_RES,
	QG_PC_QUEST_ITEM_LOAD_RES,		
	QG_PC_QUEST_COMPLETE_LOAD_RES,
	QG_PC_QUEST_PROGRESS_LOAD_RES,	
	QG_PC_QUICK_SLOT_LOAD_RES,	
	QG_PC_SHORTCUT_LOAD_RES,
	QG_PC_ITEM_RECIPE_LOAD_RES,
	QG_PC_GMT_LOAD_RES,

	QG_OPCCODE_END_DUMMY,
	QG_OPCODE_END = QG_OPCCODE_END_DUMMY - 1
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * NtlGetPacketName_QG(WORD wOpCode);
//------------------------------------------------------------------


#pragma pack(push, 1)

//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_LOAD_PC_DATA_RES)

	WORD				wResultCode;

	ACCOUNTID			accountID;
	CHARACTERID			charID;
	DWORD				dwConnectingUserKey;
	WCHAR				awchUserID[NTL_MAX_SIZE_USERID_UNICODE + 1];
	sPC_DATA				sPcData;
	sDBO_SERVER_CHANGE_INFO		serverChangeInfo;
	sQUEST_COMPLETE_DATA	sQuestCompleteData;	// ����Ʈ �Ϸ� ����		[11/14/2006 niam]

	sRANKBATTLE_SCORE_INFO	sRankBattleScore;		// ��ũ ��Ʋ ���ھ� ���� [07/07/12 john]	

	bool				bTutorialFlag;

	//  [11/1/2006 zeroera] : ���� : ��������ϹǷ� ���Ƿ� ����Ÿ ������ �ٲ��� ������!!
	BYTE				byItemCount;
	BYTE				bySkillCount;
	BYTE				byBuffCount;
	BYTE				byHTBSkillCount;
	BYTE				byQuestProgressCount;	// ����Ʈ ���� ����		[11/14/2006 niam]
	BYTE				byQuestInventoryCount;		// ����Ʈ ������ ����	[11/14/2006 niam]
	BYTE				byQuickSlotCount;
	BYTE				byPunishCount;
	sMAIL_NEW_BREIF		sMailBrief;
	BYTE				byShortcutCount;
	BYTE				byRecipeCount;

	sCHAR_WAR_FOG_FLAG	sWarFogInfo;
	PETITIONID			petitionID;
	PETITIONCATEGORY	nPetitionCategory1;//ePETITIONSYSTEM_CATEGORY_1
	PETITIONCATEGORY	nPetitionCategory2;//ePETITIONSYSTEM_CATEGORY_2
	WCHAR				awchPetitionContent[NTL_MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];

	BYTE					byGMTResetCount;
	sGAME_MANIA_TIME_DATA	sGMT_Current;
	sGAME_MANIA_TIME_DATA	sGMT_Next;

#if 0
	sITEM_DATA				asItemData[NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM];
	sSKILL_DATA				asSkill[NTL_MAX_PC_HAVE_SKILL];
	sBUFF_DATA				asBuff[NTL_MAX_BLESS_BUFF_CHARACTER_HAS + NTL_MAX_CURSE_BUFF_CHARACTER_HAS];
	sHTB_SKILL_DATA			asHTBSkill[NTL_HTB_MAX_PC_HAVE_HTB_SKILL];
	sQUEST_PROGRESS_DATA	asQuestProgress[eMAX_CAN_PROGRESS_QUEST_NUM];
	sQUEST_INVENTORY_DATA	asQuestInventory[NTL_QUEST_INVENTORY_SLOT_COUNT];
	sQUICK_SLOT_DATA		asQuickSlotData[NTL_CHAR_QUICK_SLOT_MAX_COUNT];
	sPUNISH_DATA			asPunishData[GM_PUNISH_PASSIVE_TYPE_COUNT];
	sSHORTCUT_DATA			asShortcutData[NTL_SHORTCUT_MAX_COUNT];
	sRECIPE_DATA			asRecipeData[NTL_ITEM_RECIPE_MAX_COUNT];

	sITEM_DATA *			GetItemDataPtr(int nCount = 0) { return &asItemData[nCount]; }
	sSKILL_DATA *			GetSkillDataPtr(int nCount = 0) { return &asSkill[nCount]; }
	sBUFF_DATA *			GetBuffDataPtr(int nCount = 0) { return &asBuff[nCount]; }
	sHTB_SKILL_DATA *		GetHTBSkillDataPtr(int nCount = 0) { return &asHTBSkill[nCount]; }
	sQUEST_PROGRESS_DATA *	GetQuestProgressDataPtr(int nCount = 0) { return &asQuestProgress[nCount]; }
	sQUEST_INVENTORY_DATA *	GetQuestInventoryDataPtr(int nCount = 0) { return &asQuestInventory[nCount]; }
	sQUICK_SLOT_DATA*		GetQuickSlotDataPtr(int nCount = 0) { return &asQuickSlotData[nCount]; }
	sPUNISH_DATA*			GetPunishDataPtr(int nCount = 0) { return &asPunishData[nCount]; }
	sSHORTCUT_DATA*			GetShortcutDataPtr(int nCount = 0) { return &asShortcutData[nCount]; }
	sRECIPE_DATA*			GetRecipeDataPtr(int nCount = 0) { return &asRecipeData[nCount]; }
#else
	sITEM_DATA				asItemData[1];
	sSKILL_DATA				asSkill[1];
	sBUFF_DATA				asBuff[1];
	sHTB_SKILL_DATA			asHTBSkill[1];
	sQUEST_PROGRESS_DATA	asQuestProgress[1];
	sQUEST_INVENTORY_DATA	asQuestInventory[1];
	sQUICK_SLOT_DATA		asQuickSlotData[1];
	sPUNISH_DATA			asPunishData[1];
	sSHORTCUT_DATA			asShortcutData[1];
	sRECIPE_DATA			asRecipeData[1];

	sITEM_DATA *			GetItemDataPtr(int nCount = 0) { return &asItemData[nCount]; }
	sSKILL_DATA *			GetSkillDataPtr(int nCount = 0) { return ( (sSKILL_DATA*) GetItemDataPtr(byItemCount) ) + nCount; }
	sBUFF_DATA *			GetBuffDataPtr(int nCount = 0) { return ( (sBUFF_DATA *) GetSkillDataPtr(bySkillCount) ) + nCount; }
	sHTB_SKILL_DATA *		GetHTBSkillDataPtr(int nCount = 0) { return ( (sHTB_SKILL_DATA *) GetBuffDataPtr(byBuffCount) ) + nCount; }
	sQUEST_PROGRESS_DATA *	GetQuestProgressDataPtr(int nCount = 0) { return ( (sQUEST_PROGRESS_DATA *) GetHTBSkillDataPtr(byHTBSkillCount) ) + nCount; }
	sQUEST_INVENTORY_DATA *	GetQuestInventoryDataPtr(int nCount = 0) { return ( (sQUEST_INVENTORY_DATA *) GetQuestProgressDataPtr(byQuestProgressCount) ) + nCount; }
	sQUICK_SLOT_DATA*		GetQuickSlotDataPtr(int nCount = 0) { return ( (sQUICK_SLOT_DATA *) GetQuestInventoryDataPtr(byQuestInventoryCount) )+ nCount; }
	sPUNISH_DATA*			GetPunishDataPtr(int nCount = 0) { return ( (sPUNISH_DATA *) GetQuickSlotDataPtr(byQuickSlotCount) ) + nCount; }
	sSHORTCUT_DATA*			GetShortcutDataPtr(int nCount = 0) { return ( (sSHORTCUT_DATA *) GetPunishDataPtr(byPunishCount) ) + nCount; }
	sRECIPE_DATA*			GetRecipeDataPtr(int nCount = 0) { return ( (sRECIPE_DATA *) GetShortcutDataPtr(byShortcutCount) ) + nCount; }
#endif

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_CREATE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	sITEM_DATA				sItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_MOVE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					hSrcItem;
	HOBJECT					hDstItem;
	BYTE					bySrcPlace;
	BYTE					bySrcPos;
	BYTE					byDstPlace;
	BYTE					byDstPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_MOVE_STACK_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					hSrcItem;
	HOBJECT					hDstItem;
	BYTE					bySrcPlace;
	BYTE					bySrcPos;
	BYTE					byDstPlace;
	BYTE					byDstPos;
	BYTE					byStackCount1;
	BYTE					byStackCount2;
	ITEMID					splitItemId;// Created Item ID
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_UPDATE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	sITEM_DATA				sItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_DELETE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	BYTE					byPlace;
	BYTE					byPos;
	HOBJECT					hItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_ITEM_EQUIP_REPAIR_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					npcHandle;
	DWORD					dwZenny;
	WORD					wResultCode;
	BYTE					byCount;
	sITEM_REPAIR			asItemData[EQUIP_SLOT_TYPE_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_ITEM_REPAIR_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					npcHandle;
	DWORD					dwZenny;
	WORD					wResultCode;
	sITEM_REPAIR			sItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_ITEM_DUR_UPDATE_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					itemhandle;
	BYTE					byDur;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_USE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	BYTE					byPlace;
	BYTE					byPos;
	HOBJECT					hItem;
	BYTE					byStack;
	DWORD					dwItemUseEventId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_UPGRADE_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	WORD					wResultCode;		// DB ���� ����
	BYTE					byStack;			// ���� ����� ���ð���					-> ����� ����
	BYTE					byGrade;			// ����� �׷��̵�						-> ����� �׷��̵�
	BYTE					byItemPlace;		// ���׷��̵� �� �������� �����̳� ��ġ 
	BYTE					byItemPos;			// ���׷��̵� �� �������� ��ġ
	BYTE					byStonPlace;		// ȣ�����̽��� �����̳� ��ġ
	BYTE					byStonPos;			// ȣ�����̽��� ��ġ
	bool					bType;				// true ���� false ���׷��̵�
	BYTE					byBattleAttribute;	// ������Ʈ �� �Ӽ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_IDENTIFY_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					itemhandle;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_CREATE_EX_RES)
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;	// ���� �ڵ�
	BYTE					byRequestType;	// ������ ���� Ÿ�� eITEM_CREATE_TYPE
	uITEM_CREATE_SUB_DATA	uSubData;		// �߰� ����
	BYTE					byUpdateCount;	// Stack ���氹��
	sITEM_BASIC_DATA		asUpdateData[ITEM_CREATE_EX_MAX_COUNT];
	BYTE					byItemCount;	// ������ ����
	sITEM_DATA				aItem[1];		// ������ ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_DELETE_EX_RES)
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;	// ���� �ڵ�
	BYTE					byRequestType;	// ������ ���� Ÿ�� eITEM_CREATE_TYPE
	uITEM_DELETE_SUB_DATA	uSubData;		// �߰� ����
	BYTE					byItemCount;	// ������ ����
	sITEM_DELETE_DATA		aItem[1];		// ������ ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_AUTO_EQUIP_RES)
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;
	sTSM_SERIAL				sTSMSerial;
	sITEM_AUTO_EQUIP_DATA	sItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_AUTO_EQUIP_ROLLBACK_RES)
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;
	sTSM_SERIAL				sTSMSerial;
	sITEM_AUTO_EQUIP_ROLLBACK_DATA	sItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_PICK_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					itemhandle;
	bool					bIsNew;
	WORD					wResultCode;
	sITEM_DATA				sItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ZENNY_PICK_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					itemhandle;
	WORD					wResultCode;
	DWORD					dwZenny;
	DWORD					dwOrgZenny;
	DWORD					dwBonusZenny;
END_PROTOCOL()
//---------------------------------------------------------------
BEGIN_PROTOCOL(QG_SKILL_RP_BONUS_SETTING_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	TBLIDX					skillId;
	BYTE					bySkillSlotIndex;
	BYTE					byRpBonusType;
	bool					bIsRpBonusAuto;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SKILL_LOAD_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	BYTE					byCount;
	sSKILL_DATA				sSkill[NTL_MAX_PC_HAVE_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUFF_LOAD_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	BYTE					byCount;
	sBUFF_DATA				sBuff[NTL_MAX_BLESS_BUFF_CHARACTER_HAS + NTL_MAX_CURSE_BUFF_CHARACTER_HAS];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_HTB_SKILL_LOAD_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	BYTE					byCount;
	sHTB_SKILL_DATA			asSkill[NTL_HTB_MAX_PC_HAVE_HTB_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_LOAD_PC_BANK_DATA_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					npchandle;
	DWORD					dwZenny;
	BYTE					byCount;
	sITEM_DATA				asItemData[NTL_MAX_COUNT_USER_HAVE_BANK_ITEM];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BANK_MOVE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					hSrcItem;
	HOBJECT					hDstItem;
	BYTE					bySrcPlace;
	BYTE					bySrcPos;
	BYTE					byDstPlace;
	BYTE					byDstPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BANK_MOVE_STACK_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					hSrcItem;
	HOBJECT					hDstItem;
	BYTE					bySrcPlace;
	BYTE					bySrcPos;
	BYTE					byDstPlace;
	BYTE					byDstPos;
	BYTE					byStackCount1;
	BYTE					byStackCount2;
	ITEMID					splitItemId;// Created Item ID
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BANK_ZENNY_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					npchandle;
	WORD					wResultCode;
	DWORD					dwZenny;
	bool					bIsSave;		// 1: ���� 0: ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BANK_BUY_RES)
	HOBJECT					handle;
	HOBJECT					npchandle;
	WORD					wResultCode;
	BYTE					byMerchantTab;
	BYTE					byMerchantPos;
	DWORD					dwZenny;
	TBLIDX					itemNo;					// Template Number
	CHARACTERID				charId;					// Owner Serial
	BYTE					byPlace;				// eCONTAINER_TYPE
	BYTE					byPosition;	
	BYTE					byRank;					// 0 1 2 3 //â�������� ������
	ITEMID					itemID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BANK_ITEM_DELETE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	BYTE					byPlace;
	BYTE					byPos;
	HOBJECT					hItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_UPDATE_POSITION_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	float					fPositionX;
	float					fPositionY;
	float					fPositionZ;
	float					fDirX;
	float					fDirZ;
	TBLIDX					worldTblidx;
	WORLDID					worldId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_UPDATE_EXP_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	DWORD					dwEXP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_UPDATE_LPEPRP_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	WORD					wLP;
	WORD					wEP;
	WORD					wRP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_UPDATE_LEVEL_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	BYTE					byLevel;
	DWORD					dwEXP;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SAVE_PC_DATA_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SAVE_SKILL_DATA_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SAVE_HTB_DATA_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SAVE_BUFF_DATA_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_EXIT_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	eCHARLEAVING_TYPE		eCharLeavingType;
END_PROTOCOL()
//------------------------------------------------------------------
/*BEGIN_PROTOCOL(QG_MAKE_AUTH_KEY_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	ACCOUNTID				accountId;
	CHARACTERID				charId;
END_PROTOCOL()*/
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SHOP_BUY_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	HOBJECT					hNpchandle;
	CHARACTERID				charId;
	DWORD					dwMoney;
	BYTE					byBuyCount;
	ITEMID					itemID[NTL_MAX_BUY_SHOPPING_CART];
	sSHOP_BUY_INVEN			sInven[NTL_MAX_BUY_SHOPPING_CART];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SHOP_SELL_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	HOBJECT					hNpchandle;
	DWORD					dwMoney;
	CHARACTERID				charId;
	BYTE					bySellCount;
	sSHOP_SELL_INVEN		sInven[NTL_MAX_SELL_SHOPPING_CART];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PARTY_ACTIVATE_CHARM_RES)
	WORD					wResultCode;
	PARTYID					partyId;
	TBLIDX					charmItemTblidx;		// Table Index in ItemTable
	bool					bIsSuccess;				// Dice Success �ΰ�?
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PARTY_LOOTING_ITEM_RES)
	WORD			wResultCode;
	// The item owner can be found out with using 'sItemData.charId'.
	// �������� ���� �÷��̾�� 'sItemData.charId'�� �˾Ƴ� �� �ִ�.
	// by YOSHIKI(2007-03-09)
	HOBJECT			hItem;
	bool			bNeedNewSlot;
	sITEM_DATA		itemData;
	bool			bByAutoDistribution;

	// For Game Log
	ACCOUNTID							winnerAccountId;
	PARTYID								partyId;
	sDBO_ZENNY_DATA		aZennyData[NTL_MAX_MEMBER_IN_PARTY];
	bool				bIsPartyInven;
	BYTE				byItemSlot;
	BYTE				byMemberIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PARTY_LOOTING_ZENNY_RES)
	WORD				wResultCode;
	CHARACTERID			looterCharId;
	HOBJECT				hDroppedZenny;
	DWORD				dwTotalZenny;
	bool				bIsShared;
	BYTE				byMemberCount;
	sZENNY_INFO			aZennyInfo[NTL_MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_UPDATE_BIND_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	float					fBindX;
	float					fBindY;
	float					fBindZ;
	float					fBindDirX;
	float					fBindDirZ;
	WORLDID					worldId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CHAR_CONVERT_CLASS_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	BYTE					byClass;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CHAR_PUNISH_RES )
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	CHARACTERID				targetCharID;
	BYTE					byPunishType;		// Punish Type
	DWORD					dwPunishAmount;		// How Many Day or Minutes
	bool					bDateOption;		// 0: Day 1: Minutes 
	bool					bIsOn;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CHAR_AWAY_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	bool					bIsAway;		// On 1: Off: 0
	WORD 					wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CHAR_KEY_UPDATE_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	WORD 					wResultCode;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_UPDATE_CHAR_ZENNY_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	DWORD					dwZenny;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_ITEM_CREATE_RES )
	HOBJECT						handle;
	DWORD						dwTimeStamp;
	CHARACTERID					charId;
	WORD						wResultCode;
	BYTE						byRequestType;	// sub data : Create Type [eQUEST_ITEM_REQUEST_TYPE]
	uQUEST_ITEM_UPDATE_SUB_DATA	uSubData;		// sub data;
	BYTE						byItemCount;
	sQUEST_ITEM_UPDATE_DATA		aItems[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_ITEM_DELETE_RES )
	HOBJECT						handle;
	DWORD						dwTimeStamp;
	CHARACTERID					charId;
	WORD						wResultCode;
	BYTE						byRequestType;	// sub data : Create Type [eQUEST_ITEM_REQUEST_TYPE]
	uQUEST_ITEM_UPDATE_SUB_DATA	uSubData;		// sub data;
	BYTE						byItemCount;
	sQUEST_ITEM_UPDATE_DATA		aItems[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_ITEM_MOVE_RES )
	HOBJECT						handle;
	DWORD						dwTimeStamp;
	CHARACTERID					charId;
	WORD						wResultCode;
	TBLIDX						dwSrcTblidx;
	BYTE						bySrcPos;
	TBLIDX						dwDestTblidx;
	BYTE						byDestPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_PROGRESS_DATA_CREATE_RES )
	HOBJECT					handle;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	WORD					wResultCode;
	sQUEST_PROGRESS_DATA	progressInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_PROGRESS_DATA_DELETE_RES )
	HOBJECT					handle;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	WORD					wResultCode;
	QUESTID					questID; // ����Ʈ ���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_COMPLETE_DATA_UPDATE_RES )
	HOBJECT					handle;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	WORD					wResultCode;
	BYTE						byPos;
	sCOMPLETE_QUEST_BIT_INFO	sData;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_DATA_RESET_RES )
	HOBJECT					handle;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	WORD					wResultCode;
	bool					bCompleteQuestData;	// �Ϸ� ���� ���� ����
	bool					bProgressQuestData;	// ���� ���� ���� ����
	QUESTID					startResetQID;		// ���� ����
	QUESTID					endResetQID;		// ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_STATE_UPDATE_RES )			// ������ ����
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	WORD					wTSState;				// ���� �� ���� ��
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_TSP_UPDATE_RES )			// TS �������� ����
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	sMAIN_TSP				sMainTSP;				// TS ������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_EXCEPTION_TIMER_UPDATE_RES )// ���� Ÿ�̸��� ������Ʈ
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	sEXCEPT_TIMER_SLOT		sExceptTimerSlot;			// ���� Ÿ�̸� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_SSM_UPDATE_RES )			// �޸� ������ ������Ʈ
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	BYTE					byIdx;
	DWORD					dwValue;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_SERVER_EVENT_UPDATE_RES )	// ���� �̺�Ʈ �������� ������Ʈ
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	BYTE					bySvrEvtType;			// Server Event Type
	sSTOC_EVT_DB_DATA		sSvrEvt;				// Server Event Data
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_EXC_CLIENT_GROUP_RES )// ���� �̵� �������� ������Ʈ
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	NTL_TS_TG_ID			tgExcCGroup;			// Ŭ���̾�Ʈ ���� �׷���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUEST_INFO_UPDATE_RES )			// ����Ʈ ���� ��� �������� ������Ʈ
	HOBJECT					handle;
	WORD					wResultCode;
	DWORD					dwTimeStamp;
	CHARACTERID				charId;
	QUESTID					qId;					// Trigger ID(Quest ID)
	NTL_TS_TC_ID			tcId;					// Trigger Container ID
	NTL_TS_TA_ID			taId;					// Trigger Action ID
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUICK_SLOT_UPDATE_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	WORD					wResultCode;
	TBLIDX					tblidx;		
	BYTE					bySlotID;				// QuickSlot ���̵�
	BYTE					byType;					// �������ΰ� ��ų�ΰ� �ҼȾ׼��ΰ�?
	BYTE					byPlace;
	BYTE					byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_QUICK_SLOT_DEL_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	WORD					wResultCode;
	BYTE					bySlotID;				// QuickSlot ���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_SAVE_SPAWNED_SUMMON_PET_DATA_RES )
	HOBJECT					handle;
	CHARACTERID				ownerCharId;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_SAVE_SPAWNED_ITEM_PET_DATA_RES )
	HOBJECT					handle;
	CHARACTERID				ownerCharId;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_LOAD_SUMMON_PET_DATA_RES )
	HOBJECT					handle;
	CHARACTERID				ownerCharId;
	sSUMMON_PET_DATA		petData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_LOAD_ITEM_PET_DATA_RES )
	HOBJECT					handle;
	CHARACTERID				ownerCharId;
	sITEM_PET_DATA			petData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_LOAD_PET_BUFF_RES )
	HOBJECT					handle;
	CHARACTERID				ownerCharId;
	BYTE					byCount;
	sPET_BUFF_DATA			aPetBuff[NTL_MAX_BLESS_BUFF_CHARACTER_HAS + NTL_MAX_CURSE_BUFF_CHARACTER_HAS];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_DELETE_ALL_TEMPORARY_PET_DATA_RES )
	HOBJECT					handle;
	CHARACTERID				ownerCharId;
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_TRADE_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	HOBJECT					hTarget;	
	CHARACTERID				charID;
	CHARACTERID				dstcharID;	// �Ű��� ĳ���� ���̵�
	BYTE					bySendCount;
	BYTE					byRecvCount;
	sTRADE_INVEN			asSendData[TRADE_INVEN_MAX_COUNT];
	sTRADE_INVEN			asRecvData[TRADE_INVEN_MAX_COUNT];
	DWORD					dwGiveZenny;	// �� ����
	DWORD					dwTakeZenny;	// ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_SCHEDULE_INFO )
	WORD					wResultCode;
	BYTE					byCount;
	sSCHEDULE_INFO			asInfo[SCHEDULE_EVENT_TYPE_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_TUTORIAL_HINT_UPDATE_RES )
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	DWORD					dwTutorialHint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_BALL_ITEM_PICK_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					itemhandle;
	WORD					wResultCode;
	sITEM_DATA				sItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_BALL_ITEM_PARTY_PICK_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					itemhandle;
	WORD					wResultCode;
	sITEM_DATA				sItemData;
	BYTE					byCount;
	CHARACTERID				aCharID[NTL_MAX_MEMBER_IN_PARTY];
	sEMPTY_INVEN			asEmpty[NTL_MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_BALL_ITEM_REWARD_RES )
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					hTarget; // TS Object
	WORD					wResultCode;
	sITEM_DELETE_DATA		asData[NTL_ITEM_MAX_DRAGONBALL];
	BYTE					byRewardType;		//eDRAGONBALL_REWARD_TYPE
	TBLIDX					skillId;	
	sITEM_DATA				sItemData;
	DWORD					dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_ITEM_BUYING_RES )
	HOBJECT						handle;
	HOBJECT						hTarget;
	WORD						wResultCode;
	CHARACTERID					charID_From;
	CHARACTERID					charID_To;
	DWORD						dwAllZenny;
	BYTE						byItemCount;
	sPRIVATESHOP_ITEM_POS_DATA	asPrivateShopItemPos[NTL_MAX_BUY_SHOPPING_CART];
	sINVEN_ITEM_POS_DATA		asEmpty[NTL_MAX_BUY_SHOPPING_CART];
	BYTE						byPrivateShopState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_ITEM_INSERT_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	sPRIVATESHOP_ITEM_POS_DATA	sPrivateShopEmpty;
	sINVEN_ITEM_POS_DATA		sInventoryItemPos;
	DWORD						dwZenny;		// ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_ITEM_DELETE_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	sPRIVATESHOP_ITEM_POS_DATA	sItemPos;
	sINVEN_ITEM_POS_DATA		sInventoryEmpty;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_ITEM_UPDATE_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	DWORD						dwAfterZenny;
	DWORD						dwBeforeZenny;
	BYTE						byFromPos;
	BYTE						byToPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_SHOP_LOADING_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	WCHAR						wcPrivateShopName[NTL_MAX_PRIVATESHOP_NAME_IN_UNICODE + 1];
	WCHAR						wcNotice[NTL_MAX_PRIVATESHOP_NOTICE_IN_UNICODE + 1];
	__int64						nCashShopStartTime; //���� ���� �� ��¥
	__int64						nCashShopEndTime;	//���� �� ������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_ITEM_DATA_INFO )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	sITEM_DATA					sItem;		//PRIVATESHOP_ITEM_DATA::IsSaveItem�� true�� ��� query���� ä���� game���� ������ �մϴ�
	DWORD						dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_CREATE_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	__int64						nCashShopStartTime; //���� ���� �� ��¥
	__int64						nCashShopEndTime;	//���� �� ������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PRIVATESHOP_UPDATE_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	WCHAR						wcPrivateShopName[NTL_MAX_PRIVATESHOP_NAME_IN_UNICODE + 1];
	WCHAR						wcNotice[NTL_MAX_PRIVATESHOP_NOTICE_IN_UNICODE + 1];
	bool						bIsOwnerEmpty;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_RANKBATTLE_SCORE_UPDATE_RES )
	HOBJECT						handle;
	WORD						wResultCode;
	CHARACTERID					charID;
	BYTE						byBattleMode;
	sRANKBATTLE_SCORE_INFO		sTotalScore;
	DWORD						dwMudosaPoint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_TMQ_DAYRECORD_RESET_RES )
	WORD						wResultCode;

	DWORD						dwDay;				// ����� (ex.20071116) �� ���� ���۵�
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;		// eTIMEQUEST_DIFFICULTY

	DWORD						dwClearTime;
	bool						bIsBestRecord;		// BestRecord ������ΰ�?
	WCHAR						wszPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE+1];
	BYTE						byCount;
	sTIMEQUEST_MEMBER_DATA		asMember[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_TMQ_DAYRECORD_UPDATE_RES )
	WORD						wResultCode;
	WORLDID						worldId;		// res ���� TMQ �� �� ���� �ϱ� ����
	TBLIDX						tmqTblidx;

	DWORD						dwDayRecordTime;// DayRecord �� ��� INVALID_DWORD
	bool						bIsBestRecord;	// best record �ΰ�?
	BYTE						byRank;			// ���� ��� x / 5
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_TMQ_DAYRECORD_LIST_RES )
	HOBJECT						handle;
	CHARACTERID					charId;
	WORD						wResultCode;
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
	BYTE						byTeamCount;
	sTIMEQUEST_TEAM_DATA		asTeam[DBO_TIMEQUEST_DEFAULT_DAYRECORD_RANK_COUNT];		// �뷮 ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_TMQ_DAYRECORD_RES )
	WORD						wResultCode;
	TBLIDX						tmqTblidx;
	ROOMID						roomId;
	DWORD						adwDayRecord[MAX_TIMEQUEST_DIFFICULTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_START_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	WORD 						wResultCode;	// ���
	bool						bIsAway;
	BYTE						byCount;
	sMAIL_DATA					asData[NTL_MAX_MAIL_SLOT_COUNT];		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_SEND_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	WCHAR						wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];	// ���� ĳ�� �̸�
	BYTE						byMailType;	// eMAIL_TYPE	
 	WORD						wResultCode;	// ��������
	sITEM_POSITION_DATA			sItemData;	// ����������
	DWORD						dwZenny;		// Req or Give Zenny
	CHARACTERID					targetCharID;
	MAILID						mailID;
	bool						bIsTemp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_READ_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	MAILID						mailID;	// ���� ���̵�
	WORD						wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
	BYTE						byRemainDay;
	DBOTIME						endTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_DEL_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	MAILID						mailID;	// ���� ���̵�
	WORD						wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_RETURN_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	MAILID						mailID;	// ���� ���̵�
	WORD						wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_RELOAD_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	WORD						wResultCode;	// ��������
	bool						bIsSchedule;	// �����ٿ� ���� ���ε� �ΰ� ���� ��û�ΰ�? 0:User 1:������
	BYTE						byCount;	// �������ī��Ʈ
	MAILID						asMailID[NTL_MAX_MAIL_SLOT_COUNT];
	sMAIL_BRIEF					asMailInfo[NTL_MAX_MAIL_SLOT_COUNT];	// ī��Ʈ�� �ش��ϴ� ����� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_LOAD_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	WORD						wResultCode;	// ��������
	BYTE						byCount;
	sMAIL_DATA					asData[NTL_MAX_MAIL_SLOT_COUNT];		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_ITEM_RECEIVE_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	WORD						wResultCode;	// ��������
	MAILID						mailID;	// ���� ���̵�	
	sITEM_DATA					sItemData;	// ���������� -> ��������� ���Ǿ� DB�� �� ����
	DWORD						dwZenny;		// Req or Give Zenny
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_LOCK_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	MAILID						mailID;	// ���� ���̵�	
	bool						bIsLock;		// Lock 1: Unlock: 0
	WORD 						wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ����
	BYTE						byExpiredDay;	// Unlock�� ���� ��¥ ���ſ� ���
	DBOTIME						endTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_EVENT_SEND_RES )
	CHARACTERID					charID;
	CHARACTERID					targetCharID;
	BYTE						byMailType;	// eMAIL_TYPE
	BYTE						bySenderType;	// eMAIL_SENDER_TYPE
 	WORD						wResultCode;	// ��������
	TBLIDX						itemTblidx;	// �������ε���
	DWORD						dwZenny;		// Req or Give Zenny
	MAILID						mailID;
	ITEMID						itemID;
	bool						bIsTemp;
	BYTE						byDay;		// ��ȿ���ᳯ¥ �ִ� 10��
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_MAIL_MULTI_DEL_RES )
	HOBJECT						handle;
	HOBJECT						hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	CHARACTERID					charID;
	WORD						wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
	BYTE						byCount;
	MAILID						aMailID[NTL_MAX_COUNT_OF_MULTI_DEL];	// ���� ���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PORTAL_START_RES )
	HOBJECT						handle;
	CHARACTERID					charID;
	HOBJECT						hNpcHandle;
	WORD 						wResultCode;
	BYTE						byCount;
	PORTALID					aPortalID[NTL_PORTAL_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_PORTAL_ADD_RES )
	HOBJECT						handle;
	CHARACTERID					charID;
	HOBJECT						hNpcHandle;
	WORD 						wResultCode;
	PORTALID					PortalID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_WAR_FOG_UPDATE_RES )
	HOBJECT						handle;
	CHARACTERID					charID;
	HOBJECT						hObject;
	WORD 						wResultCode;
	bool						bIsCheat;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_ITEM_UPGRADE_ALL_RES )
	HOBJECT						handle;
	CHARACTERID					charID;
	WORD 						wResultCode;
	BYTE						abyGrade[NTL_ITEM_UPGRADE_EQUIP_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_GUILD_BANK_LOAD_RES )
	HOBJECT						handle;
	CHARACTERID					charID;
	WORD 						wResultCode;
	GUILDID						guildID;
	HOBJECT						hNpcHandle;
	DWORD						dwZenny;
	BYTE						byCount;
	sITEM_DATA					asItemData[NTL_MAX_COUNT_GUILD_HAVE_TOTAL_ITEM];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_GUILD_BANK_MOVE_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					hSrcItem;
	HOBJECT					hDstItem;
	BYTE					bySrcPlace;
	BYTE					bySrcPos;
	BYTE					byDstPlace;
	BYTE					byDstPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_GUILD_BANK_MOVE_STACK_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	HOBJECT					hSrcItem;
	HOBJECT					hDstItem;
	BYTE					bySrcPlace;
	BYTE					bySrcPos;
	BYTE					byDstPlace;
	BYTE					byDstPos;
	BYTE					byStackCount1;
	BYTE					byStackCount2;
	ITEMID					splitItemId;// Created Item ID
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_GUILD_BANK_ZENNY_RES)
	HOBJECT					handle;
	CHARACTERID				charID;
	HOBJECT					npchandle;
	WORD					wResultCode;
	DWORD					dwZenny;
	bool					bIsSave;		// 1: ���� 0: ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SHOP_ITEM_IDENTIFY_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	ITEMID					itemID; 
	HOBJECT					hNpchandle; 
	BYTE					byPlace; 
	BYTE					byPos; 
	DWORD					dwZenny;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_DATA_RES)
	WORD							wResultCode;		// DB Data�� �������� ���� ��쿡�� GAME_SUCCESS�� �����ش�.
	bool							bIsExistData;		// Db Data�� �����ϴ°�?
	sBUDOKAI_UPDATEDB_INITIALIZE	sBudokaiData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INIT_DATA_NFY)
	WORD					wSeasonCount;				// ��ȸ������.
	BYTE					byBudokaiStep;				// ���� ���� �ܰ�, eBUDOKAI_STEP_TYPE
	__int64					nDefaultOpenTime;			// �⺻ ���۽ð�
	__int64					nNextStepTime;				// ���� �ܰ��� ���� �ð�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INIT_DATA_RES)
	WORD							wResultCode;
	bool							bIsFirstUpdate;		// true : ������ ó�� �����Ͽ� DB�� ����Ÿ�� ���� ���, false : ���ο� ������ �����ϰԵ� ���
	sBUDOKAI_UPDATEDB_INITIALIZE	sInitData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_UPDATE_STATE_RES)
	WORD							wResultCode;
	sBUDOKAI_STATE_DATA				sStateData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_UPDATE_MATCH_STATE_RES)
	WORD							wResultCode;
	BYTE							byMatchType;		// eBUDOKAI_MATCH_TYPE
	sBUDOKAI_MATCHSTATE_DATA		sStateData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_UPDATE_CLEAR_RES)
	WORD							wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_RANKPOINT_RESET_RES)
	WORD							wResultCode;

	BYTE							byMinLevel;
	BYTE							byMaxLevel;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_RANKBATTLE_ALLOW_RES)
	WORD							wResultCode;

	bool							bAllow;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INDIVIDUAL_ALLOW_REGISTER_RES)
	WORD							wResultCode;
	bool							bAllow;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_JOIN_INDIVIDUAL_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	float					fPoint;
	WORD					wJoinId;
	bool					bDojoRecommender;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_LEAVE_INDIVIDUAL_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INDIVIDUAL_SELECTION_RES)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INDIVIDUAL_LIST_START)
	WORD					wResultCode;
	WORD					wIndividualAllCount;	// ��ü ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INDIVIDUAL_LIST_DATA)
	WORD								wResultCode;
	WORD								wDataCount;		//
	sBUDOKAI_REGISTER_INDIVIDUAL_DATA	aData[BUDOKAI_MAX_INDIVIDUAL_DB_DATA_PACKET_COUNT];			// max = BUDOKAI_MAX_INDIVIDUAL_DB_DATA_PACKET_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_INDIVIDUAL_LIST_END)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_ENTRY_LIST_RES)
	WORD					wResultCode;
	WORD					wJoinId;
	BYTE					byMatchIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_START)
	WORD					wResultCode;
	BYTE					byMaxCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_DATA)
	WORD										wResultCode;
	BYTE										byCount;
	sBUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_DATA	aEntryData[BUDOKAI_MAX_TOURNAMENT_INDIVIDUAL_ENTRY_PACKET_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_END)
	WORD							wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_MATCH_RESULT_RES)
	WORD							wResultCode;
	sBUDOKAI_TOURNAMENT_MATCH_DATA	sMatchData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_MATCH_RESULT_RES)
	WORD							wResultCode;
	BYTE							byMatchDataCount;
	sBUDOKAI_TOURNAMENT_MATCH_DATA	aMatchData[BUDOKAI_MAX_TOURNAMENT_INDIVIDUAL_MATCH_RECORD_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TEAM_ALLOW_REGISTER_RES)
	WORD							wResultCode;
	bool							bAllow;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_JOIN_TEAM_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	WCHAR					wszTeamName[NTL_MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];
	BYTE					byMemberCount;
	CHARACTERID				aMembers[NTL_MAX_MEMBER_IN_PARTY];
	float					fPoint;
	WORD					wJoinId;

	sBUDOKAI_TEAM_POINT_INFO	aTeamInfo[NTL_MAX_MEMBER_IN_PARTY];		// game server ���� ����ϴµ����� by niam
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_LEAVE_TEAM_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	BYTE					byMemberCount;
	CHARACTERID				aMembers[NTL_MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_LEAVE_TEAM_MEMBER_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	CHARACTERID				aMembers[NTL_MAX_MEMBER_IN_PARTY];
	WCHAR					wszMemberName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TEAM_SELECTION_RES)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TEAM_LIST_START)
	WORD					wResultCode;
	WORD					wTeamAllCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TEAM_LIST_DATA)
	WORD						wResultCode;
	WORD						wDataCount;
	sBUDOKAI_REGISTER_TEAM_DATA	aData[BUDOKAI_MAX_TEAM_DB_DATA_PACKET_COUNT];			// max = BUDOKAI_MAX_TEAM_DB_DATA_PACKET_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TEAM_LIST_END)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_TEAM_ADD_ENTRY_LIST_RES)
	WORD					wResultCode;
	WORD					wJoinId;
	BYTE					byMatchIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_START)
	WORD							wResultCode;
	BYTE							byMaxCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_DATA)
	WORD								wResultCode;
	BYTE								byMemberCount;
	sBUDOKAI_TOURNAMENT_TEAM_ENTRY_DATA	aEntryData[BUDOKAI_MAX_TOURNAMENT_TEAM_ENTRY_PACKET_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_END)
	WORD							wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_TEAM_ADD_MATCH_RESULT_RES)
	WORD							wResultCode;
	sBUDOKAI_TOURNAMENT_MATCH_DATA	sMatchData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_TOURNAMENT_TEAM_MATCH_RESULT_RES)
	WORD							wResultCode;
	BYTE							byMatchDataCount;
	sBUDOKAI_TOURNAMENT_MATCH_DATA	aMatchData[BUDOKAI_MAX_TOURNAMENT_TEAM_MATCH_RECORD_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_JOIN_INFO_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;

	BYTE					byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE					byJoinState;		// ���� ����
	BYTE					byJoinResult;		// ���� ���

	union
	{
		sBUDOKAI_REGISTER_INDIVIDUAL_INFO	sIndividualInfo;
		sBUDOKAI_REGISTER_TEAM_INFO			sTeamInfo;
	};
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_JOIN_STATE_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	bool					bIsClientReq;

	BYTE					byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE					byJoinState;		// ���� ����
	BYTE					byJoinResult;		// ���� ���

	// ������ ���� ���
	// byMatchType = INVALID_BUDOKAI_MATCH_TYPE
	// byJoinState = INVALID_BUDOKAI_JOIN_STATE
	// byJoinResult = INVALID_BUDOKAI_JOIN_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_HISTORY_WRITE_RES)
	WORD								wResultCode;
	BYTE								byBudokaiType;
	BYTE								byMatchType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_HISTORY_WINNER_PLAYER_RES)
	WORD								wResultCode;

	WORD								wSeasonCount;			// �ش� season �� player info ��û
	BYTE								byBudokaiType;
	BYTE								byMatchType;			// eBUDOKAI_MATCH_TYPE
	BYTE								byJoinResult;			// JoinResult ���� ũ�ų� ���� ���� �ε��Ѵ�.

	BYTE								byPlayerCount;
	sBUDOKAI_PREV_SEASON_PLAYER_INFO	aPlayerInfo[BUDOKAI_MAX_SEASON_HISTORY_WINNER_PLAYER_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_JOIN_STATE_LIST_RES)
	WORD								wResultCode;
	BYTE								byMatchType;			// eBUDOKAI_MATCH_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_JOIN_STATE_LIST_DATA)
	BYTE								byMatchType;			// eBUDOKAI_MATCH_TYPE

	BYTE								byDataCount;
	sBUDOKAI_JOIN_STATE_DATA			aJoinStateData[BUDOkAI_MAX_PLAYER_JOIN_STATE_DATA_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_SET_OPEN_TIME_RES)
	WORD								wResultCode;

	BYTE								byState;				// eBUDOKAI_STATE
	BUDOKAITIME							tmOpenTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_MATCH_REWARD_RES)
	WORD					wResultCode;

	HOBJECT					hPc;
	CHARACTERID				charId;
	BYTE					byReqType;
	DWORD					dwMudosaPoint;
	BYTE					byItemCount;
	sITEM_DATA				aItems[MAX_BUDOKAI_MATCH_REWARD_ITEM_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SCOUTER_ITEM_SELL_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	DWORD					dwZenny;
	ITEMID					itemId; 
	BYTE					byPlace;
	BYTE					byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SCOUTER_CHIP_REMOVE_ALL_RES)
	WORD					wResultCode;

	HOBJECT					hPc;
	CHARACTERID				charId;
	BYTE					byChipCount;
	sITEM_MOVE_DATA			aChipMoveData[NTL_MAX_SCOUTER_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SHOP_EVENTITEM_BUY_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	HOBJECT					hNpchandle;
	CHARACTERID				charId;
	DWORD					dwMudosaPoint;
	BYTE					byBuyCount;
	ITEMID					itemID[NTL_MAX_BUY_SHOPPING_CART];
	sSHOP_BUY_INVEN			sInven[NTL_MAX_BUY_SHOPPING_CART];
	BYTE					byDeleteItemCount; 
	sITEM_DELETE_DATA		asDeleteItem[NTL_MAX_BUY_SHOPPING_CART];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SHOP_GAMBLE_BUY_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	HOBJECT					hNpchandle;
	CHARACTERID				charId;
	DWORD					dwMudosaPoint;
	ITEMID					itemID;
	sSHOP_BUY_INVEN			sInven;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_BUDOKAI_UPDATE_MUDOSA_POINT_RES)
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	DWORD					dwMudosaPoint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_REPLACE_RES)
	WORD					wResultCode;
	BYTE					byItemProcessType;//eITEM_PROCESS_TYPE
	HOBJECT					handle;
	CHARACTERID				charId;
	sITEM_DELETE_DATA		sDeleteItem;
	sITEM_DATA				sCreateItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_UPDATE_MARKING_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	sMARKING				sMarking;
	BYTE					byContentsType;	// eMARKING_CONTENTS_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SKILL_ADD_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	TBLIDX					skillId;
	BYTE					byNewClass;
	DWORD					dwZenny;
	DWORD					dwSP;
	BYTE					bySkillFrom;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SKILL_UPGRADE_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	TBLIDX					oldSkillId;
	TBLIDX					newSkillId;
	BYTE					bySlot;
	bool					bIsRpBonusAuto;
	DWORD					dwSP;
	bool					bForced;
	bool					bForMax;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_HTB_SKILL_ADD_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	TBLIDX					skillId;
	int						nSkillTime;
	DWORD					dwZenny;
	DWORD					dwSP;
	bool					bTrainerCheck;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SKILL_BUY_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	HOBJECT					hNpchandle;
	BYTE					bySellType;
	TBLIDX					skillId;
	BYTE					byNewClass;
	DWORD					dwZenny;
	DWORD					dwSP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_SKILL_INIT_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	DWORD					dwSP;
	BYTE					byNewClass;
	BYTE					byCount;
	TBLIDX					aSkillTblidx[NTL_MAX_PC_HAVE_SKILL];
	BYTE					byHTBCount;
	TBLIDX					aHTBTblidx[NTL_HTB_MAX_PC_HAVE_HTB_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_RECIPE_REG_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	BYTE					byPlace;
	BYTE					byPos;
	ITEMID					itemId;
	TBLIDX					recipeTblidx;
	BYTE					byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_HOIPOIMIX_JOB_SET_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	HOBJECT					hNpchandle;
	BYTE					byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_HOIPOIMIX_JOB_RESET_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	HOBJECT					hNpchandle;
	BYTE					byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_HOIPOIMIX_ITEM_MAKE_RES)			// ������ �����
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	HOBJECT					objHandle;
	TBLIDX					recipeTblidx;	
	bool					bIsNormal;
	DWORD					dwMixExp;				// ��� EXp
	BYTE					byMixLevel;				// ��� Level
	bool					bIsNew;
	BYTE					bySuccessResult;
	DWORD					dwSpendZenny;
	CHARACTERID				recvCharacter;
	sITEM_DATA				sCreateData;			// ���� ������
	BYTE					byCount;				// ���� ������ ����	
	sITEM_BASIC_DATA		asData[NTL_MAX_BAGSLOT_COUNT * NTL_MAX_BAG_ITEM_SLOT];	// ���� ������ ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_ITEM_STACK_UPDATE_RES)
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	BYTE					byPlace;
	BYTE					byPos;
	HOBJECT					hItem;
	BYTE					byStackCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_DOJO_BANK_HISTORY_RES)
	WORD							wResultCode;
	HOBJECT							handle;
	CHARACTERID						charId;
	BYTE							byCount;
	sDBO_DOJO_BANK_HISTORY_DATA		asData[DBO_MAX_COUNT_DOJO_BANK_HISTORY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_DOJO_BANK_ZENNY_UPDATE_RES)
	WORD					wResultCode;
	GUILDID					guildId;
	DWORD					dwZenny;
	bool					bIsSave;		// 1: ���� 0: ����
	BYTE					byType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_WORLD_SCHEDULE_SET_RES )
	WORD					wResultCode;
	sSCHEDULE_INFO			sInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_SWITCH_CHILD_ADULT_RES )
	WORD					wResultCode;
	CHARACTERID				charId;
	HOBJECT					hSubject;
	bool					bIsAdult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_SET_CHANGE_CLASS_AUTHORITY_RES )
	WORD					wResultCode;
	CHARACTERID				charId;
	HOBJECT					hSubject;
	bool					bCanChangeClass;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_ITEM_CHANGE_ATTRIBUTE_RES )
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charID;
	sITEM_DATA				sItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CHANGE_NETP_RES )
	WORD wResultCode;
	CHARACTERID charId; 
	HOBJECT handle;
	NETP netP; 
	BYTE byUpdateType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_ITEM_CHANGE_DURATIONTIME_RES )				
	WORD			wResultCode;
	HOBJECT			handle;
	CHARACTERID		charId;
	sITEM_DATA		sItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_SHOP_NETPYITEM_BUY_RES )
	HOBJECT					handle;
	WORD					wResultCode;
	CHARACTERID				charId;
	NETP					netpyPoint;
	BYTE					byBuyCount;
	ITEMID					itemID[NTL_MAX_BUY_SHOPPING_CART];
	sSHOP_BUY_INVEN			sInven[NTL_MAX_BUY_SHOPPING_CART];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_GM_COMMAND_LOG_RES )
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_DURATION_ITEM_BUY_RES )
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;
	BYTE					byPayType;
	DWORD					dwPayAmount;
	TBLIDX					merchantTblidx;
	BYTE					byPos;
	sITEM_DATA				sItem;		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_DURATION_RENEW_RES )
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;
	BYTE					byPayType;
	DWORD					dwPayAmount;
	HOBJECT					hItemHandle;
	sITEM_DURATION			sData;		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CASHITEM_INFO_RES )
	HOBJECT					handle;
	CHARACTERID				charId;
	WORD					wResultCode;
	BYTE					byCount;
	sCASHITEM_BRIEF			aInfo[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CASHITEM_MOVE_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	DWORD					dwProductId;
	sSHOP_BUY_INVEN			sData;
	ITEMID					itemId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CASHITEM_DEL_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	DWORD					dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CASHITEM_UNPACK_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	CHARACTERID				charId;
	DWORD					dwProductId;
	BYTE					byCount;			// UnPack�ؼ� �־��� ������ ����
	sCASHITEM_BRIEF			aInfo[1];			// UnPack�ؼ� ���� CASHITEM
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_CASHITEM_BUY_RES )
	WORD					wResultCode;
	HOBJECT					handle;
	DWORD					dwProductId;
	TBLIDX					HLSitemTblidx;
	BYTE					byCount;			// UnPack�ؼ� �־��� ������ ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( QG_GMT_UPDATE_RES )
	WORD					wResultCode;
	ACCOUNTID				accountId;
	CHARACTERID				charId;
	HOBJECT					hPc;
	sGAME_MANIA_TIME_DATA	sUpdateData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_DATA_LOAD_RES)
	WORD						wResultCode;
	ACCOUNTID					accountId;
	CHARACTERID					charId;
	WCHAR						awchUserID[NTL_MAX_SIZE_USERID_UNICODE + 1];
	sPC_DATA					sPcData;
	sDBO_SERVER_CHANGE_INFO		serverChangeInfo;
	bool						bTutorialFlag;
	sCHAR_WAR_FOG_FLAG			sWarFogInfo;
	PETITIONID					petitionID;
	PETITIONCATEGORY			nPetitionCategory1;//ePETITIONSYSTEM_CATEGORY_1
	PETITIONCATEGORY			nPetitionCategory2;//ePETITIONSYSTEM_CATEGORY_2
	WCHAR						awchPetitionContent[NTL_MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	sMAIL_NEW_BREIF				sMailBrief;
	sRANKBATTLE_SCORE_INFO		sRankBattleScore;
	BYTE						byGMTResetCount;
	BYTE						byPunishCount;
	sPUNISH_DATA				asPunishData[1]; // MAX = GM_PUNISH_PASSIVE_TYPE_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_ITEM_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byItemCount;
	sITEM_DATA				asItemData[1]; // Max = NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_SKILL_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					bySkillCount;
	sSKILL_DATA				asSkill[1];	// Max = NTL_MAX_PC_HAVE_SKILL
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_BUFF_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byBuffCount;
	sBUFF_DATA				asBuff[1]; // Max = NTL_MAX_BLESS_BUFF_CHARACTER_HAS + NTL_MAX_CURSE_BUFF_CHARACTER_HAS
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_HTB_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byHTBSkillCount;
	sHTB_SKILL_DATA			asHTBSkill[1];	// Max = NTL_HTB_MAX_PC_HAVE_HTB_SKILL
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_QUEST_ITEM_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byQuestInventoryCount;
	sQUEST_INVENTORY_DATA	asQuestInventory[1];	// Max = NTL_QUEST_INVENTORY_SLOT_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_QUEST_COMPLETE_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	sQUEST_COMPLETE_DATA	sQuestCompleteData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_QUEST_PROGRESS_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byQuestProgressCount;
	sQUEST_PROGRESS_DATA	asQuestProgress[1];	// Max = eMAX_CAN_PROGRESS_QUEST_NUM
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_QUICK_SLOT_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byQuickSlotCount;
	sQUICK_SLOT_DATA		asQuickSlotData[1];	// Max = NTL_CHAR_QUICK_SLOT_MAX_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_SHORTCUT_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byShortcutCount;
	sSHORTCUT_DATA			asShortcutData[1];	// Max = NTL_SHORTCUT_MAX_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_ITEM_RECIPE_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	BYTE					byRecipeCount;
	sRECIPE_DATA			asRecipeData[1];	// Max = NTL_ITEM_RECIPE_MAX_COUNT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(QG_PC_GMT_LOAD_RES)
	WORD					wResultCode;
	ACCOUNTID				accountId;
	sGAME_MANIA_TIME_DATA	sGMT_Current;
	sGAME_MANIA_TIME_DATA	sGMT_Next;
END_PROTOCOL()
//------------------------------------------------------------------
	
#pragma pack(pop)

