#include"Ticket_Persist.h"
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include"../Common/list.h"
#include"EntityKey_Persist.h"
#include"../Service/Ticket.h"
#include"../Service/Schedule.h"
#include"../Persistence/Schedule_Persist.h"
#include"../Service/Play.h"
#include"../Persistence/Play_persist.h"
#include"../Service/Seat.h"
static const char TICKET_DATA_FILE[] = "Ticket.dat";

static const char TICKET_DATA_TEMP_FILE[] = "TicketTmp.dat";

static const char TICKET_KEY_NAME[] = "Ticket";


int Ticket_Perst_Insert(seat_list_t  list,int schedule_id)
{
	FILE *fp = fopen(TICKET_DATA_FILE,"wb+");
	
	int rtn = 0;
	seat_list_t temp;
	seat_list_t pos;
	schedule_t sch;
	int sum = 0;

	ticket_t data;

	if(NULL == fp)
	{
		printf( "the file not exist!\n");
		return 0;
	}
	play_t buf;
	Schedule_Perst_SelectByID_ticket(schedule_id,&sch);

	Play_Perst_SelectByID(sch.play_id,&buf);
	
	int key = EntKey_Perst_GetNewKeys(TICKET_KEY_NAME,1);
	temp = list;
	pos = list->next;
	while(pos != temp)
	{
		sum++;

		data.id = EntKey_Perst_GetNewKeys(TICKET_KEY_NAME,1);
		data.schedule_id = schedule_id;
		data.seat_id = pos->data.id;
		data.price = buf.price;
		data.status = 0;
	pos = pos->next;
		rtn = fwrite(&data,sizeof(ticket_t),1,fp);
	}

	fclose(fp);
	return rtn;

}


int  Ticket_Perst_Rem(int schedule_id)
{
	if(rename(TICKET_DATA_FILE,TICKET_DATA_TEMP_FILE) < 0)
	{
		printf( "shan chu piao shi bai \n");
		return 0;
	}

	FILE *fpsour,*fpTarg;

	fpsour = fopen(TICKET_DATA_TEMP_FILE,"rb");
	if(NULL == fpsour)
	{
		printf( "Cannot open the file %s\n",TICKET_DATA_FILE);
		return 0;
	}

	fpTarg = fopen(TICKET_DATA_FILE,"wb");
	if(NULL == fpTarg)
	{
		printf( "Cannot open the file %s!\n",TICKET_DATA_TEMP_FILE);
		return 0;
	}

	int found = 0;
	ticket_t buf;
	while(!feof(fpsour))
	{
		if(fread(&buf,sizeof(ticket_t),1,fpsour))
		{
			if(buf.schedule_id == schedule_id)
			{
				found += 1;
				continue;
			}
			fwrite(&buf,sizeof(ticket_t),1,fpTarg);

		}
	}


	fclose(fpsour);
	fclose(fpTarg);


	remove(TICKET_DATA_TEMP_FILE);

	return found;
}



void Ticket_Perst_SelectAll(ticket_list_t list)
{
	ticket_node_t *newNode;
	ticket_t data;


	assert(NULL != list);

	List_Free(list,ticket_node_t);

	FILE *fp = fopen(TICKET_DATA_FILE,"rb");

	if(NULL == fp)
	{
		return ;
	}

	while(!feof(fp))
	{
		if(fread(&data,sizeof(ticket_t),1,fp))
		{
			newNode = (ticket_node_t *)malloc(sizeof(ticket_node_t));
			if(!newNode)
			{
				printf( "Waring ,Memory OverFlow !!!\n Cannot Load more Data into memory !!!\n");
				break;
			}
			newNode->data = data;

			List_AddTail(list,newNode);
		}
	}

	fclose(fp);

	return ;
}

int Ticket_Perst_SelByID(int id,ticket_t *buf)      //通过seat ID  找票
{
	int found = 0;
	ticket_t data;
	FILE *fp = fopen(TICKET_DATA_FILE,"rb");
	if(fp == NULL)
	{
		return 0;
	}
	while(!feof(fp))
	{
		if(fread(&data,sizeof(ticket_t),1,fp))
		{

			if(id == data.seat_id)
			{
				*buf = data;
				found = 1;
				break;
			}
		}
	}

	fclose(fp);


	return found;
}
int Ticket_Perst_SelByticketID(int ticket_id,ticket_t *buf)
{
	int count = 0;
	FILE *fp = fopen(TICKET_DATA_FILE,"rb");
	if(NULL == fp)
	{
		printf( " the file is not exit!!\n");
		return 0;
	}

	ticket_t data;
	while(!feof(fp))
	{
		if(fread(&data,sizeof(ticket_t),1,fp))
		{
			if(data.id == ticket_id)
			{
				*buf = data;
				count = 1;
				break;
			}
		}
	}

	fclose(fp);

	return count;
}
int Ticket_Perst_SelBySchID(int id,ticket_list_t list)   
{

	int count = 0;

	FILE *fp = fopen(TICKET_DATA_FILE,"rb");

	if(NULL == fp)
	{
		printf( "the file is not exit");
		return 0;
	}

	ticket_t data;
	ticket_node_t * newNode;

	while(!feof(fp))
	{
		if(fread(&data,sizeof(ticket_t),1,fp))
		{
			if(data.schedule_id == id)
			{
				count++;
				newNode = (ticket_node_t *)malloc(sizeof(ticket_node_t));
				newNode->data = data;
				List_AddTail(list,newNode);
			}
		}
	}

	fclose(fp);
	return count;
}

int Ticket_Perst_Update(const ticket_t *data)
{


	assert(NULL != data);
	int found = -1;
	FILE *fp = fopen(TICKET_DATA_FILE,"rb+");

	if(NULL == fp)
	{
		printf( "the file is not exit\n!");
		return -1;
	}
	
	ticket_t temp;
	while(!feof(fp))
	{
		if(fread(&temp,sizeof(ticket_t),1,fp))
		{
			if(temp.id == data->id)
			{
				fseek(fp,-((int)sizeof(ticket_t)),SEEK_CUR);
				found = 1;
				fwrite(data,sizeof(ticket_t),1,fp);
				break;
			}
		}
	}
	fclose(fp);
	return found;
}
