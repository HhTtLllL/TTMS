/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_02	 
* File name: Seat.h	  
* Description : ������λ�����־û���	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "Seat_Persist.h"
#include "../Service/Seat.h"
#include "../Common/list.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char SEAT_DATA_FILE[] = "Seat.dat";
static const char SEAT_DATA_TEMP_FILE[] = "SeatTmp.dat";

//��Ӷ���������ʶ����
static const char SEAT_KEY_NAME[] = "Seat";

/*
�������ܣ��������ļ������һ������λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ��ӵ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��������λ�ı�־��
*/ 
int Seat_Perst_Insert(seat_t *data) 
{   
	assert(NULL!=data);
	FILE *fp = fopen(SEAT_DATA_FILE,"rb+");
	if(NULL == fp)
	{
		printf( "the file is not in here\n");
	}
	seat_t temp;
	while(!feof(fp))
	{
		if(fread(&temp,sizeof(seat_t),1,fp))
		{
			if(temp.roomID == data->roomID && temp.row == data->row && temp.column == data->column )
			{
				printf( "roomID = %d id = %d row = %d col = %d\n",temp.roomID,temp.id,temp.row,temp.column);
				if(temp.status == 0)
				{
					printf("addtemp.status = %d",temp.status);
					temp.status = 1;
					fseek(fp,-sizeof(seat_t),SEEK_CUR);
					fwrite(&temp,sizeof(seat_t),1,fp);
					break;
				}
			}
		}
	}

	fclose(fp);

	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_InsertBatch
�������ܣ��������ļ������һ����λ���ݡ�
����˵����listΪseat_list_t���ͣ���ʾ��Ҫ��ӵ�һ����λ������ͷָ�롣
�� �� ֵ�����ͣ���ʾ�ɹ����һ����λ�ĸ�����
*/
int Seat_Perst_InsertBatch(seat_list_t list) {
	seat_node_t *p;
	assert(NULL!=list);

	return 0;
}
int Seat_Perst_Del(const seat_t *data)
{
	assert(NULL != data);
	FILE *fp = fopen(SEAT_DATA_FILE,"rb+");
	if(NULL == fp)
	{
		printf( "the file is not in here\n");
		return 0;
	}
	seat_t temp;
	while(!feof(fp))
	{
		if(fread(&temp,sizeof(seat_t),1,fp))
		{
			if(temp.roomID == data->roomID && temp.row == data->row && temp.column == data->column )
			{
				printf( "roomID = %d id = %d row = %d col = %d\n",temp.roomID,temp.id,temp.row,temp.column);
				if(temp.status == 1);
				{
					temp.status = 0;
					fseek(fp,-sizeof(seat_t),SEEK_CUR);
					fwrite(&temp,sizeof(seat_t),1,fp);
					break;
				}
			}
		}
	}

	fclose(fp);

}
/*
��ʶ����TTMS_SCU_Seat_Perst_Update
�������ܣ��������ļ��и���һ����λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ���µ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_Perst_Update(const seat_t *data) 
{
	assert(NULL!=data);


	FILE *fp = fopen(SEAT_DATA_FILE,"rb+");
//	fseek(fp,0L,SEEK_SET);
	seat_t temp;
	while(!feof(fp))
	{
		if(fread(&temp,sizeof(seat_t),1,fp))
		{
			if(temp.roomID == data->roomID && temp.row == data->row && temp.column == data->column )
			{

					char flag;
					printf( "please inpit you will Mod [%d,%d]:",temp.row+1,temp.column+1);
					printf( "0 -> aisle,1 -> effect,other -> brokenn\n");
					getchar( );
					flag = getchar();
					getchar( );
					printf( "flag = %c\n",flag);
					if(flag == '1') 
						temp.status = 1;
					else
						temp.status = 2;
					printf( "mod = temp.status = %d",temp.status);
					fseek(fp,-sizeof(seat_t),SEEK_CUR);
					fwrite(&temp,sizeof(seat_t),1,fp);
			}
		}
	}

	fclose(fp);
	return 0;

}

/*
ʶ����TTMS_SCU_Seat_Perst_DelByID
�������ܣ����ڴ��ļ���ɾ��һ����λ�����ݡ�
����˵��������IDΪ���ͣ���ʾ��Ҫɾ������λID�� 
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_Perst_DeleteByID(int ID) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_DelAllByID
�������ܣ����ݱ�����ڴ��ļ���ɾ����λ���ݡ�
����˵��������roomIDΪ���ͣ���ʾ�ݳ���ID�� 
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/ 
int Seat_Perst_DeleteAllByRoomID(int roomID) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Studio_Perst_SelByID
�������ܣ����ڴ��ļ�������һ����λ�����ݡ�
����˵������һ������IDΪ���ͣ���ʾ��Ҫ�������ݵ���λID���ڶ�������bufΪseat_tָ�룬ָ��������λ���ݵ�ָ�롣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_Perst_SelectByID(int ID, seat_t *buf) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_SelAll
�������ܣ����ڴ��ļ�������������λ���ݡ�
����˵����listΪseat_list_t���ͣ���ʾ��Ҫ�������λ����ͷָ�롣
�� �� ֵ�����ͣ��ɹ�������λ�ĸ�����
*/
int Seat_Perst_SelectAll(seat_list_t list) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_SelByRoomID
�������ܣ��������ļ��и����ݳ���ID����������λ���ݡ�
����˵������һ������listΪseat_list_t���ͣ���ʾ��Ҫ�������λ����ͷָ�룬�ڶ�������roomIDΪ���ͣ���ʾ�ݳ���ID��
�� �� ֵ�����ͣ���ʾ�ɹ��������ݳ�����λ�ĸ�����
*/
int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID) 
{
	            
        int num = 1;
        seat_list_t temp = (seat_list_t)malloc(sizeof(seat_node_t));
        FILE *fp;
        fp = fopen(SEAT_DATA_FILE,"ab+");

        if(NULL == fp) 
        {   
                printf( "Cannot open file %s!\n",SEAT_DATA_FILE);
                return 0;

        }   
//      List_Init(list,seat_node_t);

        while(!feof(fp))
        {   
                if(fread(temp,sizeof(seat_node_t),1,fp))
                {   
                        if(temp->data.roomID == roomID)
                        {           
                                printf( "%d     \n",num);
                                if(temp->data.status == 1)    num++;
				List_AddTail(list,temp);
                            	temp = (seat_list_t)malloc(sizeof(seat_node_t));
                        }
                }
        }   



	return 0;
}
