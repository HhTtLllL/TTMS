/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: listTestDrv.c			 
* Description : 链表操作测试 
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日		 
*/

#include "listTestDrv.h"
#include <stdlib.h>
#include <stdio.h>

#include "../Common/list.h"

//链表初始化测试 
void ListTest_Init() {
	TestList_t head=NULL;

	List_Init(head, TestList_Node_t);

	if (head!=NULL && head->next == head && head->prev == head)
		printf("List_Init passed!\n");
	else
		printf("List_Init Failed!\n");

	List_Destroy(head, TestList_Node_t);
}

//链表为空测试 
void ListTest_Empty() {
	TestList_Node_t head;
	head.next = head.prev = &head;

	if (List_IsEmpty(&head))
		printf("List_Empty passed!\n");
	else
		printf("List_Empty Failed!\n");
}

//链表尾插法插入结点测试 
void ListTest_AddTail() {
	TestList_t head;
	TestList_Node_t *p, *nodes;
	int i = 0;
	int result = 1;

	/*初始化链表*/
	head = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	head->next = head->prev = head;

	/*初始化数据*/
	nodes = (TestList_Node_t*) malloc(sizeof(TestList_Node_t) * 3);
	/*生成测试数据*/
	for (i = 0; i < 3; i++) {
		nodes[i].data.value = i;
		List_AddTail(head, &nodes[i]);
	}

	/*校验next链表指针完整性*/
	for (p = head->next, i = 0; i < 3; i++, p = p->next) {
		if (p != &nodes[i]) {
			result = 0;
			break;
		}
	}

	if (p != head)
		result = 0;

	/*校验prev链表指针完整性*/
	for (p = head->prev, i = 2; i >= 0; i--, p = p->prev) {
		if (p != &nodes[i]) {
			result = 0;
			break;
		}
	}
	if (p != head)
		result = 0;

	free(nodes);
	free(head);

	if (result)
		printf("List_AddTail Passed!\n");
	else
		printf("List_AddTail Failed!\n");

}

//链表头插法插入结点测试 
void ListTest_AddHead() {
	TestList_t head;
	TestList_Node_t *p, *nodes;
	int i = 0;

	int result = 1;

	/*初始化链表*/
	head = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	head->next = head->prev = head;

	/*初始化数据*/
	nodes = (TestList_Node_t*) malloc(sizeof(TestList_Node_t) * 3);
	/*生成测试数据*/
	for (i = 0; i < 3; i++) {
		nodes[i].data.value = i;
		List_AddHead(head, &nodes[i]);
	}

	/*校验next链表指针完整性*/
	for (p = head->next, i = 2; i >= 0; i--, p = p->next) {
		if (p != &nodes[i]) {
			result = 0;
			break;
		}
	}
	if (p != head)
		result = 0;

	/*校验prev链表指针完整性*/
	for (p = head->prev, i = 0; i < 3; i++, p = p->prev) {
		if (p != &nodes[i]) {
			result = 0;
			break;
		}
	}
	if (p != head)
		result = 0;

	free(nodes);
	free(head);

	if (result)
		printf("List_AddHead Passed!\n");
	else
		printf("List_AddHead Failed!\n");
}

//释放链表测试  
void ListTest_Free() {
	TestList_t head;
	TestList_Node_t *node;

	/*初始化链表*/
	head = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	head->next = head->prev = head;

	/*测试空链表的Free*/
	List_Free(head, TestList_Node_t);

	if (NULL==head || head->next != head || head->prev != head){
		printf("List_Free Failed!\n");
		return ;
	}

	/*测试非空链表Free*/
	node = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	node->data.value=1;
	/*将结点node插入到链表中*/
	node->next=head;
	node->prev=head;
	head->next=node;
	head->prev=node;

	List_Free(head, TestList_Node_t);
	if (head!=NULL && head->next == head && head->prev == head)
		printf("List_Free passed!\n");
	else
		printf("List_Free Failed!\n");

	free(head);
}

//销毁链表测试 
void ListTest_Destroy() {
	TestList_t head;
	TestList_Node_t *node;

	/*测试空链表的Free*/
	head = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	head->next = head->prev = head;
	List_Destroy(head, TestList_Node_t);

	if (NULL!=head){
		printf("List_Destroy Failed!\n");
		return ;
	}

	/*测试非空链表Free*/
	head = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	head->next = head->prev = head;
	node = (TestList_Node_t*) malloc(sizeof(TestList_Node_t));
	node->data.value=1;
	/*将结点node插入到链表中*/
	node->next=head;
	node->prev=head;
	head->next=node;
	head->prev=node;

	List_Destroy(head, TestList_Node_t);
	if (head==NULL)
		printf("List_Destroy passed!\n");
	else
		printf("List_Destroy Failed!\n");
}

//链表测试用例 
void List_TestDriver_Entry() {
	/*测试初始化*/
	ListTest_Init();

	ListTest_Empty();

	ListTest_AddTail();

	ListTest_AddHead();

	ListTest_Free();

	ListTest_Destroy();

}
