/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_02	 
* File name: Seat.h	  
* Description : 设置座位用例持久化层	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
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

//添加对象主键标识名称
static const char SEAT_KEY_NAME[] = "Seat";

/*
函数功能：用于向文件中添加一个新座位数据。
参数说明：data为seat_t类型指针，表示需要添加的座位数据结点。
返 回 值：整型，表示是否成功添加了座位的标志。
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
标识符：TTMS_SCU_Seat_Perst_InsertBatch
函数功能：用于向文件中添加一批座位数据。
参数说明：list为seat_list_t类型，表示需要添加的一批座位的链表头指针。
返 回 值：整型，表示成功添加一批座位的个数。
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
标识符：TTMS_SCU_Seat_Perst_Update
函数功能：用于在文件中更新一个座位数据。
参数说明：data为seat_t类型指针，表示需要更新的座位数据结点。
返 回 值：整型，表示是否成功更新了座位的标志。
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
识符：TTMS_SCU_Seat_Perst_DelByID
函数功能：用于从文件中删除一个座位的数据。
参数说明：参数ID为整型，表示需要删除的座位ID。 
返 回 值：整型，表示是否成功删除了座位的标志。
*/
int Seat_Perst_DeleteByID(int ID) {
	
	return 0;
}

/*
标识符：TTMS_SCU_Seat_Perst_DelAllByID
函数功能：根据编号用于从文件中删除座位数据。
参数说明：参数roomID为整型，表示演出厅ID。 
返 回 值：整型，表示是否成功删除了座位的标志。
*/ 
int Seat_Perst_DeleteAllByRoomID(int roomID) {
	
	return 0;
}

/*
标识符：TTMS_SCU_Studio_Perst_SelByID
函数功能：用于从文件中载入一个座位的数据。
参数说明：第一个参数ID为整型，表示需要载入数据的座位ID；第二个参数buf为seat_t指针，指向载入座位数据的指针。
返 回 值：整型，表示是否成功载入了座位的标志。
*/
int Seat_Perst_SelectByID(int ID, seat_t *buf) {
	
	return 0;
}

/*
标识符：TTMS_SCU_Seat_Perst_SelAll
函数功能：用于从文件中载入所有座位数据。
参数说明：list为seat_list_t类型，表示将要载入的座位链表头指针。
返 回 值：整型，成功载入座位的个数。
*/
int Seat_Perst_SelectAll(seat_list_t list) {
	
	return 0;
}

/*
标识符：TTMS_SCU_Seat_Perst_SelByRoomID
函数功能：用于在文件中根据演出厅ID载入所有座位数据。
参数说明：第一个参数list为seat_list_t类型，表示将要载入的座位链表头指针，第二个参数roomID为整型，表示演出厅ID。
返 回 值：整型，表示成功载入了演出厅座位的个数。
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
