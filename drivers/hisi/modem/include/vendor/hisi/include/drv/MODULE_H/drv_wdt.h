/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : drv_wdt.h
  �� �� ��   : ����
  ��    ��   : ���׳� d00209607
  ��������   : 2013��2��2��
  ����޸�   :
  ��������   : drv_wdt.h ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��2��2��
    ��    ��   : ���׳� d00209607
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __DRV_WDT_H__
#define __DRV_WDT_H__
#include "drv_global.h"
#if defined(BSP_CORE_MODEM) || defined(PRODUCT_CFG_CORE_TYPE_MODEM)

/*****************************************************************************
* �� �� ��  : BSP_WDT_Init
*
* ��������  : ��ʼ�����ƿ��Ź������ó�ʱʱ�䣬�ҽ��жϷ�����
*
* �������  : wdtId         ���Ź�ID,оƬ�ṩ1�����Ź���ID����Ϊ0
*             wdtTimeOuts   ���Ź���ʱʱ�䣬��λ��,ʱ������ܳ���51��
*
* �������  : ��
*
* �� �� ֵ  : OK& ERROR
*
* �޸ļ�¼ :  2009��3��5��  v1.00  wangxuesong  ����
*****************************************************************************/
BSP_S32 BSP_WDT_Init(BSP_U8 wdtId , BSP_U32 wdtTimeOuts);
#define DRV_WDT_INIT(wdtId,wdtTimeOuts)      BSP_WDT_Init(wdtId,wdtTimeOuts)

/*****************************************************************************
* �� �� ��  : BSP_WDT_EnableWdt
*
* ��������  : �������Ź�
*
* �������  : wdtId  ���Ź�ID
*
* �������  : ��
*
* �� �� ֵ  : OK& ERROR
*
* �޸ļ�¼ :  2009��3��5��  v1.00  wangxuesong  ����
*****************************************************************************/
BSP_S32 BSP_WDT_Enable(BSP_U8 wdtId);
#define DRV_WDT_ENABLE(wdtId)    BSP_WDT_Enable(wdtId)

/*****************************************************************************
* �� �� ��  : BSP_WDT_Disable
*
* ��������  : �رտ��Ź�
*
* �������  : wdtId  ���Ź�ID
*
* �������  : ��
*
* �� �� ֵ  : OK& ERROR
*
* �޸ļ�¼ :  2009��3��5��  v1.00  wangxuesong  ����
*****************************************************************************/
BSP_S32 BSP_WDT_Disable(BSP_U8 wdtId);
#define DRV_WDT_DISABLE(wdtId)    BSP_WDT_Disable(wdtId)
#endif

/*****************************************************************************
* �� �� ��  : BSP_WDT_HardwareFeed
*
* ��������  : ���ÿ��Ź������Ĵ�����ι����
*
* �������  : wdtId  ���Ź�ID
*
* �������  : ��
*
* �� �� ֵ  : OK& ERROR
*
* �޸ļ�¼ :  2009��3��5��  v1.00  wangxuesong  ����
*****************************************************************************/
BSP_S32 BSP_WDT_HardwareFeed(BSP_U8 wdtId);
#define DRV_WDT_FEED(wdtId)    BSP_WDT_HardwareFeed(wdtId)

/*****************************************************************************
 �� �� ��  : BSP_ClearZSPWatchDogInt
 ��������  : ���һ��ZSP WatchDog���ж�
 �������  : �ޡ�
 �������  : ��
 �� �� ֵ  : �ж��Ƿ���Ҫ����
*****************************************************************************/
extern BSP_BOOL BSP_ClearZSPWatchDogInt(BSP_VOID);
#define DRV_CLEAR_ZSPDOG_INT()   BSP_ClearZSPWatchDogInt()

/*****************************************************************************
 �� �� ��  : BSP_ClearHIFIWatchDogInt
 ��������  : ���һ��HIFI WatchDog���ж�
 �������  : �ޡ�
 �������  : ��
 �� �� ֵ  : �ж��Ƿ���Ҫ����
*****************************************************************************/
extern BSP_BOOL BSP_ClearHIFIWatchDogInt(BSP_VOID);
#define DRV_CLEAR_HIFIDOG_INT()   BSP_ClearHIFIWatchDogInt()

/*****************************************************************************
 �� �� ��  : BSP_ZspWatchDogIntEnalbe
 ��������  : ʹ��һ��ZSP WatchDog���ж�
 �������  : �ޡ�
 �������  : ��
 �� �� ֵ  : �ж��Ƿ���Ҫ����
*****************************************************************************/
extern BSP_VOID BSP_ZSPWatchDogIntEnalbe(int level);
#define DRV_ZSPDOG_INT_ENABLE(level) BSP_ZSPWatchDogIntEnalbe(level)

/*****************************************************************************
 �� �� ��  : BSP_ZspWatchDogIntEnalbe
 ��������  : ʹ��һ��ZSP WatchDog���ж�
 �������  : �ޡ�
 �������  : ��
 �� �� ֵ  : �ж��Ƿ���Ҫ����
*****************************************************************************/
extern BSP_VOID BSP_HIFIWatchDogIntEnalbe(int level);
#define DRV_HIFIDOG_INT_ENABLE(level) BSP_HIFIWatchDogIntEnalbe(level)

#endif
