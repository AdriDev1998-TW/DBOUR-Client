#include "precomp_dboclient.h"
#include "WhoListGui.h"

#include "DialogDefine.h"
#include "NtlPLGuiManager.h"
#include "DialogManager.h"
#include "NtlSLEventFunc.h"

#include "DBOGlobal.h"
#include "NtlResultCode.h"
#include "DBoEvent.h"
#include "DboEventGenerator.h"
#include "TableContainer.h"
#include "TextAllTable.h"
#include "NtlSLApi.h"
#include "NtlSlGlobal.h"
#include "NtlSobAvatar.h"
#include "NtlSobManager.h"
#include "NtlSLLogic.h"
#include "DboLogic.h"
#include "NtlPacketTU.h"
#include "DisplayStringDef.h"
#include "DisplayStringManager.h"
#include "AlarmManager.h"
#include "InfoWndManager.h"


#define WHO_LIST_X 21
#define WHO_LIST_Y 97
#define WHO_LIST_MARGIN 4
#define WHO_ITEM_WITH 274
#define WHO_ITEM_HEIGHT 19

#define WHO_ICON_X 15
#define WHO_ICON_Y 97
#define WHO_LEVEL_X 139
#define WHO_LEVE_WIDTH 30
#define WHO_LOC_X 177
#define WHO_LOC_WIDTH 62
#define WHO_CHANNEL_X 246
#define WHO_CHANNEL_WIDTH 48

#define WHO_ITEM_COLOR_ONLINE RGB(255, 255, 255)
#define WHO_ITEM_COLOR_OFFLINE RGB(180, 180, 180)
#define WHO_ITEM_COLOR_FOCUS RGB(255, 219, 71)

CWhoListGui::CWhoListGui( void ) 
{

}
CWhoListGui::CWhoListGui( const RwChar* pName ) 
: CNtlPLGui(pName)
{
    Init();
}

CWhoListGui::~CWhoListGui( void ) 
{

}

VOID CWhoListGui::Init() 
{
    m_pSttDialogTitle   = NULL;
    m_pBtnClose         = NULL;
    m_pBtnTitleName     = NULL;
    m_pBtnTitleLevel    = NULL;
    m_pBtnTitleLoc      = NULL;
    m_pBtnTitleChannel  = NULL;
    m_pTabMode          = NULL;    
    m_pBtnAdd           = NULL;
    m_pBtnParty         = NULL;
    m_pBtnMail          = NULL;
    m_pBtnWhisper       = NULL;
    m_pBtnBlock         = NULL;
    m_pBtnDelete        = NULL;
    m_pSbScroll         = NULL;
    m_eListMode         = FRIEND_LIST;
    m_uiCurrentCharID   = INVALID_SERIAL_ID;
    m_nButtonIndex      = 0;
}

RwBool CWhoListGui::Create() 
{
    if(!CNtlPLGui::Create("", "gui\\WhoList.srf", "gui\\WhoList.frm"))
        return FALSE;

    CNtlPLGui::CreateComponents(CNtlPLGuiManager::GetInstance()->GetGuiManager());

    m_pThis             = (gui::CDialog*)GetComponent("dlgMain");
    m_pSttDialogTitle   = (gui::CStaticBox*)GetComponent("sttDialogTitle");
    m_pBtnClose         = (gui::CButton*)GetComponent("btnClose");
    m_pTabMode          = (gui::CTabButton*)GetComponent("tabList");
    m_pBtnTitleName     = (gui::CButton*)GetComponent("btnTitleName");
    m_pBtnTitleLevel    = (gui::CButton*)GetComponent("btnTitleLevel");
    m_pBtnTitleLoc      = (gui::CButton*)GetComponent("btnTitleLoc");
    m_pBtnTitleChannel  = (gui::CButton*)GetComponent("btnTitleChannel");    
    m_pBtnAdd           = (gui::CButton*)GetComponent("btnAdd");
    m_pBtnParty         = (gui::CButton*)GetComponent("btnParty");
    m_pBtnMail          = (gui::CButton*)GetComponent("btnMail");
    m_pBtnWhisper       = (gui::CButton*)GetComponent("btnWhisper");
    m_pBtnBlock         = (gui::CButton*)GetComponent("btnBlock");
    m_pBtnDelete        = (gui::CButton*)GetComponent("btnDelete");
    m_pSbScroll         = (gui::CScrollBar*)GetComponent("scbScroll");
	m_pBtnHelp			= (gui::CButton*)GetComponent("btnHelp");

    m_pBtnAdd->SetToolTip(GetDisplayStringManager()->GetString(DST_FRIEND_ADD));
    m_pBtnParty->SetToolTip(GetDisplayStringManager()->GetString(DST_FRIEND_INVITE));
    m_pBtnMail->SetToolTip(GetDisplayStringManager()->GetString(DST_FRIEND_MAIL));
    m_pBtnWhisper->SetToolTip(GetDisplayStringManager()->GetString(DST_FRIEND_WHISPER));
    m_pBtnBlock->SetToolTip(GetDisplayStringManager()->GetString(DST_FRIEND_BLOCK));
    m_pBtnDelete->SetToolTip(GetDisplayStringManager()->GetString(DST_FRIEND_DELETE));

    CreateInfoStaticBox();

    // ���� ����        
    m_slotMouseLeave    = m_pThis->SigMouseLeave().Connect(this, &CWhoListGui::OnMouseLeave);
    m_slotClose         = m_pBtnClose->SigClicked().Connect(this, &CWhoListGui::OnCloseBtnClicked);
    m_slotBtnTitleName  = m_pBtnTitleName->SigClicked().Connect(this, &CWhoListGui::OnTitleNameClicked);
    m_slotBtnTitleLevel = m_pBtnTitleLevel->SigClicked().Connect(this, &CWhoListGui::OnTitleLevelClicked);
    m_slotBtnTitleLoc   = m_pBtnTitleLoc->SigClicked().Connect(this, &CWhoListGui::OnTitleLocClicked);
    m_slotBtnTitleChannel = m_pBtnTitleChannel->SigClicked().Connect(this, &CWhoListGui::OnTitleChannelClicked);
    m_slotBtnAdd        = m_pBtnAdd->SigClicked().Connect(this, &CWhoListGui::OnAddBtnClicked);
    m_slotBtnParty      = m_pBtnParty->SigClicked().Connect(this, &CWhoListGui::OnPartyBtnClicked);
    m_slotBtnMail       = m_pBtnMail->SigClicked().Connect(this, &CWhoListGui::OnMailBtnClicked);
    m_slotBtnWhisper    = m_pBtnWhisper->SigClicked().Connect(this, &CWhoListGui::OnWhisperClicked);
    m_slotBtnBlock      = m_pBtnBlock->SigClicked().Connect(this, &CWhoListGui::OnBlockClicked);
    m_slotBtnDelete     = m_pBtnDelete->SigClicked().Connect(this, &CWhoListGui::OnDeleteClicked);
    m_slotScroll        = m_pSbScroll->SigValueChanged().Connect(this, &CWhoListGui::OnScrollChanged);
    m_slotScrollMove    = m_pSbScroll->SigSliderMoved().Connect(this, &CWhoListGui::OnScrollChanged);
    m_slotTabChange     = m_pTabMode->SigSelectChanged().Connect(this, &CWhoListGui::OnTabChanged);
    m_slotCaptureWheelMove = m_pThis->SigMouseWheel().Connect(this, &CWhoListGui::OnCaptureWheelMove);    
	m_slotClickedBtnHelp = m_pBtnHelp->SigClicked().Connect( this, &CWhoListGui::OnClickedBtnHelp );
    
    
    // ���� �̸� ��ġ ����
    m_pSttDialogTitle->SetPosition(DBOGUI_DIALOG_TITLE_X, DBOGUI_DIALOG_TITLE_Y);
	m_pSttDialogTitle->SetText("Who's Online");//GetDisplayStringManager()->GetString("DST_FRIEND_TAB_FRIEND));

    // �� ����            
	std::wstring wstrTabFriend(L"Who's Online");//GetDisplayStringManager()->GetString(DST_FRIEND_TAB_FRIEND);
	std::wstring wstrTabBlack(L"Unknown");//= GetDisplayStringManager()->GetString(DST_FRIEND_TAB_BLACKLIST);
    m_pTabMode->AddTab(wstrTabFriend);
    m_pTabMode->AddTab(wstrTabBlack);
    m_pTabMode->SelectTab(0);

    // �ؽ�Ʈ ����
    m_pBtnTitleName->SetText(GetDisplayStringManager()->GetString(DST_FRIEND_SUBJECT_NAME));
    m_pBtnTitleLevel->SetText(GetDisplayStringManager()->GetString(DST_FRIEND_SUBJECT_LEVEL));
    m_pBtnTitleLoc->SetText(GetDisplayStringManager()->GetString(DST_FRIEND_SUBJECT_LOC));
    m_pBtnTitleChannel->SetText(GetDisplayStringManager()->GetString(DST_FRIEND_SUBJECT_CHANNEL));

    // ����Ʈ ����
    m_InfoList.Create(m_pThis, this, 
                      &CWhoListGui::OnCreateItem,
                      &CWhoListGui::OnDestroyItem,
                      &CWhoListGui::OnClickedItem,
                     WHO_LIST_X,WHO_LIST_Y,
                     WHO_LIST_MARGIN,WHO_LIST_MAX_VISIBLE);

	for(int i = 0; i <WHO_LIST_MAX_VISIBLE; ++i)
	{
		CRectangle rectIcon;
		// ������ ����
		rectIcon.left =WHO_ICON_X;
		rectIcon.right = rectIcon.left + 19;
		rectIcon.top =WHO_ICON_Y + i * (19 +WHO_LIST_MARGIN);
		rectIcon.bottom = rectIcon.top + 19;

		m_pPnlIcon[i] = NTL_NEW gui::CPanel(rectIcon, m_pThis, GetNtlGuiManager()->GetSurfaceManager());
	}

    LinkMsg(g_EventFriendInfoNotify);
    LinkMsg(g_EventMsgBoxResult);
    LinkMsg(g_EventIconPopupResult);

    Show(FALSE);
    m_InfoList.Show(FALSE);

    return TRUE;
}

VOID CWhoListGui::Destroy() 
{
    m_InfoList.Destroy();

    UnLinkMsg(g_EventFriendInfoNotify);
    UnLinkMsg(g_EventMsgBoxResult);
    UnLinkMsg(g_EventIconPopupResult);

    CNtlPLGui::DestroyComponents();
    CNtlPLGui::Destroy();
}

RwInt32 CWhoListGui::SwitchDialog( bool bOpen ) 
{
    Show(bOpen);    
    m_InfoList.Show(bOpen);

    return TRUE;
}

VOID CWhoListGui::HandleEvents( RWS::CMsg &pMsg ) 
{
    if(pMsg.Id == g_EventFriendInfoNotify)
    {
        SNtlEventFriendInfoNotify* pData = (SNtlEventFriendInfoNotify*)pMsg.pData;
        switch(pData->nNotifyMsg)
        {
        case TU_FRIEND_ADD_RES:
            OnFriendAddRes(pData->targetID);
            break;
        case TU_FRIEND_DEL_RES:
            OnFriendDelRes(pData->targetID);
            break;
        case TU_FRIEND_MOVE_RES:
            OnFriendMoveRes(pData->targetID);
            break;
        case TU_FRIEND_LIST_INFO:
            OnFriendListInfo();
            break;
        case TU_FRIEND_INFO:
            OnFriendInfo(pData->targetID);
            break;
        case TU_FRIEND_INFO_CHANGE:
            OnFriendInfoChange(pData->targetID);
            break;
        case TU_FRIEND_BLACK_ADD_RES:
            OnBlackListAddRes(pData->targetID);
            break;
        case TU_FRIEND_BLACK_DEL_RES:
            OnBlackListDelRes(pData->targetID);
            break;
        case SLFE_FRIEND_LOGIN:
            OnFriendLogin(pData->targetID);
            break;
        }
    }
    else if(pMsg.Id == g_EventMsgBoxResult)     // ģ�� �������� Ȯ�� ��ư Ŭ����
    {
        SDboEventMsgBoxResult *pMsgBoxResult = reinterpret_cast<SDboEventMsgBoxResult*>( pMsg.pData );
        if( pMsgBoxResult->eResult == MBR_OK )
        {
            if(pMsgBoxResult->uiWorkId == MBW_FRIENDLIST_DEL_ASK)       // ģ�� ���� ��û
            {
                GetDboGlobal()->GetChatPacketGenerator()->SendFriend_Del_Req(m_uiCurrentCharID);
            }
            else if(pMsgBoxResult->uiWorkId == MBW_BLACKLIST_DEL_ASK)   // �� ����Ʈ ���� ��û
            {
                GetDboGlobal()->GetChatPacketGenerator()->SendFriend_Black_Del_Req(m_uiCurrentCharID);
            }
            else if(pMsgBoxResult->uiWorkId == MBW_FRIENDLIST_ADD_ASK)  // ģ�� ��� ��û
            {
                if(IsEnableAdd(pMsgBoxResult->pData->pwcText, FRIEND_LIST))
                {
                    if(wcslen(pMsgBoxResult->pData->pwcText) <= NTL_MAX_SIZE_CHAR_NAME_UNICODE)
                    {
                        GetDboGlobal()->GetChatPacketGenerator()->SendFriend_Add_Req(pMsgBoxResult->pData->pwcText);
                    }
                    else
                    {
						GetAlarmManager()->AlarmMessage( DST_FRIEND_TOO_OVER_NAME );
                        //CNtlSLEventGenerator::SysMsg((WCHAR*)GetDisplayStringManager()->GetString(DST_FRIEND_TOO_OVER_NAME));
                    }                    
                }                
            }
            else if(pMsgBoxResult->uiWorkId == MBW_BLACKLIST_ADD_ASK)   // ������Ʈ ��� ��û
            {
                if(IsEnableAdd(pMsgBoxResult->pData->pwcText, BLACK_LIST))
                {
                    GetDboGlobal()->GetChatPacketGenerator()->SendFriend_Black_Add_Req(pMsgBoxResult->pData->pwcText);
                }                
            }
        }        
    }
    else if(pMsg.Id == g_EventIconPopupResult)          // Ÿ���� �޴�â���� ģ���߰� ��ư�� Ŭ��������
    {
        SDboEventIconPopupResult* pData = (SDboEventIconPopupResult*)pMsg.pData;
        if(pData->nWorkId != PMW_FRIEND_ADD)
            return;
        
        std::wstring wstrCharName = Logic_GetName(GetNtlSobManager()->GetSobObject(pData->uiSerial));
        if(IsEnableAdd(wstrCharName.c_str(), FRIEND_LIST))
        {
            GetDboGlobal()->GetChatPacketGenerator()->SendFriend_Add_Req(wstrCharName.c_str());
        }
    }
}

VOID CWhoListGui::OnCloseBtnClicked( gui::CComponent* pComponent ) 
{
	if( !Logic_CanMouseInput_in_Tutorial( ETL_MOUSE_INPUT_TYPE_WHOSONLINE_WND_CLOSE_BTN ) )
		return;

    GetDialogManager()->CloseDialog(DIALOG_WHOSONLINE);
}

VOID CWhoListGui::OnAddBtnClicked( gui::CComponent* pComponent ) 
{
    if(m_eListMode == FRIEND_LIST)
    {
        //CDboEventGenerator::MsgBoxShow(GetDisplayStringManager()->GetString(DST_FRIEND_MSG_FRIEND_ADD), MBW_FRIENDLIST_ADD_ASK, MBTF_INPUT);            
		GetAlarmManager()->AlarmMessage( DST_FRIEND_MSG_FRIEND_ADD );
    }
    else if(m_eListMode == BLACK_LIST)
    {
        //CDboEventGenerator::MsgBoxShow(GetDisplayStringManager()->GetString(DST_FRIEND_MSG_BLACK_ADD), MBW_BLACKLIST_ADD_ASK, MBTF_INPUT);        
		GetAlarmManager()->AlarmMessage( DST_FRIEND_MSG_BLACK_ADD );
    }
}

VOID CWhoListGui::OnFriendAddRes(RwUInt32 uiTargetID)
{
    if(m_eListMode != FRIEND_LIST)
        return;

	CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();
    sFriendMember* pMember = reinterpret_cast<sFriendMember*>( pFriendList->GetMemberbyKey(uiTargetID) );
    if(!pMember)
        return;

    m_InfoList.AddItem(pMember->wszMemberName, pMember);   
    UpdateInfo(pMember->charID);    
}

VOID CWhoListGui::OnBlackListAddRes(RwUInt32 uiTargetID)
{
    if(m_eListMode != BLACK_LIST)
        return;

	CNtlSLBlackList* pBlackList = GetNtlSLGlobal()->GetSobAvatar()->GetBlackList();
	sBlackListMember* pMember = reinterpret_cast<sBlackListMember*>( pBlackList->GetMemberbyKey(uiTargetID) );
    if(!pMember)
        return;

    m_InfoList.AddItem(pMember->wszMemberName, pMember);      
    UpdateInfo(pMember->charID);
}

// ��Ƽ �ʴ� ��ư�� Ŭ��������
VOID CWhoListGui::OnPartyBtnClicked( gui::CComponent* pComponent ) 
{
    if(m_uiCurrentCharID == INVALID_SERIAL_ID)
    {
		GetAlarmManager()->AlarmMessage( DST_FRIEND_INVALID_USER );
        //CNtlSLEventGenerator::SysMsg((WCHAR*)GetDisplayStringManager()->GetString(DST_FRIEND_INVALID_USER));
        return;
    }

	CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();
	sFriendMember* pMember = reinterpret_cast<sFriendMember*>( pFriendList->GetMemberbyKey(m_uiCurrentCharID) );
    if(!pMember)
        return;

    GetDboGlobal()->GetGamePacketGenerator()->SendPartyInvite_CharID(m_uiCurrentCharID);
}

VOID CWhoListGui::OnWhisperClicked( gui::CComponent* pComponent ) 
{
    if(m_uiCurrentCharID == INVALID_SERIAL_ID)
    {
		GetAlarmManager()->AlarmMessage( DST_FRIEND_INVALID_USER );
        //CNtlSLEventGenerator::SysMsg((WCHAR*)GetDisplayStringManager()->GetString(DST_FRIEND_INVALID_USER));
        return;
    }    

	CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();
	sFriendMember* pMember = reinterpret_cast<sFriendMember*>( pFriendList->GetMemberbyKey(m_uiCurrentCharID) );
    if(!pMember)
        return;
    
    WCHAR buf[1024] = {0,};
    swprintf_s(buf, L"/w %s ", pMember->wszMemberName);
    CDboEventGenerator::SetTextToInputChat(buf);
}

VOID CWhoListGui::OnMailBtnClicked( gui::CComponent* pComponent ) 
{
    if(m_uiCurrentCharID == INVALID_SERIAL_ID)
    {
		GetAlarmManager()->AlarmMessage( DST_FRIEND_INVALID_USER );
        //CNtlSLEventGenerator::SysMsg((WCHAR*)GetDisplayStringManager()->GetString(DST_FRIEND_INVALID_USER));
        return;
    }

	CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();
	sFriendMember* pMember = reinterpret_cast<sFriendMember*>( pFriendList->GetMemberbyKey(m_uiCurrentCharID) );
    if(!pMember)
        return;
    
    // ���� ���� �̺�Ʈ
    CDboEventGenerator::OpenSendMail(pMember->wszMemberName);
}

// ģ������Ʈ�� �ִ� ģ���� ������Ʈ�� �̵��� ��û�Ѵ�.
VOID CWhoListGui::OnBlockClicked( gui::CComponent* pComponent ) 
{
    if(m_uiCurrentCharID == INVALID_SERIAL_ID)
    {
		GetAlarmManager()->AlarmMessage( DST_FRIEND_INVALID_USER );
        return;
    }

    GetDboGlobal()->GetChatPacketGenerator()->SendFriend_Move_Req(m_uiCurrentCharID);
}

VOID CWhoListGui::OnFriendMoveRes(RwUInt32 uiTargetID)
{
    if(uiTargetID == GetDboGlobal()->GetCommunityTarget())
    {
        // UI ����
        CNtlSLEventGenerator::CommuTargetRelease(uiTargetID);
    }

    RefreshList();       
}

/// ģ��/������Ʈ ���� ��û
VOID CWhoListGui::OnDeleteClicked( gui::CComponent* pComponent ) 
{
    if(m_uiCurrentCharID == INVALID_SERIAL_ID)
    {
		GetAlarmManager()->AlarmMessage( DST_FRIEND_INVALID_USER );
        return;
    }

    // Ȯ�� UI ���
    if(m_eListMode == FRIEND_LIST)
    {
		GetAlarmManager()->FormattedAlarmMessage( DST_FRIEND_MSG_FRIEND_DEL, FALSE, 0.0f, NULL, GetNtlSLGlobal()->GetSobAvatar()->GetFriendList()->GetMemberbyKey(m_uiCurrentCharID)->wszMemberName );	
    }
    else if(m_eListMode == BLACK_LIST)
    {
		GetAlarmManager()->FormattedAlarmMessage( DST_FRIEND_MSG_BLACk_DEL, FALSE, 0.0f, NULL, GetNtlSLGlobal()->GetSobAvatar()->GetBlackList()->GetMemberbyKey(m_uiCurrentCharID)->wszMemberName );	
    }    
}

VOID CWhoListGui::OnFriendDelRes(RwUInt32 uiTargetID)
{
    if(m_eListMode != FRIEND_LIST)
        return;

    if(uiTargetID == GetDboGlobal()->GetCommunityTarget())
    {
        // UI ����
        CNtlSLEventGenerator::CommuTargetRelease(uiTargetID);
    }

    RefreshList();
}

VOID CWhoListGui::OnBlackListDelRes(RwUInt32 uiTargetID)
{
    if(m_eListMode != BLACK_LIST)
        return;

    RefreshList();
}

// ó�� ���ӽ� ģ�� ����Ʈ ������ �޴´�.
VOID CWhoListGui::OnFriendListInfo()
{
    // UI�� �����Ѵ�.
    OnTabChanged(m_eListMode, NULL);
}

// ģ������Ʈ�� �ִ� ģ���߿� ���� ������ ģ���� ������ ����´�.
VOID CWhoListGui::OnFriendInfo(RwUInt32 uiTargetID)
{
    if(m_eListMode != FRIEND_LIST)
        return;

    UpdateInfo(uiTargetID);
}

// �������� ģ���� ������ ����Ǿ����� ����´�.
VOID CWhoListGui::OnFriendInfoChange(RwUInt32 uiTargetID)
{
    if(m_eListMode != FRIEND_LIST)
        return;

    UpdateInfo(uiTargetID);
}

// ó�� ģ���� �α��������� �˸� �������� ǥ���Ѵ�.
VOID CWhoListGui::OnFriendLogin( RwUInt32 uiTargetID ) 
{
    // ���� �˸�UI�� ģ���� ������ �˸���.    
	CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();
	sFriendMember* pMember = reinterpret_cast<sFriendMember*>( pFriendList->GetMemberbyKey(uiTargetID) );
    if(!pMember)
        return;

    GetAlarmManager()->FormattedAlarmMessage(DST_FRIEND_MSG_LOGIN, FALSE, NULL, pMember->wszMemberName);

	WCHAR awcBuffer[128];
	swprintf_s( awcBuffer, 128, GetDisplayStringManager()->GetString( DST_SIDEICON_HINT_FRIEND_TEXT) , pMember->wszMemberName );

	CNtlSLEventGenerator::PopoNotify( GetDisplayStringManager()->GetString( DST_SIDEICON_HINT_FRIEND_TITLE ),
		awcBuffer, TRUE, 5.0f ); // 5�� ���� ������

}

//////////////////////////////////////////////////////////////////////////
VOID CWhoListGui::OnScrollChanged( RwInt32 nNewOffset ) 
{
    m_InfoList.SetValue(nNewOffset);
    UpdateInfo(NULL);
}

VOID CWhoListGui::CreateInfoStaticBox() 
{
    CRectangle rectLevel, rectLoc, rectChannel, rectJob, rectBackSpace, rectIcon;
    for(int i = 0; i < WHO_LIST_MAX_VISIBLE; ++i)
    {
        // ��ư ��� ����
        rectBackSpace.left  = WHO_LIST_X;
        rectBackSpace.right = rectBackSpace.left + WHO_ITEM_WITH;
        rectBackSpace.top   = WHO_LIST_Y + i * (WHO_ITEM_HEIGHT + WHO_LIST_MARGIN);
        rectBackSpace.bottom = rectBackSpace.top + WHO_ITEM_HEIGHT;

        m_pPnlBackSpace[i] = NTL_NEW gui::CPanel(rectBackSpace, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), GetNtlGuiManager()->GetSurfaceManager()->GetSurface("WhoList.srf", "srfBackSpace"));

        //// ������ ����
        //rectIcon.left = FRIEND_ICON_X;
        //rectIcon.right = rectIcon.left + 19;
        //rectIcon.top = FRIEND_ICON_Y + i * (19 + FRIEND_LIST_MARGIN);
        //rectIcon.bottom = rectIcon.top + 19;

        //m_pPnlIcon[i] = NTL_NEW gui::CPanel(rectIcon, m_pThis, GetNtlGuiManager()->GetSurfaceManager());

        // Info ��ư�� ��ü ����
        rectLevel.left = WHO_LEVEL_X;
        rectLevel.right = WHO_LEVEL_X + WHO_LEVE_WIDTH;
        rectLoc.left = WHO_LOC_X;
        rectLoc.right = WHO_LOC_X + WHO_LOC_WIDTH;
        rectChannel.left = WHO_CHANNEL_X;
        rectChannel.right = WHO_CHANNEL_X + WHO_CHANNEL_WIDTH;

        rectLevel.top = rectLoc.top = rectChannel.top = WHO_LIST_Y + i * (WHO_ITEM_HEIGHT + WHO_LIST_MARGIN);
        rectLevel.bottom = rectLoc.bottom = rectChannel.bottom = rectLevel.top + WHO_ITEM_HEIGHT;

        m_pSttLevel[i]      = NTL_NEW gui::CStaticBox(rectLevel, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_CENTER);
        m_pSttLoc[i]        = NTL_NEW gui::CStaticBox(rectLoc, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_CENTER);
        m_pSttChannel[i]    = NTL_NEW gui::CStaticBox(rectChannel, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_CENTER);
        
        m_pSttLevel[i]->CreateFontStd(DETAIL_FONT, 90, NULL);
        m_pSttLoc[i]->CreateFontStd(DETAIL_FONT, 90, NULL);
        m_pSttChannel[i]->CreateFontStd(DETAIL_FONT, 90, NULL);

        m_pSttLevel[i]->Clear();
        m_pSttLoc[i]->Clear();
        m_pSttChannel[i]->Clear();
    }
}

gui::CButton* CWhoListGui::OnCreateItem() 
{
    gui::CButton* pButton = NTL_NEW gui::CButton(CRectangle(0, 0, WHO_ITEM_WITH, WHO_ITEM_HEIGHT), L"", NULL,
        GetNtlGuiManager()->GetSurfaceManager());
 
    pButton->AddSurfaceDown(GetNtlGuiManager()->GetSurfaceManager()->GetSurface("wholist.srf", "srfListFoc"));

    pButton->SetTextStyle(0);
    pButton->SetTextCoord(20, 4);
    pButton->SetTextDownCoordDiff(0, 0);        
    pButton->SetToggleMode(true);
    pButton->SetTextFont(DETAIL_FONT, 90, NULL);

    pButton->ApplyText();

    m_slotMouseMove[m_nButtonIndex]     = pButton->SigMouseMove().Connect(this, &CWhoListGui::OnMouseMove);
    m_slotBtnMouseLeave[m_nButtonIndex] = pButton->SigMouseLeave().Connect(this, &CWhoListGui::OnMouseLeave);
    m_slotListWheelMove[m_nButtonIndex] = pButton->SigMouseWheel().Connect(this, &CWhoListGui::OnCaptureWheelMove);    
    m_slotToggled[m_nButtonIndex]       = pButton->SigToggled().Connect(this, &CWhoListGui::OnToggled);
    ++m_nButtonIndex;

    return pButton;
}

void CWhoListGui::OnDestroyItem( gui::CButton* pButton ) 
{
    NTL_DELETE(pButton);
}

void CWhoListGui::OnClickedItem( RwInt32 iIndex ) 
{
    CButtonList<CWhoListGui, sCommunityMember*>::SItem sItem = m_InfoList.GetItem(iIndex);
    sFriendMember* pMember = reinterpret_cast<sFriendMember*>( sItem.TData );

            m_pBtnParty->Show(true);
            m_pBtnWhisper->Show(true);
    
        OnTargeting(pMember);

    m_uiCurrentCharID = pMember->charID;    
}


/// ��ư ����Ʈ�� ��ư�� ��� ���°� ���Ҷ� ȣ��Ǵ� �Լ� 
/// ��۽ÿ� ��� �������� �Ǿ����� Ȯ���ϰ�, ��ۻ��µ� ��ư�� ������ ���� ������ INVALID�� �Ѵ�.
VOID CWhoListGui::OnToggled( gui::CComponent* pComponent, bool bToggled ) 
{
    if(m_InfoList.GetSelect() == -1)
    {
        m_uiCurrentCharID = INVALID_SERIAL_ID;
    }
}

VOID CWhoListGui::OnTargeting( sFriendMember* pMember ) 
{
    if(pMember->uiSerialID == INVALID_SERIAL_ID)
        return;

    if(pMember->bOnline)    // �¶����� ���
    {
        // ���� ������ Ÿ���� ������ �����Ѵ�.
        if(GetDboGlobal()->GetTargetSerial() != INVALID_SERIAL_ID)
        {
            CNtlSLEventGenerator::SobTargetSelectRelease(GetDboGlobal()->GetTargetSerial());            
            GetDboGlobal()->SetTargetSerial(INVALID_SERIAL_ID);
        }

        // Ŀ�´�Ƽ Ÿ���� �����Ѵ�.
        CNtlSLEventGenerator::CommuTargetSelect(pMember->charID, pMember->uiSerialID, pMember->wszMemberName, COMMU_TARGET_FRIEND);
    }
    else    // �������� ���
    {
        // Ŀ�´�Ƽ Ÿ������ �Ǿ� �ִ� ��� -> Ŀ�´�Ƽ Ÿ�� UI ����
        if(GetDboGlobal()->GetCommunityTarget() != INVALID_SERIAL_ID)
        {
            // UI ����
            CNtlSLEventGenerator::CommuTargetRelease(pMember->uiSerialID);
        }
        // Ŀ�´�Ƽ Ÿ������ �ȵǾ� �ִ� ��� -> ��ȭ ���� (UI�� �ȳ����ִ�.)
    }
}

VOID CWhoListGui::OnTabChanged( RwInt32 nIndex, RwInt32 nOldIndex ) 
{
    m_InfoList.ClearItem();
    for(int i = 0; i < WHO_LIST_MAX_VISIBLE; ++i)
    {
        m_pSttLevel[i]->Clear();
        m_pSttLoc[i]->Clear();
        m_pSttChannel[i]->Clear();   
        m_pPnlIcon[i]->ClearSurface();
    }

    switch(nIndex)
    {
    case FRIEND_LIST:
        {
            // ��Ʈ�� Ȱ��ȭ
            m_pBtnParty->Show(true);
            m_pBtnMail->Show(true);
            m_pBtnWhisper->Show(true);
            m_pBtnBlock->Show(true);

            CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();
            for(COMMUNITY_ITER it = pFriendList->Begin(); it != pFriendList->End(); ++it)
            {
				sFriendMember* pMember = reinterpret_cast<sFriendMember*>( *it );
                m_InfoList.AddItem(pMember->wszMemberName, pMember);
            }   
        }        
        break;
    case BLACK_LIST:
        {
            // ��Ʈ�� ��Ȱ��ȭ
            m_pBtnParty->Show(false);
            m_pBtnMail->Show(false);
            m_pBtnWhisper->Show(false);
            m_pBtnBlock->Show(false);

            CNtlSLBlackList* pBlackList = GetNtlSLGlobal()->GetSobAvatar()->GetBlackList();
            for(COMMUNITY_ITER it = pBlackList->Begin(); it != pBlackList->End(); ++it)
            {
				sBlackListMember* pMember = reinterpret_cast<sBlackListMember*>( *it );
				m_InfoList.AddItem(pMember->wszMemberName, pMember);
            }            
        }        
        break;
    }

    m_eListMode = (EFriendListMode)nIndex;
    m_uiCurrentCharID = INVALID_SERIAL_ID;

    UpdateInfo(NULL);
}


VOID CWhoListGui::RefreshList() 
{
    RwInt32 nCurValue = m_InfoList.GetValue();
    OnTabChanged(m_eListMode, m_eListMode);
    m_InfoList.SetValue(nCurValue); 
    UpdateInfo(NULL);
}

// NULL�̸� ���� ȭ�鿡 ���̴� ����Ʈ���� ��� ������ ������Ʈ�Ѵ�.
VOID CWhoListGui::UpdateInfo( RwUInt32 uiCharID ) 
{
    RwInt32 nCurValue = m_InfoList.GetValue();    
    for(int i = nCurValue; i < nCurValue + WHO_LIST_MAX_VISIBLE; ++i)
    {
        if(i >= m_InfoList.GetSize())
            break;

        CButtonList<CWhoListGui, sCommunityMember*>::SItem sItem = m_InfoList.GetItem(i);

        if(m_eListMode == FRIEND_LIST)
        {
            sFriendMember* pMember = reinterpret_cast<sFriendMember*>( sItem.TData );

            if(uiCharID == NULL || pMember->charID == uiCharID) 
            {
                if(pMember->bOnline)  // �¶���
                {
                    // ������ ��ư
                    m_pSttLevel[i - nCurValue]->SetText(pMember->byLevel);                
                    m_pSttChannel[i - nCurValue]->SetText(pMember->byChannel);
                    m_pSttChannel[i - nCurValue]->SetTextColor(WHO_ITEM_COLOR_ONLINE, TRUE);                
                    std::wstring strAreaName;                
                    Logic_GetAreaNameFromTblIDX(pMember->mapTblIdx, &strAreaName);
                    m_pSttLoc[i - nCurValue]->SetText(strAreaName.c_str());

                    gui::CButton* pButton = m_InfoList.GetButton(i - nCurValue);
                    if(pButton)
                    {
                        pButton->SetTextUpColor(WHO_ITEM_COLOR_ONLINE);
                        pButton->SetTextFocusColor(WHO_ITEM_COLOR_ONLINE);
                        pButton->SetTextDownColor(WHO_ITEM_COLOR_FOCUS);
                        pButton->ApplyText();
                    }

                    if(m_uiCurrentCharID == pMember->charID)
                    {
                        m_pBtnParty->Show(true);
                        m_pBtnWhisper->Show(true);
                    }

                    // ���� ������ ǥ��
                    m_pPnlIcon[i - nCurValue]->AddSurface(Logic_GetPCClassIconSurface(pMember->byClass, FALSE));

                }
                else    // ��������
                {
                    m_pSttLevel[i - nCurValue]->Clear();
                    m_pSttLoc[i - nCurValue]->Clear();
                    m_pSttChannel[i - nCurValue]->SetText(GetDisplayStringManager()->GetString(DST_FRIEND_OFFLINE));                  
                    m_pSttChannel[i - nCurValue]->SetTextColor(WHO_ITEM_COLOR_OFFLINE, TRUE);
                    
                    gui::CButton* pButton = m_InfoList.GetButton(i - nCurValue);
                    if(pButton)
                    {
                        pButton->SetTextUpColor(WHO_ITEM_COLOR_OFFLINE);
                        pButton->SetTextFocusColor(WHO_ITEM_COLOR_OFFLINE);
                        pButton->SetTextDownColor(WHO_ITEM_COLOR_FOCUS);
                        pButton->ApplyText();
                    }

                    if(m_uiCurrentCharID == pMember->charID)
                    {
                        m_pBtnParty->Show(false);
                        m_pBtnWhisper->Show(false);
                    }                    
                }    

           


                // �Ѹ� ���� �����̸� ������ ������ �������ʰ� ������.
                if(pMember->charID == uiCharID)
                    break;
            }
        }
        else if(m_eListMode == BLACK_LIST)
        {
            gui::CButton* pButton = m_InfoList.GetButton(i - nCurValue);
            if(pButton)
            {
                pButton->SetTextUpColor(WHO_ITEM_COLOR_OFFLINE);
                pButton->SetTextFocusColor(WHO_ITEM_COLOR_OFFLINE);
                pButton->SetTextDownColor(WHO_ITEM_COLOR_FOCUS);
                pButton->ApplyText();
            }

            m_pSttLevel[i - nCurValue]->Clear();
            m_pSttLoc[i - nCurValue]->Clear();
            m_pSttChannel[i - nCurValue]->Clear();   
        }   
    }

    // ��ũ�ѹ� ������Ʈ       
    RwInt32 nMax = m_InfoList.GetSize() - WHO_LIST_MAX_VISIBLE;
    m_pSbScroll->SetRange(0, max(0, nMax));    
    m_pSbScroll->SetValue(nCurValue);
}

RwBool CWhoListGui::IsEnableAdd(const WCHAR* pwszName, EFriendListMode eMode ) 
{
    if(!pwszName)
        return FALSE;

    switch(eMode)
    {
    case FRIEND_LIST:
        // ������Ʈ�� �����ϸ� ģ������Ʈ�� �߰����� ���Ѵ�.
        if(GetNtlSLGlobal()->GetSobAvatar()->GetBlackList()->GetMemberbyName((WCHAR*)pwszName))
        {
            //CNtlSLEventGenerator::SysMsg((WCHAR*)GetDisplayStringManager()->GetString(DST_FRIEND_ERR_EXIST_BLACK));
			GetAlarmManager()->AlarmMessage( DST_FRIEND_ERR_EXIST_BLACK );
            return FALSE;
        }        
        break;
    case BLACK_LIST:
        // ģ������Ʈ�� �����ϸ� ������Ʈ�� �߰����� ���Ѵ�.
        if(GetNtlSLGlobal()->GetSobAvatar()->GetFriendList()->GetMemberbyName((WCHAR*)pwszName))
        {
            //CNtlSLEventGenerator::SysMsg((WCHAR*)GetDisplayStringManager()->GetString(DST_FRIEND_ERR_EXIST_FRIEND));
			GetAlarmManager()->AlarmMessage( DST_FRIEND_ERR_EXIST_FRIEND );
            return FALSE;
        }
        break;
    }

    return TRUE;
}

VOID CWhoListGui::OnMouseMove( RwInt32 nFlags, RwInt32 nX, RwInt32 nY ) 
{
    // ��ư���� ���콺�� �ö����� ������ ǥ���Ѵ�.

    nX = CMouse::GetX();
    nY = CMouse::GetY();

    RwInt32 nCurValue = m_InfoList.GetValue();    
    CRectangle rect;    
    for(int i = nCurValue; i < nCurValue + WHO_LIST_MAX_VISIBLE; ++i)
    {
        if(i >= m_InfoList.GetSize())
            break;

		if( m_eListMode != FRIEND_LIST )
			break;

        CButtonList<CWhoListGui, sCommunityMember*>::SItem sItem = m_InfoList.GetItem(i);
        sFriendMember* pMember = reinterpret_cast<sFriendMember*>( sItem.TData );

        // ���������� ǥ������ �ʴ´�.
        if(!pMember->bOnline)
            continue;

        gui::CButton* pButton = m_InfoList.GetButton(i - nCurValue);
        if(!pButton)
            continue;

        rect = pButton->GetScreenRect();
        if(rect.PtInRect(nX, nY))
        {
            GetInfoWndManager()->ShowInfoWindow(TRUE, CInfoWndManager::INFOWND_FRIEND_LIST, rect.left, rect.top, (VOID*)pMember, DIALOG_WHOSONLINE);
            return;
        }
    }   

    if(GetInfoWndManager()->GetRequestGui() == DIALOG_WHOSONLINE)
    {
        GetInfoWndManager()->ShowInfoWindow(FALSE);
    }
}

VOID CWhoListGui::OnMouseLeave( gui::CComponent* pComponent ) 
{
    if(GetInfoWndManager()->GetRequestGui() == DIALOG_WHOSONLINE)
    {
        GetInfoWndManager()->ShowInfoWindow(FALSE);
    }
}

VOID CWhoListGui::OnCaptureWheelMove( RwInt32 nFlag, RwInt16 sDelta, CPos& pos ) 
{
    if(!IsShow())
        return;

    RwInt32 nDelta = m_pSbScroll->GetValue() - sDelta / GUI_MOUSE_WHEEL_DELTA;
    nDelta = max(0, min(nDelta, m_pSbScroll->GetMaxValue()));    

    m_pSbScroll->SetValue(nDelta);
}

VOID CWhoListGui::OnClickedBtnHelp( gui::CComponent* pComponent )
{
	CDboEventGenerator::OpenHelpContent(DIALOG_WHOSONLINE);
}

VOID CWhoListGui::OnTitleNameClicked( gui::CComponent* pComponent ) 
{
    static RwBool bAscentName = FALSE;
    bAscentName = !bAscentName;

    CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();  
    pFriendList->Sort(COMMUNITY_DATA_NAME, bAscentName);
    RefreshList();
}

VOID CWhoListGui::OnTitleLevelClicked( gui::CComponent* pComponent ) 
{
    static RwBool bAscentLevel = FALSE;
    bAscentLevel = !bAscentLevel;

    CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();  
    pFriendList->Sort(COMMUNITY_DATA_LEVEL, bAscentLevel);
    RefreshList();
}

VOID CWhoListGui::OnTitleLocClicked( gui::CComponent* pComponent ) 
{
    static RwBool bAscentLoc = FALSE;
    bAscentLoc = !bAscentLoc;

    CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();  
    pFriendList->Sort(COMMUNITY_DATA_LOC, bAscentLoc);
    RefreshList();

}

VOID CWhoListGui::OnTitleChannelClicked( gui::CComponent* pComponent ) 
{
    static RwBool bAscentChannel = FALSE;
    bAscentChannel = !bAscentChannel;

    CNtlSLFriendList* pFriendList = GetNtlSLGlobal()->GetSobAvatar()->GetFriendList();  
    pFriendList->Sort(COMMUNITY_DATA_CHANNEL, bAscentChannel);
    RefreshList();

}

