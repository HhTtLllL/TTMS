/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: list.h			 
* Description : 链表操作宏定义、分页操作 
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日		 
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <assert.h>

/*初始化链表list。链表为带头结点的双向循环链表*/
#define List_Init(list, list_node_t) {					\
		list=(list_node_t*)malloc(sizeof(list_node_t)); \
		(list)->next=(list)->prev=list;					\
	}

//释放链表list中所有数据结点。list 为链表头指针，list_node_t为链表结点类型
#define List_Free(list, list_node_t) {			\
		assert(NULL!=list);						\
		list_node_t *tmpPtr;					\
		(list)->prev->next=NULL; 				\
		while(NULL!=(tmpPtr=(list)->next)){ 	\
			(list)->next=tmpPtr->next;			\
			free(tmpPtr);						\
		}										\
		(list)->next=(list)->prev=list;			\
	}

//销毁链表list，释放所有数据结点及头结点。 list为链表头指针，tmpPtr为链表结点临时指针变量
#define List_Destroy(list, list_node_t) {		\
		assert(NULL!=list);						\
		List_Free(list, list_node_t)			\
		free(list);								\
		(list)=NULL;							\
	}

//链表头插法，list为头指针，new为新节点
#define List_AddHead(list, newNode) {			\
		(newNode)->next=(list)->next;		 	\
		(list)->next->prev=newNode;			 	\
		(newNode)->prev=(list);				 	\
		(list)->next=newNode;				 	\
	}

//链表尾插法，list为头指针，new为新节点
#define List_AddTail(list, newNode) {			\
		(newNode)->prev=(list)->prev; 		 	\
		(list)->prev->next=newNode;			 	\
		(newNode)->next=list;				 	\
		(list)->prev=newNode;				 	\
	}

//将新节点newNode加入到node之前
#define List_InsertBefore(node, newNode) {		\
		(newNode)->prev=(node)->prev; 		 	\
		(newNode)->next=node;			 		\
		(newNode)->prev->next=newNode;			\
		(newNode)->next->prev=newNode;			\
	}

//将新节点newNode加入到node之后
#define List_InsertAfter(node, newNode) {		\
		(newNode)->next=node->next;			 	\
		(newNode)->prev=node; 				 	\
		(newNode)->next->prev=newNode;			\
		(newNode)->prev->next=newNode;			\
	}

//判断链表是否为空，list为头指针
#define List_IsEmpty(list)  ((list != NULL)	\
	&& ((list)->next == list)				\
	&& (list == (list)->prev))

//从删除链表结点node，
#define List_DelNode(node) {\
			assert(NULL!=node && node!=(node)->next && node!=(node)->prev);				\
			(node)->prev->next=(node)->next; 	\
			(node)->next->prev=(node)->prev;	\
	}

//从链表中删除并释放结点node
#define List_FreeNode(node) {	\
		List_DelNode(node);		\
		free(node);				\
	}


//使用指针curPos依次遍历链表list
#define List_ForEach(list, curPos) 		\
	 for (   curPos = (list)->next;  	\
		  	  	  curPos != list;       \
		  	  	  curPos=curPos->next	\
	    )


//分页数据结构体，简称分页器类型
typedef struct
{
	int totalRecords;	//总记录数
	int offset;			//当前页起始记录相对于第一条记录的偏移记录数
	int pageSize;		//页面大小
	void *curPos;		//当前页起始记录在链表中的结点地址
}Pagination_t;

//根据分页器paging的偏移量offset将分页器定位到链表list的对应位置
#define List_Paging(list, paging, list_node_t) {			\
		if(paging.offset+paging.pageSize>=paging.totalRecords){	\
			Paging_Locate_LastPage(list, paging, list_node_t);	}\
		else {													\
			int i;												\
			list_node_t * pos=(list)->next;						\
			for( i=0; i<paging.offset && pos!=list ; i++) 		\
			   pos=pos->next;		 							\
			paging.curPos=(void*)pos;							\
		}														\
	}

//将分页器paging定位到链表list的第一页
#define Paging_Locate_FirstPage(list, paging) { \
		paging.offset=0;						\
		paging.curPos=(void *)((list)->next);	\
	}

//将分页器paging定位到链表list的最后一页
#define Paging_Locate_LastPage(list, paging, list_node_t) {	\
	int i=paging.totalRecords % paging.pageSize;	\
	if (0==i && paging.totalRecords>0)				\
		i=paging.pageSize;							\
	paging.offset=paging.totalRecords-i;			\
	list_node_t * pos=(list)->prev;					\
	for(;i>1;i--)									\
		pos=pos->prev;								\
	paging.curPos=(void*)pos;						\
													\
}

//对于链表list及分页器paging,使用指针curPos依次遍历paging指向页面中每个结点
//这里i为整型计数器变量
#define Paging_ViewPage_ForEach(list, paging, list_node_t, pos, i) 	\
	for (i=0, pos = (list_node_t *) (paging.curPos);	\
			pos != list && i < paging.pageSize; 		\
			i++, pos=pos->next)							\

//对于链表list,将分页器paging向前（后）移动offsetPage个页面.
//当offsetPage<0时，向前（链表头方向）移动|offsetPage|个页面
//当offsetPage>0时，向后（链末尾方向）移动offsetPage个页面
#define Paging_Locate_OffsetPage(list, paging, offsetPage, list_node_t) {\
	int offset=offsetPage*paging.pageSize;			\
	list_node_t *pos=(list_node_t *)paging.curPos;	\
	int i;											\
	if(offset>0){									\
		if( paging.offset + offset >= paging.totalRecords )	{\
			Paging_Locate_LastPage(list, paging, list_node_t);	\
		}else {												\
			for(i=0; i<offset; i++ )						\
				pos=pos->next;								\
			paging.offset += offset;						\
			paging.curPos= (void *)pos;						\
		}													\
	}else{													\
		if( paging.offset + offset <= 0 ){					\
			Paging_Locate_FirstPage(list, paging);			\
		}else {												\
			for(i=offset; i<0; i++ )						\
				pos	= pos->prev;							\
			paging.offset += offset;						\
			paging.curPos= pos;								\
		}													\
	}														\
}

//根据分页器paging计算当前的页号
#define Pageing_CurPage(paging) 	(0==(paging).totalRecords?0:1+(paging).offset/(paging).pageSize)

//根据分页器paging计算的总的页数
#define Pageing_TotalPages(paging)	(((paging).totalRecords%(paging).pageSize==0)?\
	(paging).totalRecords/(paging).pageSize:\
	(paging).totalRecords/(paging).pageSize+1)

//根据paging判断当前页面是否为第一页。结果为true表示是，否则false
#define Pageing_IsFirstPage(paging) (Pageing_CurPage(paging)<=1)

//根据paging判断当前页面是否为最后一页。结果为true表示是，否则false
#define Pageing_IsLastPage(paging) 	(Pageing_CurPage(paging)>=Pageing_TotalPages(paging))


#endif /* LIST_H_ */
