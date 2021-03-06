#include "precomp_shopedit.h"
#include <ddraw.h>
#include "ShopEditApplication.h"
#include "NtlDebug.h"
#include "NtlCharsetPrint.h"
#include "NtlText.h"
#include "NtlBitFlagManager.h"

#include "guicore_precomp.h"
#include "gui_precomp.h"
#include "gui_fontmanager.h"
#include "gui_renderer.h"
#include "GuiUtil.h"

#include "TableContainer.h"
#include "TableFileNameList.h"
#include "MerchantTable.h"
#include "NPCTable.h"
#include "TextAllTable.h"
CShopEditApplication * CShopEditApplication::m_pInstance = NULL;
#define FRIEND_LIST_X 21
#define FRIEND_LIST_Y 97
#define FRIEND_LIST_MARGIN 4
#define FRIEND_ITEM_WITH 274
#define FRIEND_ITEM_HEIGHT 19

#define FRIEND_ICON_X 15
#define FRIEND_ICON_Y 97
#define FRIEND_LEVEL_X 139
#define FRIEND_LEVE_WIDTH 30
#define FRIEND_LOC_X 177
#define FRIEND_LOC_WIDTH 62
#define FRIEND_CHANNEL_X 246
#define FRIEND_CHANNEL_WIDTH 48

#define FRIEND_ITEM_COLOR_ONLINE RGB(255, 255, 255)
#define FRIEND_ITEM_COLOR_OFFLINE RGB(180, 180, 180)
#define FRIEND_ITEM_COLOR_FOCUS RGB(255, 219, 71)

CShopEditApplication::CShopEditApplication() : m_pCharset(NULL)
{
	m_pInstance = this;
	m_pTableContainer = NULL;

	m_BackgroundColor.red   = 50;
	m_BackgroundColor.green = 50;
	m_BackgroundColor.blue  = 50;
	m_BackgroundColor.alpha = 0;

	m_ForegroundColor.red   = 255;
	m_ForegroundColor.green = 255;
	m_ForegroundColor.blue  = 255;
	m_ForegroundColor.alpha = 255;

	m_pCamera = NULL;
	m_pResMgr = 0;
	m_pSurMgr = 0;
	m_pCompMgr = 0;
	m_pGuiMgr = 0;

	m_fTime = 0.0f;

	m_bActiveBtn = FALSE;


}

CShopEditApplication::~CShopEditApplication()
{
	
}

RwBool CShopEditApplication::CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer)
{
	NTL_FUNCTION("CShopEditApplication::CreateSubSystem" );

	CNtlApplication::CreateSubSystem(iWidth, iHeight, zBuffer);

	// camera 
	m_pCamera = NTL_NEW CNtlCamera;
	if(!m_pCamera->Create(iWidth, iHeight, zBuffer, 1.f, 500.f))
	{
		NTL_RETURN(FALSE);
	}
	
	// character set
	m_pCharset = RtCharsetCreate(&m_ForegroundColor, &m_BackgroundColor);
    if( m_pCharset == NULL )
	{
		NTL_RETURN(FALSE);
	}	

	m_pResMgr = NTL_NEW gui::CResourceManager;
	m_pSurMgr = NTL_NEW gui::CSurfaceManager(m_pResMgr);	
	m_pCompMgr = NTL_NEW gui::CComponentManager;
	m_pGuiMgr = NTL_NEW gui::CGUIManager(CRectangle(0, 0, iWidth, iHeight));
	
	// Table
	m_pTableContainer = NTL_NEW CTableContainer;
	
	CNtlBitFlagManager flagManager;
	if (false == flagManager.Create(CTableContainer::TABLE_COUNT))
		return false;
	
	CTableFileNameList fileNameList;
	if (false == fileNameList.Create())
		return false;
	
	

	// gui setup
	gui::CSetupGUI::Init( GetHWnd(), iWidth, iHeight, m_pGuiMgr, "gui\\font\\GuiFont.def", "script\\metatag.htm", "gui\\font\\FlashFont.def" );

	m_pResMgr->AddPage("Gui\\GuiDevTest.rsr");
	m_strResPage = "Gui\\GuiDevTest.rsr";

	m_pResMgr->AddPage("Gui\\Human\\Game.rsr");
	m_strSkillResPage = "Gui\\Human\\Game.rsr";

	m_pSurMgr->AddPage("Gui\\GuiDevTest.srf");
	m_strSurPage = "Gui\\GuiDevTest.srf";

	m_pSurMgr->AddPage("Gui\\GameCommon.srf");
	m_strSurPage = "Gui\\GameCommon.srf";

	m_pSurMgr->AddPage("Gui\\wholist.srf");
	m_strSkillPage = "Gui\\wholist.srf";

	m_pSurMgr->AddPage("gui\\CommonNumber.srf");
	m_pSurMgr->AddPage("gui\\CommonNumber2.srf");
	m_pResMgr->AddPage("gui\\GlobalGui.rsr");
	
	m_pSurMgr->AddPage("gui\\globalgui.srf");
	m_pCompMgr->AddPage("Gui\\globalgui.frm");

	m_hCompPage = m_pCompMgr->AddPage("Gui\\wholist.frm");
	m_strCompPage = "Gui\\wholist.frm";


	m_pCompMgr->CreateComponents( m_hCompPage, m_pGuiMgr, m_pSurMgr );
	gui::CToolTip* pToolTip = new gui::CToolTip( CRectangle( 0, 0, 100, 100 ), m_pGuiMgr, m_pSurMgr );
	pToolTip->SetMouseMargin( 32, 32 );
	gui::GetGlobalComponent()->SetToolTip( pToolTip );


	//m_pInput->SetText( "sample.txt" );
	m_pThis = (gui::CDialog*)m_pCompMgr->GetComponent(m_hCompPage, "dlgMain");
	m_pSttDialogTitle = (gui::CStaticBox*)m_pCompMgr->GetComponent(m_hCompPage, "sttDialogTitle");
	m_pBtnClose = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnClose");
	m_pBtnTitleName = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnTitleName");
	m_pBtnTitleLevel = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnTitleLevel");
	m_pBtnTitleLoc = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnTitleLoc");
	m_pBtnTitleChannel = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnTitleChannel");
	m_pBtnAdd = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnAdd");
	m_pBtnParty = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnParty");
	m_pBtnMail = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnMail");
	m_pBtnWhisper = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnWhisper");
	m_pBtnBlock = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnBlock");
	m_pBtnDelete = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnDelete");
	m_pSbScroll = (gui::CScrollBar*)m_pCompMgr->GetComponent(m_hCompPage, "scbScroll");
	m_pBtnHelp = (gui::CButton*)m_pCompMgr->GetComponent(m_hCompPage, "btnHelp");
	CreateInfoStaticBox();
	
	CRectangle rect;
	char acBuffer[64] = "";

	rect.SetRectWH(DBOGUI_DIALOG_TITLE_X, DBOGUI_DIALOG_TITLE_Y, 145, 14);
	m_pSttDialogTitle = NTL_NEW gui::CStaticBox(rect, m_pThis, m_pSurMgr, COMP_TEXT_LEFT);
	m_pSttDialogTitle->CreateFontStd(DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);
	m_pSttDialogTitle->SetText(L"Who's Online");
	m_pSttDialogTitle->Enable(false);

	rect = GetPosition();


	m_pBtnTitleName->SetText("Name");
	m_pBtnTitleLevel->SetText("Level");
	m_pBtnTitleLoc->SetText("Area");
	m_pBtnTitleChannel->SetText("Guild");

	
	for (int i = 0; i < 13; ++i)
	{
		CRectangle rectIcon;
		// ¾ÆÀÌÄÜ »ý¼º
		rectIcon.left = FRIEND_ICON_X;
		rectIcon.right = rectIcon.left + 19;
		rectIcon.top = FRIEND_ICON_Y + i * (19 + FRIEND_LIST_MARGIN);
		rectIcon.bottom = rectIcon.top + 19;

		m_pPnlIcon[i] = NTL_NEW gui::CPanel(rectIcon, m_pThis, m_pSurMgr);
	}

	NTL_RETURN(TRUE);
}	

RwBool CShopEditApplication::AttachPlugin()
{
	NTL_FUNCTION( "CShopEditApplication::AttachPlugin" );

	if( !RpWorldPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RpCollisionPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RtAnimInitialize() )
		NTL_RETURN(FALSE);
	
	if( !RpHAnimPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RpSkinPluginAttach() )
		NTL_RETURN(FALSE);

	if ( !RpToonPluginAttach() )
		NTL_RETURN(FALSE);

	if( !RpUserDataPluginAttach() )
		NTL_RETURN(FALSE);

	if( !RpIdPluginAttach() )
		NTL_RETURN(FALSE);
	
	NTL_RETURN(TRUE);
}

RwBool CShopEditApplication::Resize(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer)
{
	NTL_FUNCTION("CShopEditApplication::Resize" );

	CNtlApplication::Resize(iWidth, iHeight, zBuffer, FALSE );

	if(m_pCamera != NULL)
	{
		if (m_pCamera->GetCamera())
		{
			if (iWidth == 0 || iHeight == 0)
			{
			}
			else
			{
				RwRect rt;
				rt.x = 0; rt.y = 0; rt.w = iWidth; rt.h = iHeight;
				m_pCamera->SetCameraSize(&rt); 				
			}
			NTL_RETURN(TRUE);
		}
		else
		{
			NTL_RETURN(FALSE);
		}
	}

	NTL_RETURN(TRUE);
}


LRESULT CShopEditApplication::PreTranslateMessage(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pGuiMgr)
        return m_pGuiMgr->Win32EventProc(window, message, wParam, lParam);
	else
		return 0;
}

RwBool CShopEditApplication::Update(RwReal fTime, RwReal fElapsedTime)
{
	NTL_FUNCTION("CShopEditApplication::Update" );

	CEventTimer::KeepAlive();
	
	m_fTime += fElapsedTime;

	if (RwCameraClear(m_pCamera->GetCamera(), &m_BackgroundColor, rwCAMERACLEARZ|rwCAMERACLEARIMAGE))
	{
		//Ready to render scene.
		if( RwCameraBeginUpdate(m_pCamera->GetCamera()) )
		{
			RwBlendFunction eSrcBlend;
			RwBlendFunction eDestBlend;

			RwD3D9SetTexture(NULL, 0);
			RwD3D9SetTexture(NULL, 1);

			RwD3D9SetTextureStageState (0, D3DTSS_COLOROP, D3DTOP_MODULATE); 
			RwD3D9SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE); 
			RwD3D9SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_DIFFUSE); 

			// stage 0 alpha : nada 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE); 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE); 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE); 

			RwRenderStateSet(rwRENDERSTATESHADEMODE, (void *)rwSHADEMODEGOURAUD);
			RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void *) NULL);
			RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void *) TRUE);
			RwRenderStateGet(rwRENDERSTATESRCBLEND, (void *)&eSrcBlend);
			RwRenderStateGet(rwRENDERSTATEDESTBLEND, (void *)&eDestBlend);
			RwRenderStateSet(rwRENDERSTATESRCBLEND, (void *)rwBLENDSRCALPHA);
			RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void *)rwBLENDINVSRCALPHA);

			// gui render
			g_GuiRenderer.ResetRender();

			if(m_pGuiMgr)
				m_pGuiMgr->Show();

			g_GuiRenderer.Render();

			RwD3D9SetTexture(NULL, 0);

			RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) TRUE);
			RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *) TRUE);
			RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void *) NULL);
			RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATESRCBLEND, (void *)eSrcBlend);
			RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void *)eDestBlend);

			DisplayInfo();

			RwCameraEndUpdate(RwCameraGetCurrentCamera());
		}

		RwCameraShowRaster(m_pCamera->GetCamera(), GetHWnd(), 0);
	}
	
	NTL_RETURN(TRUE);
}

void CShopEditApplication::Destroy()
{
	NTL_FUNCTION("CShopEditApplication::Destroy" );

	m_pCompMgr->DestroyComponents (m_hCompPage);
	m_pResMgr->RemovePage(m_strResPage);
	m_pResMgr->RemovePage(m_strSkillResPage);
	m_pSurMgr->RemovePage(m_strSurPage);
	m_pSurMgr->RemovePage(m_strSkillPage);
	m_pCompMgr->RemovePage(m_hCompPage);

	if(m_pGuiMgr)
	{
		NTL_DELETE(m_pGuiMgr);
	}

	if(m_pCompMgr)
	{
		NTL_DELETE(m_pCompMgr);
	}

	if(m_pSurMgr)
	{
		NTL_DELETE(m_pSurMgr);
	}

	if(m_pResMgr)
	{
		NTL_DELETE(m_pResMgr);
	}

	CEventListener_Win32::RemoveAll();

	// character set destroy
	if(m_pCharset)
    {
		RtCharsetClose();
		RwRasterDestroy(m_pCharset);
		m_pCharset = NULL;
    }
	
	// camera destroy
	if(m_pCamera)
	{
		m_pCamera->Destroy();
		NTL_DELETE(m_pCamera);
		m_pCamera = NULL;
	}

	// gui
	gui::CSetupGUI::Deinit();

	//
	CNtlApplication::Destroy();
	
	NTL_RETURNVOID();
}

void CShopEditApplication::DisplayInfo()
{
	RwChar caption[256];
	RwInt32 iIdx = 0;
	
	//fps
	RsSprintf(caption, RWSTRING("FPS: %4.2f"), GetFps());
	RsCharsetPrint(m_pCharset, caption, 0, iIdx++, rsPRINTPOSTOPRIGHT);
}

LRESULT CShopEditApplication::WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch( message )
	{
	case WM_KEYUP:
		{
			
		}
		break;
	default:
		break;
	}

	return CNtlApplication::WndProc(window, message, wParam, lParam);
}

VOID CShopEditApplication::OnBtnClick( gui::CComponent* pComponent )
{
	OnInputReturn();
}

VOID CShopEditApplication::OnInputReturn(VOID)
{

}


VOID CShopEditApplication::OnScrollChanged( RwInt32 nNewOffset )
{
}

VOID CShopEditApplication::OnCaptureWheelMove( RwInt32 nFlag, RwInt16 sDelta, CPos& pos )
{
}

VOID CShopEditApplication::OnResizeSkillCustomize( RwInt32 nOldWidth, RwInt32 nOldHeight )
{
}

VOID CShopEditApplication::OnActiveBtnClick( gui::CComponent* pComponent )
{

}

VOID CShopEditApplication::OnListToggledCbbTitle(RwBool bToggled, gui::CComponent* pComponent)
{
	if (bToggled)
	{
		pComponent->Raise();
	}
}

/**
* \brief Å¸ÀÌÆ² ¹öÆ°À» Å¬¸¯ÇÏ¿´À» °æ¿ì ( ÄÞº¸¹Ú½ºÀÇ Button )
*/
VOID CShopEditApplication::OnClickedBtnTitle(gui::CComponent* pComponent)
{

}

/**
* \brief ÄÞº¸¹Ú½º¸¦ ¼±ÅÃÇÏ¿´À» ¶§ ³¯¶ó¿À´Â ÄÝ¹é
* \param nIndex	(RwInt32) ¾ÆÀÌÅÛÀÇ ÀÎµ¦½º
*/
VOID CShopEditApplication::OnSelectNpc(RwInt32 nIndex)
{
	PopulateShopData(nIndex);
}


void CShopEditApplication::PopulateShopData(RwInt32 byIndex)
{
	
}

VOID CShopEditApplication::CreateInfoStaticBox()
{
	CRectangle rectLevel, rectLoc, rectChannel, rectJob, rectBackSpace, rectIcon;
	for (int i = 0; i < 13; ++i)
	{
		// ¹öÆ° ¹è°æ »ý¼º
		rectBackSpace.left = FRIEND_LIST_X;
		rectBackSpace.right = rectBackSpace.left + FRIEND_ITEM_WITH;
		rectBackSpace.top = FRIEND_LIST_Y + i * (FRIEND_ITEM_HEIGHT + FRIEND_LIST_MARGIN);
		rectBackSpace.bottom = rectBackSpace.top + FRIEND_ITEM_HEIGHT;

		m_pPnlBackSpace[i] = NTL_NEW gui::CPanel(rectBackSpace, m_pThis, m_pSurMgr, m_pSurMgr->GetSurface("wholist.srf", "srfBackSpace"));

		//// ¾ÆÀÌÄÜ »ý¼º
		//rectIcon.left = FRIEND_ICON_X;
		//rectIcon.right = rectIcon.left + 19;
		//rectIcon.top = FRIEND_ICON_Y + i * (19 + FRIEND_LIST_MARGIN);
		//rectIcon.bottom = rectIcon.top + 19;

		//m_pPnlIcon[i] = NTL_NEW gui::CPanel(rectIcon, m_pThis, GetNtlGuiManager()->GetSurfaceManager());

		// Info ¹öÆ°¹× °´Ã¼ »ý¼º
		rectLevel.left = FRIEND_LEVEL_X;
		rectLevel.right = FRIEND_LEVEL_X + FRIEND_LEVE_WIDTH;
		rectLoc.left = FRIEND_LOC_X;
		rectLoc.right = FRIEND_LOC_X + FRIEND_LOC_WIDTH;
		rectChannel.left = FRIEND_CHANNEL_X;
		rectChannel.right = FRIEND_CHANNEL_X + FRIEND_CHANNEL_WIDTH;

		rectLevel.top = rectLoc.top = rectChannel.top = FRIEND_LIST_Y + i * (FRIEND_ITEM_HEIGHT + FRIEND_LIST_MARGIN);
		rectLevel.bottom = rectLoc.bottom = rectChannel.bottom = rectLevel.top + FRIEND_ITEM_HEIGHT;

		m_pSttLevel[i] = NTL_NEW gui::CStaticBox(rectLevel, m_pThis, m_pSurMgr, COMP_TEXT_CENTER);
		m_pSttLoc[i] = NTL_NEW gui::CStaticBox(rectLoc, m_pThis, m_pSurMgr, COMP_TEXT_CENTER);
		m_pSttChannel[i] = NTL_NEW gui::CStaticBox(rectChannel, m_pThis, m_pSurMgr, COMP_TEXT_CENTER);

		m_pSttLevel[i]->CreateFontStd(DETAIL_FONT, 90, NULL);
		m_pSttLoc[i]->CreateFontStd(DETAIL_FONT, 90, NULL);
		m_pSttChannel[i]->CreateFontStd(DETAIL_FONT, 90, NULL);

		m_pSttLevel[i]->Clear();
		m_pSttLoc[i]->Clear();
		m_pSttChannel[i]->Clear();
	}
}

inline CRectangle CShopEditApplication::GetPosition()
{
	// ºÎ¸ð·ÎºÎÅÍÀÇ ±âÁØ ÁÂÇ¥¿Í ³ÐÀÌ, ³ôÀÌ¸¸À» Âü°íÇÏÀÚ
	CRectangle rtRect;

	rtRect.left = 0;
	rtRect.top = 0;
	rtRect.right = rtRect.left + m_iX_fromParent;
	rtRect.bottom = rtRect.top + m_iY_fromParent;

	return rtRect;
}