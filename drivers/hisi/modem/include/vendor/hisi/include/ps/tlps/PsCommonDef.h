/******************************************************************************


        Copyright(C)2011,Hisilicon Co. LTD.

 ******************************************************************************
    File name   : PsCommonDef.h
    Description : Э��ջ�ڴ洦������Ϣ����ʱ���Ƚӿڷ�װ
    History     :
      1.  Draft  2011-04-21 �������
******************************************************************************/


#ifndef __PSCOMMONDEF_H__
#define __PSCOMMONDEF_H__


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include "vos.h"
#include "v_timer.h"

#ifdef _lint
/* PCLINT������뿪�أ�ֻ��PCLINTʱ�� */
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#endif

#ifdef __RECUR_TEST__                                                           /* _H2ASN_Skip */
#include "RecurTest.h"                                                          /* _H2ASN_Skip */
#endif                                                                          /* _H2ASN_Skip */

/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  #pragma pack(*)    �����ֽڶ��뷽ʽ
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 macro
*****************************************************************************/
#define PS_SUBMOD_NULL 0


/* �ڴ������װ */
#ifdef _lint

#define PS_MEM_CPY(pDestBuffer,pSrcBuffer,Count)            memcpy(pDestBuffer, pSrcBuffer, Count)

#define PS_MEM_CMP(pDestBuffer,pSrcBuffer,Count)            memcmp(pDestBuffer,pSrcBuffer, Count )

/*�ڴ��������궨��*/
#define PS_MEM_SET(pBuffer,ucData,Count)                    memset(pBuffer, ucData, Count)

/*�ڴ��ƶ��궨��*/
#define PS_MEM_MOVE(pDestBuffer,pSrcBuffer,ulBufferLen)     memmove(pDestBuffer, pSrcBuffer, ulBufferLen)

/*������Ϣ��,����ĳ��Ȱ�����Ϣ��ͷ����*/
#define PS_ALLOC_MSG_WITH_HEADER_LEN(ulPid , ulLen)         malloc(ulLen)

/*������Ϣ��,����ĳ��Ȳ�������Ϣ��ͷ����*/
#define PS_ALLOC_MSG(ulPid , ulLen)                         malloc((ulLen) + VOS_MSG_HEAD_LENGTH)

/*��Ϣ����*/
#ifdef LINUX_PC_LINT
#define PS_SEND_MSG(ulPid, pMsg)                            (free(pMsg), ulPid) 

#else
#define PS_SEND_MSG(ulPid, pMsg)                            /*lint -e10 -e58 -e64 -e144 */ free(pMsg) \ /*lint +e10 +e58 +e64 +e144 */

#endif

/*��Ϣ����,����PS_POST_MSG֮��,��Ҫʹ������ʾ���ͷ���Ϣ��,������ﲻ����ת����Ϊfree*/
#define PS_POST_MSG(ulPid, pMsg)                            VOS_PostMsg( ulPid, pMsg )

/*��Ϣ����*/
#ifdef LINUX_PC_LINT
#define PS_SEND_URGENT_MSG(ulPid, pMsg)                     (free(pMsg), ulPid) 

#else
#define PS_SEND_URGENT_MSG(ulPid, pMsg)                     /*lint -e10 -e58 -e64 -e144 */ free(pMsg) \ /*lint +e10 +e58 +e64 +e144 */

#endif

/*��Ϣ�ͷź궨��*/
#ifdef LINUX_PC_LINT
#define PS_FREE_MSG(ulPid, pMsg)                            (free(pMsg), ulPid) 

#else
#define PS_FREE_MSG(ulPid, pMsg)                            /*lint -e10 -e58 -e64 -e144 */ free(pMsg) \ /*lint +e10 +e58 +e64 +e144 */

#endif

/*�ڴ�����궨��*/
#define PS_MEM_ALLOC(ulPid , ulSize)                        malloc(ulSize)

/*�ڴ��ͷź궨��*/
#ifdef LINUX_PC_LINT
#define PS_MEM_FREE(ulPid, pAddr )                          (free(pAddr), ulPid)

#else
#define PS_MEM_FREE(ulPid, pAddr )                          /*lint -e10 -e58 -e64 -e144 */ free(pAddr) \ /*lint +e10 +e58 +e64 +e144 */

#endif

/*���뾲̬�ڴ�궨��*/
#define PS_ALLOC_STATIC_MEM(ulPid , ulSize)                 malloc(ulSize)

/*�ͷž�̬�ڴ�궨��*/
#ifdef LINUX_PC_LINT
#define PS_FREE_STATIC_MEM(ulPid, pAddr )                   (free(pAddr), ulPid)

#else
#define PS_FREE_STATIC_MEM(ulPid, pAddr )                   /*lint -e10 -e58 -e64 -e144 */ free(pAddr) \ /*lint +e10 +e58 +e64 +e144 */

#endif

/*zhengjunyan add for PC_Lint 2011-06-14 begin*/
/* �ڴ濽�� */
#define PS_MEM_CPY_ALL_CHECK(pucDestBuffer, pucSrcBuffer, ulBufferLen) \
             VOS_MemCpy( pucDestBuffer, pucSrcBuffer, ulBufferLen )

/*�ڴ��������궨��*/
#define PS_MEM_SET_ALL_CHECK(pucBuffer, ucData, ulBufferLen) \
             VOS_MemSet( pucBuffer, ucData, ulBufferLen )

/*�ڴ��ƶ��궨��*/
#define PS_MEM_MOVE_ALL_CHECK(pucDestBuffer, pucSrcBuffer, ulBufferLen) \
             VOS_MemMove( pucDestBuffer, pucSrcBuffer, ulBufferLen )

/*�ڴ�����*/
#define PS_ALLOC_MSG_ALL_CHECK(ulPid , ulLen)  \
            VOS_AllocMsg( ulPid, (ulLen)-(VOS_MSG_HEAD_LENGTH) )


/*zhengjunyan add for PC_Lint 2011-06-14 end*/

/*Modified by dongying for UT,2010-2-1,begin*/
#elif defined(PS_UT_SWITCH)|| defined(_GAS_UT_SWITCH_)
#include "stdlib.h"

#define PS_MEM_CPY(pDestBuffer,pSrcBuffer,Count)            memcpy(pDestBuffer, pSrcBuffer, Count)
#define PS_MEM_SET(pBuffer,ucData,Count)                    memset(pBuffer, ucData, Count)
#define PS_ALLOC_MSG(ulPid , ulLen)                         malloc((ulLen) + VOS_MSG_HEAD_LENGTH)
/* pengzhipeng add for clear define start*/
#define PS_ALLOC_MSG_WITH_HEADER_LEN(ulPid , ulLen)         malloc(ulLen)
#define PS_POST_MSG(ulPid, pMsg)                            VOS_PostMsg(ulPid,pMsg)
/* pengzhipeng add for clear define end*/
#define PS_SEND_MSG(ulPid, pMsg)                            free(pMsg)
#define PS_MEM_FREE(ulPid, pAddr )                          free(pAddr)
#define PS_MEM_ALLOC(ulPid , ulSize)                        malloc(ulSize)
#define PS_FREE_MSG(ulPid, pMsg)                            free(pMsg)
#define PS_FREE_STATIC_MEM(ulPid, pAddr )                   free(pAddr)
#define PS_MEM_CMP(pDestBuffer,pSrcBuffer,Count)            memcmp(pDestBuffer,pSrcBuffer, Count )
#define PS_MEM_MOVE(pDestBuffer,pSrcBuffer,ulBuffLen)       memmove(pDestBuffer,pSrcBuffer,ulBuffLen)

#else
/*Modified by dongying for UT,2010-2-1,end*/
/*�ڴ濽���궨��*/
#define PS_MEM_CPY(pucDestBuffer, pucSrcBuffer, ulBufferLen) \
             VOS_MemCpy( pucDestBuffer, pucSrcBuffer, ulBufferLen )

/*�ڴ��������궨��*/
#define PS_MEM_SET(pucBuffer, ucData, ulBufferLen) \
            VOS_MemSet( pucBuffer, ucData, ulBufferLen )

/*�ڴ��ƶ��궨��*/
#define PS_MEM_MOVE(pucDestBuffer, pucSrcBuffer, ulBufferLen) \
            VOS_MemMove( pucDestBuffer, pucSrcBuffer, ulBufferLen )

#define PS_MEM_CMP( pucDestBuffer, pucSrcBuffer, ulBufferLen ) \
            VOS_MemCmp( pucDestBuffer, pucSrcBuffer, ulBufferLen )


/*������Ϣ��,����ĳ��Ȱ�����Ϣ��ͷ����*/
#define PS_ALLOC_MSG_WITH_HEADER_LEN(ulPid , ulLen)  \
        VOS_AllocMsg( ulPid, (ulLen)-(VOS_MSG_HEAD_LENGTH) )

/*������Ϣ��,����ĳ��Ȳ�������Ϣ��ͷ����*/
#define PS_ALLOC_MSG(ulPid , ulLen)  \
        VOS_AllocMsg( ulPid, ulLen)

#define PS_ALLOC_MSG_ALL_CHECK(ulPid , ulLen)  \
        VOS_AllocMsg( ulPid, (ulLen)-(VOS_MSG_HEAD_LENGTH) )


/* �ڴ濽�� */
#define PS_MEM_CPY_ALL_CHECK(pucDestBuffer, pucSrcBuffer, ulBufferLen) \
             VOS_MemCpy( pucDestBuffer, pucSrcBuffer, ulBufferLen )

/*�ڴ��������궨��*/
#define PS_MEM_SET_ALL_CHECK(pucBuffer, ucData, ulBufferLen) \
             VOS_MemSet( pucBuffer, ucData, ulBufferLen )

/*�ڴ��ƶ��궨��*/
#define PS_MEM_MOVE_ALL_CHECK(pucDestBuffer, pucSrcBuffer, ulBufferLen) \
             VOS_MemMove( pucDestBuffer, pucSrcBuffer, ulBufferLen )


/*Ŀǰ,Э��ջOSA����֧��WIN32����ϵͳ,��PC�����ϲ���ʱ����Ҫʹ��miniDOPRA,���
  ���������ｫPS_SEND_MSG�ֱ���,����WIN32��VXWORKS�汾,����WIN32�汾,��ʹ��ԭ
  Ps_SendMsg����,�Ա�����PC STUB׮ת����Ϣ.����OSA֧��WIN32�汾��,�����ͳһ����*/
    #if(VOS_OS_VER == VOS_WIN32 )

        /*��Ϣ����*/
        #ifdef __RECUR_TEST__

        #define PS_SEND_MSG(ulPid, pMsg) \
            RECRUTEST_PsSendMsg(ulPid, pMsg)

        #elif defined(PS_ITT_PC_TEST)

        #define PS_SEND_MSG(ulPid, pMsg) \
            Ps_Itt_Stub_SendMsg(ulPid, pMsg)

        #elif defined(PS_ITT_PC_TEST_L2)
        #define PS_SEND_MSG(ulPid, pMsg) \
            VOS_SendMsg(ulPid, pMsg)
        #else

        VOS_UINT32 Ps_SendMsg(VOS_INT8 *cFileName, VOS_UINT32 ulLine, VOS_PID ulPid, VOS_VOID * pMsg);

        #define PS_SEND_MSG(ulPid, pMsg) \
            Ps_SendMsg((VOS_INT8 *)__FILE__, __LINE__, ulPid, pMsg)
        #endif
    #else
    /*��Ϣ����*/
    #define PS_SEND_MSG(ulPid, pMsg) \
            VOS_SendMsg( ulPid, pMsg)
    #endif

/*��Ϣ����*/
#define PS_POST_MSG(ulPid, pMsg) \
        VOS_PostMsg( ulPid, pMsg)

/*��Ϣ����*/
#define PS_SEND_URGENT_MSG(ulPid, pMsg) \
         VOS_SendUrgentMsg( ulPid, pMsg)


/*��Ϣ�ͷź궨��*/
#define PS_FREE_MSG(ulPid, pMsg) \
        VOS_FreeMsg( ulPid, pMsg)

/*�ڴ�����궨��*/
#if (VOS_OS_VER != VOS_WIN32)

#define PS_MEM_ALLOC(ulPid , ulSize) \
            VOS_MemAlloc( ulPid, (DYNAMIC_MEM_PT), ulSize)

#else   /*WIN32 DOPRA 1.6.1�汾DYNAMIC_MEM_PT�ڴ�����㷨����BUG����˻���BLOCK_MEM_PT-h42180*/
#define PS_MEM_ALLOC(ulPid , ulSize) \
            VOS_MemAlloc( ulPid, (BLOCK_MEM_PT), ulSize)
#endif


/*�ڴ��ͷź궨��*/
#define PS_MEM_FREE(ulPid, pAddr ) \
        VOS_MemFree( ulPid, pAddr)

/*���뾲̬�ڴ�궨��*/
#define PS_ALLOC_STATIC_MEM(ulPid , ulSize)\
        VOS_MemAlloc(ulPid, (STATIC_MEM_PT), ulSize)


/*�ͷž�̬�ڴ�궨��*/
#define PS_FREE_STATIC_MEM(ulPid, pAddr )\
        VOS_MemFree(ulPid, (pAddr))
#endif



/* ��ʱ����װ */

/* ������ʱ��
Input Parameters
Pid: The function module ID of application.

ulLength:The duration of relative timer, in milliseconds.

ulName:Timer name. When the timer times out, this parameter will be passed to the application.

ulParam:Additional parameter. When the timer times out,
this parameter will be passed to the application.

ucMode: Work mode of relative timer:
VOS_RELTIMER_LOOP (loop);
VOS_RELTIMER_NOLOOP (no loop).

Output Parameters

phTm: The relative timer provided to the application by the system.
When phTm is VOS_NULL_PTR, ucMode is not allowed to be VOS_RELTIMER_LOOP.
*/

#if (VOS_OS_VER != VOS_WIN32)

    #define PS_START_REL_TIMER(phTm, ulPid, ulLength, ulName, ulParam, ucMode)\
                            VOS_StartRelTimer( phTm, ulPid, ulLength, ulName, ulParam, ucMode, VOS_TIMER_PRECISION_0 )
#else
    #define PS_START_REL_TIMER(phTm, ulPid, ulLength, ulName, ulParam, ucMode)\
                            VOS_StartRelTimer( phTm, ulPid, ulLength, ulName, ulParam, ucMode )
#endif

/*sunbing 49683 2013-7-14 VoLTE begin*/
#define PS_START_CALLBACK_REL_TIMER(phTm, ulPid, ulLength, ulName, ulParam, ucMode, TimeOutRoutine, ulPrecision)\
                            VOS_StartCallBackRelTimer(phTm, ulPid, ulLength, ulName, ulParam, ucMode, TimeOutRoutine, ulPrecision)
/*sunbing 49683 2013-7-14 VoLTE end*/

#define PS_STOP_REL_TIMER(phTm)               VOS_StopRelTimer( phTm )

#define PS_GET_REL_TIMER_NAME(pMsg)          (((REL_TIMER_MSG *)pMsg)->ulName)

#define PS_GET_REL_TIMER_PARA(pMsg)          (((REL_TIMER_MSG *)pMsg)->ulPara)

#define PS_RESTART_REL_TIMER(phTm) \
        VOS_RestartRelTimer(phTm)

/*��װ���Ӻ���ע�ắ��*/
#define PS_REGISTER_MSG_GET_HOOK(pfnMsgHook) \
        VOS_RegisterMsgGetHook(pfnMsgHook)

#define PS_SND_MSG_ALL_CHECK(ulPid , pMsg)              PS_SEND_MSG(ulPid, pMsg)

/* ���ͽ�����Ϣ */
#define PS_SND_URGENT_MSG(ulPid , pMsg)                 VOS_SendUrgentMsg(ulPid, pMsg)

#define PS_MEM_ALLOC_All_CHECK(ulPid , ulSize) \
            PS_MEM_ALLOC(ulPid , ulSize)

/*�ڴ��ͷź궨��*/
#define PS_MEM_FREE_ALL_CHECK(ulPid, pAddr )            PS_MEM_FREE(ulPid, pAddr)

#define PS_FREE_MSG_ALL_CHECK(Pid, pMsg)                PS_FREE_MSG(Pid, pMsg)


#ifndef CONST
  #define CONST const
#endif

#ifndef STATIC
  #define STATIC static
#endif



/*****************************************************************************
  3 Massage Declare
*****************************************************************************/



/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
  5 STRUCT
*****************************************************************************/


/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/
/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/



/*****************************************************************************
  9 OTHERS
*****************************************************************************/




#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* PsOsAdapter.h */

