/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* 用例编号：TTMS_UC_01	
* File name: Studio_c		  
* Description : 演出厅用例业务逻辑层头文件	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef STUDIO_H_
#define STUDIO_H_

//演出厅数据结构 
typedef struct {
	int id;			//放映厅ID
	char name[30];	//放映厅名称
	int rowsCount;	//座位行数
	int colsCount;	//座位列数
	int seatsCount;
} studio_t;

//双向链表
typedef struct studio_node {
	studio_t data;				//实体数据
	struct studio_node *next;	//后向指针
	struct studio_node *prev;	//前向指针
} studio_node_t, *studio_list_t;

//标识符：TTMS_SCU_Studio_Srv_Add 
//功能：添加新演出厅服务
int Studio_Srv_Add(studio_t *data);

//标识符：TTMS_SCU_Studio_ Srv _Mod 
//功能：修改演出厅服务
int Studio_Srv_Modify(const studio_t *data);

//标识符：TTMS_SCU_Studio_Srv_DelByID 
//功能：根据ID删除演出厅服务
int Studio_Srv_DeleteByID(int ID);

//标识符：TTMS_SCU_Studio_Srv_FetchByID
//功能：根据ID获取相应演出厅 
int Studio_Srv_FetchByID(int ID, studio_t *buf);

//标识符：TTMS_SCU_Studio_Srv_FetchAll
//功能：获取全部演出厅服务
int Studio_Srv_FetchAll(studio_list_t list);

//标识符：TTMS_SCU_Studio_Srv_FindByID
//功能：根据ID在链表中获取相应演出厅结点
studio_node_t *Studio_Srv_FindByID(studio_list_t list, int ID);

#endif //STUDIO_H_
