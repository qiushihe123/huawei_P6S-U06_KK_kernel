/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : drv_config.h
  �� �� ��   : ����
  ��    ��   : Ԭ�� 00145322
  ��������   : 2013��11��19��
  ����޸�   :
  ��������   : drv_config.h ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��11��19��
    ��    ��   : Ԭ�� 00145322
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __DRV_CONFIG_H__
#define __DRV_CONFIG_H__


/******************************** SRAM-OFF�ڴ��������ڴ�滮*********************************/
/*SRAM-OFF�����ڴ���ʼ��ַ*/
#define CONFIG_DATA_BASE               (MEMORY_AXI_CONFIG_ADDR)

#define CONFIG_MBFULLMNTN_ADDR         (CONFIG_DATA_BASE) 
#define CONFIG_MBFULLMNTN_SIZE         (0x1)   

#define CONFIG_NOC_ERRLOG_ADDR         (CONFIG_MBFULLMNTN_ADDR + CONFIG_MBFULLMNTN_SIZE) 
#define CONFIG_NOC_ERRLOG_SIZE         (0x1)  

#define CONFIG_CCPU_GPIO_INT_GROUP     (CONFIG_NOC_ERRLOG_ADDR + CONFIG_NOC_ERRLOG_SIZE)
#define CONFIG_CCPU_GPIO_INT_SIZE      (0x1)

#define CONFIG_LOAD_DDR_ADDR          (CONFIG_CCPU_GPIO_INT_GROUP + CONFIG_CCPU_GPIO_INT_SIZE)
#define CONFIG_LOAD_DDR_SIZE         (0x1)

#define CONFIG_LOAD_PORT_ADDR          (CONFIG_LOAD_DDR_ADDR + CONFIG_LOAD_DDR_SIZE) 
#define CONFIG_LOAD_PORT_SIZE         (0x1)  

#define CONFIG_LOAD_PORT_IDMASK_ADDR         (CONFIG_LOAD_PORT_ADDR + CONFIG_LOAD_PORT_SIZE) 
#define CONFIG_LOAD_PORT_IDMASK_SIZE         (0x4)  

#define CONFIG_LOAD_DDR_SINGLE_PORT_ADDR         (CONFIG_LOAD_PORT_IDMASK_ADDR + CONFIG_LOAD_PORT_IDMASK_SIZE)
#define CONFIG_LOAD_DDR_SINGLE_PORT_SIZE         (0x1)

#define CONFIG_IS_SDCARD_EXIST_ADDR        (CONFIG_LOAD_DDR_SINGLE_PORT_ADDR + CONFIG_LOAD_DDR_SINGLE_PORT_SIZE)
#define CONFIG_IS_SDCARD_EXIST_SIZE        (0x1)
#endif
