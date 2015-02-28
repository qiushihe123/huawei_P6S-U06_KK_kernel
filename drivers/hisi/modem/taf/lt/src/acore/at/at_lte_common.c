/******************************************************************************
/*
/*                  ��Ȩ���� (C), 1998-2009, ��Ϊ�������޹�˾
/*
/******************************************************************************
/*  �� �� ��   : at_lte_common.c
/*  �� �� ��   : V1.0
/*  ��    ��   : �޾�ǿ/00064416
/*  ��������   : 2011-03-10
/*  ��������   : AT��ܵ�ͨ�ô���
/*
/*  �����б�   : TODO: ...
/*  �޸���ʷ   :
/*  1.��    �� : 2011-03-10
/*    ��    �� : �޾�ǿ/00064416
/*    �޸����� : �����ļ�
/*
/******************************************************************************

/******************************************************************************
/* PROJECT   : MSP_CPV700R001C01
/* SUBSYSTEM : AT
/* MODULE    : LTE
/* OWNER     :
/******************************************************************************
#include "osm.h"
#include "gen_msg.h"
#include "msp_at.h"
#include "at_lte_common.h"
#include "ATCmdProc.h"

/*lint -e767 ԭ��:Log��ӡ*/
#define    THIS_FILE_ID        MSP_FILE_ID_AT_LTE_COMMON_C
/*lint +e767 */

/* ���ͻ�����
AT_SEND_DATA_BUFFER_STRU gstLAtSendData = {{0},};
VOS_UINT8 *pgucLAtSndCodeAddr = &gstLAtSendData.aucBuffer[2];


AT_ERROR_CODE_TABLE_STRU g_stErrCodeTable[] = {
    {APP_SUCCESS,                               AT_OK},
    {APP_FAILURE,                               AT_ERROR},
    {APP_ERR_CAPABILITY_ERROR,                  AT_CME_OPERATION_NOT_SUPPORTED},
    {APP_ERR_USIM_SIM_CARD_NOTEXIST,            AT_CME_SIM_NOT_INSERTED},
    {APP_ERR_NEED_PIN1,                         AT_CME_SIM_PIN_REQUIRED},
    {APP_ERR_NEED_PUK1,                         AT_CME_SIM_PUK_REQUIRED},
    {APP_ERR_USIM_SIM_INVALIDATION,             AT_CME_SIM_FAILURE},
    {APP_ERR_ID_INVALID,                        AT_CME_INVALID_INDEX},
    {APP_ERR_TIME_OUT,                          AT_CME_NETWORK_TIMEOUT},
    {APP_ERR_PARA_ERROR,                        AT_CME_INCORRECT_PARAMETERS},
    {APP_ERR_NULL_PTR,                          AT_CME_INCORRECT_PARAMETERS},
    {APP_ERR_NUM_VALUE_INVALID,                 AT_CME_INCORRECT_PARAMETERS},
    {APP_ERR_NUM_LEN_INVALID,                   AT_CME_INCORRECT_PARAMETERS},

    /* ���Ŵ���
    {APP_ERR_SM_APN_LEN_ILLEGAL,                AT_CME_APN_LEN_ILLEGAL},
    {APP_ERR_SM_APN_SYNTACTICAL_ERROR,          AT_CME_APN_SYNTACTICAL_ERROR},
    {APP_ERR_SM_SET_APN_BEFORE_SET_AUTH,        AT_CME_SET_APN_BEFORE_SET_AUTH},
    {APP_ERR_SM_AUTH_TYPE_ILLEGAL,              AT_CME_AUTH_TYPE_ILLEGAL},
    {APP_ERR_SM_USER_NAME_TOO_LONG,             AT_CME_USER_NAME_TOO_LONG},
    {APP_ERR_SM_USER_PASSWORD_TOO_LONG,         AT_CME_USER_PASSWORD_TOO_LONG},
    {APP_ERR_SM_ACCESS_NUM_TOO_LONG,            AT_CME_ACCESS_NUM_TOO_LONG},
    {APP_ERR_SM_CALL_CID_IN_OPERATION,          AT_CME_CALL_CID_IN_OPERATION},
    {APP_ERR_SM_BEARER_TYPE_NOT_DEFAULT,        AT_CME_BEARER_TYPE_NOT_DEFAULT},
    {APP_ERR_SM_CALL_CID_INVALID,               AT_CME_CALL_CID_INVALID},
    {APP_ERR_SM_CALL_CID_ACTIVE,                AT_CME_CALL_CID_ACTIVE},
    {APP_ERR_SM_BEARER_TYPE_ILLEGAL,            AT_CME_BEARER_TYPE_ILLEGAL},
    {APP_ERR_SM_MUST_EXIST_DEFAULT_TYPE_CID,    AT_CME_MUST_EXIST_DEFAULT_TYPE_CID},
    {APP_ERR_SM_PDN_TYPE_ILLEGAL,               AT_CME_PDN_TYPE_ILLEGAL},
    {APP_ERR_SM_IPV4_ADDR_ALLOC_TYPE_ILLEGAL,   AT_CME_IPV4_ADDR_ALLOC_TYPE_ILLEGAL},
    {APP_ERR_SM_LINK_CID_INVALID,               AT_CME_LINK_CID_INVALID},

    /* NV ERROR CODE
    {ERR_MSP_NV_NOT_SUPPORT_ID,         AT_DEVICE_NV_NOT_SUPPORT_ID},
    {ERR_MSP_NV_ERROR_READ,             AT_DEVICE_NV_READ_FAILURE},
    {ERR_MSP_NV_NOT_SUPPORT_LENTH,      AT_DEVICE_NV_WRITE_FAIL_OVERLEN},
    {ERR_MSP_NV_BAD_BLOCK,              AT_DEVICE_NV_WRITE_FAIL_BADFLASH},
    {ERR_MSP_NV_ERROR_WRITE,            AT_DEVICE_NV_WRITE_FAIL_UNKNOWN},
    /* װ�� ERROR CODE
    {ERR_MSP_SUCCESS,                   AT_OK},
    {ERR_MSP_FAILURE,                   AT_ERROR},
    {ERR_MSP_NOT_EXIST,                 AT_DEVICE_NOT_SUPPORT},
    {ERR_MSP_UNKNOWN,                   AT_DEVICE_ERR_UNKNOWN},
    {ERR_MSP_INVALID_PARAMETER,         AT_DEVICE_INVALID_PARAMETERS},
    {ERR_MSP_VCTCXO_OVER_HIGH,          AT_DEVICE_VCTCXO_OVER_HIGH},
    {ERR_MSP_UE_MODE_ERR,               AT_DEVICE_UE_MODE_ERR},
    {ERR_MSP_NOT_SET_CHAN,              AT_DEVICE_NOT_SET_CHAN},
    {ERR_MSP_OPEN_RFTX_ERROR,           AT_DEVICE_OPEN_UL_CHAN_ERROR},
    {ERR_MSP_OPEN_RFRX_ERROR,           AT_DEVICE_OPEN_DL_CHAN_ERROR},
    {ERR_MSP_OPEN_CHAN_ERROR,           AT_DEVICE_OPEN_CHAN_ERROR},
    {ERR_MSP_CLOSE_CHAN_ERROR,          AT_DEVICE_CLOSE_CHAN_ERROR},
    {ERR_MSP_NOT_SUPPORT,               AT_DEVICE_OPERATION_NOT_SUPPORT},
    {ERR_MSP_INVALID_OP,                AT_DEVICE_INVALID_OP},
    {ERR_MSP_ENTER_BAND_ERROR,          AT_DEVICE_CHAN_BAND_INVALID},
    {ERR_MSP_SET_CHAN_INFOR_ERROR,      AT_DEVICE_SET_CHAN_INFO_FAILURE},
    {ERR_MSP_FRE_CHANI_NOTMATCH,        AT_DEVICE_CHAN_BAND_CHAN_NOT_MAP},
    {ERR_MSP_SET_TX_POWER_FAILUE,       AT_DEVICE_SET_TX_POWER_FAILURE},
    {ERR_MSP_SET_PA_LEVEL_FAILUE,       AT_DEVICE_SET_PA_LEVEL_FAILURE},
    {ERR_MSP_NOT_SET_CURRENT_CHAN,      AT_DEVICE_NOT_SET_CURRENT_CHAN},
    {ERR_MSP_NOT_ABLETO_RD_APC,         AT_DEVICE_CUR_APC_UNAVAILABLE},
    {ERR_MSP_SET_APC_ERROR,             AT_DEVICE_SET_APC_ERR},
    {ERR_MSP_RD_APC_ERROR,              AT_DEVICE_RD_APC_ERR},
    {ERR_MSP_SET_LINA_ERROR,            AT_DEVICE_SET_LNA_ERR},
    {ERR_MSP_NOT_OPEN_RXRX,             AT_DEVICE_NOT_OPEN_DL_CHAN},
    {ERR_MSP_NOT_OPEN_RXTX,             AT_DEVICE_NOT_OPEN_UL_CHAN},
    {ERR_MSP_NO_SIGNAL,                 AT_DEVICE_NO_SIGNAL},
    {ERR_MSP_PHYNUM_LENGTH_ERROR,       AT_DEVICE_PHYNUM_LEN_ERR},
    {ERR_MSP_PHYNUM_INVALID,            AT_DEVICE_PHYNUM_INVALID},
    {ERR_MSP_PHYNUM_TYPE_ERROR,         AT_DEVICE_PHYNUM_TYPE_ERR},
    {ERR_MSP_PLATINFOR_NOTABLE_TORD,    AT_DEVICE_PLATFORM_INFO_UNAVAILABLE},
    {ERR_MSP_WRT_NOT_UNLOCK,            AT_DEVICE_DATA_LOCK},
    {ERR_MSP_CALLNUM_OVER20,            AT_DEVICE_PLMN_OVER_20},
    {ERR_MSP_MNC_ENTER_OVERFLOW,        AT_DEVICE_MNC_NUM_INVALID},
    {ERR_MSP_RD_VER_FAILUE,             AT_DEVICE_GET_VER_ERR},
    {ERR_MSP_OPERTION_ERROR,            AT_DEVICE_PORTLOCK_ERR},
    {ERR_MSP_PWD_ERR,                   AT_DEVICE_PWD_ERR},
    {ERR_MSP_TIME_OUT,                  AT_DEVICE_TIMEOUT_ERR},
    {ERR_MSP_NO_MORE_MEMORY,            AT_DEVICE_NOT_ENOUGH_MEMORY},
    {ERR_MSP_SIMM_LOCK,                 AT_DEVICE_SIMM_LOCK},
    {ERR_MSP_CLOSE_RFTX_ERROR,          AT_DEVICE_CLOSE_UL_CHAN_FAILURE},
    {ERR_MSP_CLOSE_RFRX_ERROR,          AT_DEVICE_CLOSE_DL_CHAN_FAILURE},
    {ERR_MSP_NV_DATA_INVALID,           AT_DEVICE_NV_DATA_INVALID},

};


/******************************************************************************
/* ��������: atChgErrorCode
/* ��������: ������ģ�鷵�صĴ�����ת����AT�Ĵ�����
/*
/* ����˵��:
/*   usTafErrorCode [in] ������
/*
/* �� �� ֵ:
/*    ����AT�Ĵ�����
/*
/* ����Ҫ��: TODO: ...
/* ���þ���: TODO: ...
/* ��    ��: �޾�ǿ/00064416 [2009-08-11]
/******************************************************************************
static VOS_UINT32 ChgErrorCode(VOS_UINT32 usTafErrorCode)
{
    VOS_UINT32 ulRtn = AT_CME_UNKNOWN;
    VOS_UINT32 i = 0;
    VOS_UINT32 ulErrNum = sizeof(g_stErrCodeTable)/sizeof(AT_ERROR_CODE_TABLE_STRU);

    for(i = 0; i < ulErrNum; i++)
    {
        if(usTafErrorCode == g_stErrCodeTable[i].ulSrcError)
        {
            ulRtn = g_stErrCodeTable[i].ulATError;

            return ulRtn;
        }
    }

    return AT_ERROR;
}



/******************************************************************************
/* ��������: CmdErrProc
/* ��������: ������ת����AT�ظ��ϱ�
/*
/* ����˵��:
/*   ucClientId [in] �ͻ���ID
/*   ulErrCode [in]  ������
/*   usBufLen [in]   �ظ���Ϣ
/*   pucBuf [in]     �ظ���Ϣ����
/*
/* �� �� ֵ:
/*    ��
/*
/* ����Ҫ��: TODO: ...
/* ���þ���: TODO: ...
/* ��    ��: �޾�ǿ/00064416 [2009-08-11]
/******************************************************************************
VOS_VOID CmdErrProc(VOS_UINT8 ucClientId, VOS_UINT32 ulErrCode, VOS_UINT16 usBufLen, VOS_UINT8* pucBuf)
{
    VOS_UINT32 ulResult = 0;

    gstAtSendData.usBufLen = usBufLen;
    if(NULL != pucBuf)
    {
        /*MSP_MEMCPY(gstAtSendData.aucBuffer, pucBuf, usBufLen);
        /*�ĳ��������ƥ�亯�� At_FormatResultData
        MSP_MEMCPY(pgucAtSndCodeAddr, pucBuf, usBufLen);
    }

    if(ERR_MSP_SUCCESS != ulErrCode)
    {
        ulResult = ChgErrorCode(ulErrCode);

        At_FormatResultData(ucClientId, ulResult);
    }
    else
    {
        At_FormatResultData(ucClientId, AT_OK);
    }

    return ;
}


/******************************************************************************
/* ��������: atSendFtmDataMsg
/* ��������: ATģ���FTM ģ�鷢����Ϣ
/*
/* ����˵��:
/*   TaskId [in] ����PID
/*   MsgId  [in] ��ϢID
/*   ulClientId [in] �˿ں�
/*   pData  [in] ������ʼ
/*   uLen   [in] ���ݳ���
/* �� �� ֵ:
/*    ERR_MSP_SUCCESS�ɹ�
/*    ��ERR_MSP_SUCCESSʧ��
/* ��    ��: lwx26324 [20110927]
/******************************************************************************
VOS_UINT32 atSendFtmDataMsg(VOS_UINT32 TaskId, VOS_UINT32 MsgId, VOS_UINT32 ulClientId, VOS_VOID* pData, VOS_UINT32 uLen)
{
    VOS_UINT32 u32Ret = ERR_MSP_UNKNOWN;
    AT_FW_DATA_MSG_STRU* pMsgBlock = NULL;

    pMsgBlock = (AT_FW_DATA_MSG_STRU*)VOS_AllocMsg(WUEPS_PID_AT,(sizeof(AT_FW_DATA_MSG_STRU)+ uLen - 20));

    if (pMsgBlock)
    {
        pMsgBlock->ulReceiverPid = TaskId;
        pMsgBlock->ulSenderPid   = WUEPS_PID_AT;
        pMsgBlock->ulLength      = sizeof(AT_FW_DATA_MSG_STRU)+ uLen - 20;
        pMsgBlock->ulMsgId      = MsgId;
        pMsgBlock->ulClientId   = ulClientId;
        pMsgBlock->ulLen        = uLen;

        MSP_MEMCPY(pMsgBlock->pContext, pData, uLen);

        u32Ret = VOS_SendMsg(pMsgBlock->ulSenderPid, pMsgBlock);

        if (u32Ret == VOS_OK)
        {
            u32Ret = ERR_MSP_SUCCESS;
        }
    }

    return u32Ret;
}


/*****************************************************************************
 �� �� ��  : atSendFtmDataMsg
 ��������  : AT������ģ�鷢����Ϣ
 �������  : VOS_UINT32 TaskId
             VOS_UINT32 MsgId
             VOS_UINT32 ulClientId
             IN VOS_VOID* pData
             VOS_UINT32 uLen
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��8��25��
    ��    ��   : c64416
    �޸�����   : �����ɺ���
  1.��    ��   : 2013��6��6��
    ��    ��   : c64416
VOS_UINT32 atSendDataMsg(VOS_UINT32 TaskId, VOS_UINT32 MsgId, VOS_VOID* pData, VOS_UINT32 uLen)
{
    VOS_UINT32 u32Ret = 0;
    L4A_COMM_REQ_STRU* pMsgBlock;

    pMsgBlock = (L4A_COMM_REQ_STRU *)VOS_AllocMsg(WUEPS_PID_AT, (uLen - VOS_MSG_HEAD_LENGTH));

    if (pMsgBlock)
    {
        MSP_MEMCPY(pMsgBlock, pData, uLen);
        pMsgBlock->ulSenderPid      = WUEPS_PID_AT;
        pMsgBlock->ulLength         = (uLen - VOS_MSG_HEAD_LENGTH);
        pMsgBlock->enMsgId          = MsgId;

        u32Ret = VOS_SendMsg(pMsgBlock->ulSenderPid, pMsgBlock);
    }

    return u32Ret;
}

/* ������LTE��TDS˽��AT���� */

        
        
        (VOS_UINT8*)"^LWCLASH",    VOS_NULL_PTR},
    
    /*begin_added by c64416 for lte wifi 20131013*/
    {AT_CMD_ISMCOEX,
    VOS_NULL_PTR,           AT_NOT_SET_TIME,
    AT_CME_INCORRECT_PARAMETERS, CMD_TBL_NO_LIMITED,
    (VOS_UINT8*)"^ISMCOEX",    (VOS_UINT8*)"(@bw),(@bw),(@bw),(@bw),(@bw),(@bw)"}
    /*end_added by c64416 for lte wifi 20131013*/
};


 �� �� ��  : At_RegisterTLCmdTable
 ��������  : ��AT������ע��TDS/LTEר�������
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 �޸���ʷ  :


{
   
