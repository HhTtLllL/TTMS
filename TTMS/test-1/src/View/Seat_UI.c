/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* ������ţ�TTMS_UC_02
* File name: Seat_UI.c			  
* Description : ������λ���������	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "Seat_UI.h"
#include "../Service/Seat.h"

#include "../Service/Studio.h"
#include "../Common/list.h"
#include <stdio.h>

/*
��ʶ����TTMS_SCU_Seat_UI_S2C 
�������ܣ�������λ״̬��ȡ������ʾ���š�
����˵����statusΪseat_status_t���ͣ���ʾ��λ״̬��
�� �� ֵ���ַ��ͣ���ʾ��λ�Ľ�����ʾ���š�
*/
inline char Seat_UI_Status2Char(seat_status_t status) {

	if(status == 1)
		return "#";

}

/*
��ʶ����TTMS_SCU_Seat_UI_C2S
�������ܣ�����������Ż�ȡ��λ״̬��
����˵����statusCharΪ�ַ��ͣ���ʾ������λ��������š�
�� �� ֵ��seat_status_t���ͣ���ʾ��λ��״̬��
*/
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	return SEAT_NONE;
}

/*
��ʶ����TTMS_SCU_Seat_UI_MgtEnt
�������ܣ�����������λ����ں�������ʾ��ǰ����λ���ݣ����ṩ��λ������ӡ��޸ġ�ɾ�����ܲ�������ڡ�
����˵����roomIDΪ���ͣ�����Ҫ������λ���ݳ���ID��
�� �� ֵ���ޡ�
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
ʶ����TTMS_SCU_Seat_UI_Add
�������ܣ��������һ���µ���λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬
         �ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��������λ�ı�־��
*/
int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) 
{        
														//����һ����λ
	seat_t temp;
	temp.roomID = roomID;
	temp.row = row - 1;
	temp.column = column - 1;
	Seat_Srv_Add(&temp);

	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_UI_Mod 
�������ܣ������޸�һ����λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸�����λ�ı�־��
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
��ʶ����TTMS_SCU_Seat_UI_Del
�������ܣ�����ɾ��һ����λ�����ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
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

