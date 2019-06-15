/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* 用例编号：TTMS_UC_02
* File name: Seat_UI.c			  
* Description : 设置座位用例界面层	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#include "Seat_UI.h"
#include "../Service/Seat.h"

#include "../Service/Studio.h"
#include "../Common/list.h"
#include <stdio.h>

/*
表识符：TTMS_SCU_Seat_UI_S2C 
函数功能：根据座位状态获取界面显示符号。
参数说明：status为seat_status_t类型，表示座位状态。
返 回 值：字符型，表示座位的界面显示符号。
*/
inline char Seat_UI_Status2Char(seat_status_t status) {

	if(status == 1)
		return "#";

}

/*
标识符：TTMS_SCU_Seat_UI_C2S
函数功能：根据输入符号获取座位状态。
参数说明：statusChar为字符型，表示设置座位的输入符号。
返 回 值：seat_status_t类型，表示座位的状态。
*/
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	return SEAT_NONE;
}

/*
标识符：TTMS_SCU_Seat_UI_MgtEnt
函数功能：界面层管理座位的入口函数，显示当前的座位数据，并提供座位数据添加、修改、删除功能操作的入口。
参数说明：roomID为整型，是需要设置座位的演出厅ID。
返 回 值：无。
*/ 
void Seat_UI_MgtEntry(int roomID) 
{
	
	seat_list_t list;
	List_Init(list,seat_node_t);
	studio_t buf;   //guan ying shi
	buf.id = 0;

	Studio_Srv_FetchByID(roomID,&buf);  

//	buf.seatsCount;
	if(buf.id == 0)
	{
		printf( "the studio is not in here\n");
		return ;
	}	
	
	buf.seatsCount = Seat_Srv_FetchByRoomID(list,roomID);



	if(List_IsEmpty(list))
	{
		Seat_Srv_RoomInit(list,roomID,buf.rowsCount,buf.colsCount);
		Studio_Srv_Modify(&buf);      //updata  studio
		
		
		
		buf.seatsCount = Seat_Srv_FetchByRoomID(list,roomID);
		list = list->next;
	/*	printf( "%d    \n",list->data.status);*/
		printf( "-----------------------------------------------%d  studio---------------------------------------------------------\n",roomID);
		for(int i = 0;i < buf.rowsCount;i++)
		{
			for(int j = 0;j < buf.colsCount;j++)
			{
				if(list->data.status == 1)
				{
					printf( "# ");
					list = list->next;
				}
			}

			printf( "\n");
		}
	}
	else
	{
		list = list->next;
		printf( "-----------------------------------------------%d  studio---------------------------------------------------------\n",roomID);
		for(int i = 0;i < buf.rowsCount;i++)
		{
			for(int j = 0;j < buf.colsCount;j++)
			{
				if(list->data.status == 1)
				{

					printf( "# ");
					list = list->next;
				}
				else
				{
					printf( "  ",list->data.status);
					list = list->next;
				}

/*				printf("%c",Seat_UI_Status2Char(list->data.status));
				list = list->next;*/
			}

			printf( "\n");
		}
		

	}


	char choice;
	printf( "your choice :");
	choice = getchar();
	int row,col;
	switch(choice)
	{
		case 'a':
		case 'A':
			scanf( "%d%d",&row,&col);
			Seat_UI_Add(list,roomID,row,col);
			break;
		case 'u':
		case 'U':
			scanf( "%d%d",&row,&col);
			Seat_UI_Modify(list,roomID,row,col);
			break;
		case 'd':
		case 'D':
			scanf( "%d%d",&row,&col);
			Seat_UI_Delete(list,roomID,row,col);
			break;
		defualt:break;
	}
 
}

/*
识符：TTMS_SCU_Seat_UI_Add
函数功能：用于添加一个新的座位数据。
参数说明：第一个参数list为seat_list_t类型指针，指向座位链表头指针，
         第二个参数rowsCount为整型，表示座位所在行号，第三个参数colsCount为整型，表示座位所在列号。
返 回 值：整型，表示是否成功添加了座位的标志。
*/
int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) 
{        
														//输入一个座位
	seat_t temp;
	temp.roomID = roomID;
	temp.row = row - 1;
	temp.column = column - 1;
	Seat_Srv_Add(&temp);

	return 0;
}

/*
标识符：TTMS_SCU_Seat_UI_Mod 
函数功能：用于修改一个座位数据。
参数说明：第一个参数list为seat_list_t类型指针，指向座位链表头指针，第二个参数rowsCount为整型，表示座位所在行号，第三个参数colsCount为整型，表示座位所在列号。
返 回 值：整型，表示是否成功修改了座位的标志。
*/
int Seat_UI_Modify(seat_list_t list,int roomID, int row, int column) 
{
	seat_t temp;
	temp.roomID = roomID;
	temp.row = row-1;
	temp.column = column - 1;
	Seat_Srv_Modify(&temp);

	return 0;

}

/*
标识符：TTMS_SCU_Seat_UI_Del
函数功能：用于删除一个座位的数据。
参数说明：第一个参数list为seat_list_t类型指针，指向座位链表头指针，第二个参数rowsCount为整型，表示座位所在行号，第三个参数colsCount为整型，表示座位所在列号。
返 回 值：整型，表示是否成功删除了座位的标志。
*/
int Seat_UI_Delete(seat_list_t list,int roomID, int row, int column) 
{
	seat_t temp;
	temp.roomID = roomID;
	temp.row = row - 1;
	temp.column = column - 1;
	Seat_Srv_Del(&temp);

	return 0;

}

