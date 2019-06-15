/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_02	 
* File name: Seat.h	  
* Description : 设置座位用例业务逻辑层头文件	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef SEAT_H_
#define SEAT_H_

//座位状态 
typedef enum{
	SEAT_NONE=0,			//空位
	SEAT_GOOD=1,			//有座位
	SEAT_BROKEN=9			//损坏的座位
}seat_status_t;

//座位数据结构 
typedef struct {
	int id;					//座位id
	int roomID;				//所在演出厅id
	int row;           		//座位行号
    int column;        		//座位列号
    seat_status_t status;	//座位在该行的状态，0表示没有座位，1表示有座位。扩展2可表示座位坏了
} seat_t;


//双向链表
typedef struct seat_node {
	seat_t data;
	struct seat_node *next, *prev;
} seat_node_t, *seat_list_t;

/*
标识符：TTMS_SCU_Seat_Srv_RoomInit
功能：根据行、列数初始化演出厅的座位
*/ 
int Seat_Srv_RoomInit(seat_list_t list, int roomID,int rowsCount,int colsCount);

/*
标识符：TTMS_SCU_Seat_Srv_SortSeatList 
功能：对座位链表list进行排序
*/
void Seat_Srv_SortSeatList(seat_list_t list );

/*
标识符：TTMS_SCU_Seat_Srv_AddSortedList
功能：将结点node加入到已排序链表list中*/
void Seat_Srv_AddToSoftedList(seat_list_t list , seat_node_t *node);

/*
标识符：TTMS_SCU_Seat_Srv_Add
功能：单个添加座位
*/
int Seat_Srv_Add(const seat_t *data);

/*
标识符：TTMS_SCU_Seat_Srv_AddBatch 
功能：批量添加座位
*/
int Seat_Srv_AddBatch(seat_list_t list);

/*
标识符：TTMS_SCU_Seat_ Srv_Mod 
功能：修改座位
*/
int Seat_Srv_Modify(const seat_t *data);

/*
标识符：TTMS_SCU_Seat_Srv_DelByID 
功能：删除座位
*/
int Seat_Srv_DeleteByID(int ID);

/*
标识符：TTMS_SCU_Seat_Srv_DeleteAllByRoomID 
功能：批量删除座位
*/
int Seat_Srv_DeleteAllByRoomID(int roomID);

/*
标识符：TTMS_SCU_Seat_Srv_ FetchValidByRoomID 
功能：根据放映厅ID提取有效的座位
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID);

/*
标识符：TTMS_SCU_Seat_Srv_FetchByID 
功能：根据ID获取座位服务
*/ 
int Seat_Srv_FetchByID(int ID, seat_t *buf);

/*
标识符：标识符：TTMS_SCU_Seat_Srv_FetchByRoomID 
功能：根据演出厅ID获取所有座位服务
*/
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID);

/*
标识符：TTMS_SCU_Seat_Srv_FetchByRoomID
功能：根据放映厅ID提取有效的座位
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID);

/*
标识符：TTMS_SCU_Seat_Srv_FindByRC
功能：根据行列号获取座位服务
*/
seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column);

/*
标识符：TTMS_SCU_Studio_Srv_FindByID
功能：根据ID在链表中获取座位服务*/ 
seat_node_t * Seat_Srv_FindByID(seat_list_t list, int seatID);


#endif //SEAT_H_





