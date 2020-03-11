#pragma once

// core
#include "ceventhandler.h"

// presentation
#include "NtlPLGui.h"

// dbo
#include "Windowby3.h"
#include "SideIconGui.h"
#include "DBOEvent.h"
    
/**
 * \ingroup Client
 * \brief HLS ������ ǥ���ϴ� Side View
 *
 * \date 2009-04-20
 * \author agebreak
 */
class CHLSSideViewGui : public CSideViewBase, public RWS::CEventHandler
{
public:
    enum EHLSSideViewHeight
    {
        HLS_SIDEVIEW_HEIGHT_NORMAL = 60,
        HLS_SIDEVIEW_HEIGHT_PCBANG = 140,
        HLS_SIDEVIEW_HEIGHT_NFY    = 60,
    };

public:
    CHLSSideViewGui(const RwChar* pName);
    virtual ~CHLSSideViewGui(void);

    RwBool		Create();
    VOID		Destroy();
    VOID		Update(RwReal fElapsed);

    virtual VOID	OnPressESC();
    virtual VOID	OnSideViewOpen(const void* pData);
    virtual VOID	OnSideViewClose();
    virtual VOID	OnSideViewLocate(const CRectangle& rectSideIcon);	

protected:
    virtual VOID	HandleEvents( RWS::CMsg &msg );
    VOID			LocateComponent();
    VOID			OnMove(RwInt32 iOldX, RwInt32 iOldY);
    VOID			OnResize( RwInt32 iOldW, RwInt32 iOldH );
    VOID			OnPaint();

   // VOID            SetState(eHLSSideViewType type);
    VOID            OnShowInfo();           ///< ���� HLS ������ ����Ѵ�
    VOID            OnShowNotify();         ///< HLS ���� ������ ����Ѵ�. 

protected:
    CWindowby3			m_BackPanel;		///< ���
   // eHLSSideViewType  m_type;             ///< ���� �������� Ÿ��

    gui::CSlot			m_slotPaint;
    gui::CSlot			m_slotMove;
    gui::CSlot			m_slotResize;

    // ���� HLS ����
    gui::CStaticBox*    m_pstbRemainTimeTitle;
    gui::CStaticBox*    m_pstbRemainTimeData;    
    gui::CStaticBox*    m_pstbGetTitle;
    gui::CStaticBox*    m_pstbGetData;    
    gui::CStaticBox*    m_pstbCurrentTitle;
    gui::CStaticBox*    m_pstbCurrentData;   

    // HLS ȹ�� ����
    gui::CStaticBox*    m_pstbGetPoint;

   // SDboEventUpdateHLS m_UpdateHLSInfo;                 ///< ������ ���� ���� HLS ������Ʈ ����
    DWORD                m_dwUpdateHLSPoint;              ///< ȹ�� ����Ʈ
    RwReal               m_fRemainTime;                     ///< ���� HLS ȹ������� ���� �ð�
    RwReal               m_fNotifyShowTime;                 ///< Notify ǥ�� �ð�    
    RwBool               m_bIsPCBang;                       ///< PC�������� �Ǵ��Ѵ�.
};
