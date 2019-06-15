/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: listTestDrv.h			 
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日		 
*/

#ifndef COMMON_LISTTESTDRV_H_
#define COMMON_LISTTESTDRV_H_

//链表结点数据定义 ，测试用 
typedef struct TestListRec
{
    int value;
}TestListRec_t;

//链表结点定义 ，测试用 
typedef struct TestListNode
{
    TestListRec_t data;
    struct TestListNode *next, *prev;
}TestList_Node_t, *TestList_t;

//链表为空，测试用  
static void ListTest_Empty();

//初始化链表，测试用  
static void ListTest_Init();

//链表尾插法插入结点,测试用 
static void ListTest_AddTail();

//链表头插法插入结点,测试用 
static void ListTest_AddHead();

//释放链表,测试用   
static void ListTest_Free();

//销毁链表，测试用 
static void ListTest_Destroy();

//链表测试用例 
void List_TestDriver_Entry();


#endif /* COMMON_LISTTESTDRV_H_ */
