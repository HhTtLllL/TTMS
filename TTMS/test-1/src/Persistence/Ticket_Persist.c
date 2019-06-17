#include"Ticket_Persist.h"
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
	FILE *fp = fopen(TICKET_DATA_FILE,"rb+");
	
	int rtn = 0;
	seat_list_t temp;
	seat_list_t pos;
	schedule_t sch;

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
		data.id = key;
		data.schedule_id = schedule_id;
		data.seat_id = pos->data.id;
		data.price = buf.price;
		data.status = 0;

		rtn = fwrite(&data,sizeof(ticket_t),1,fp);
	}

	
	fclose(fp);

	return rtn;

}

int  Tick_Perst_Rem(int schedule_id)
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
			if(buf.id == schedule_id)
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
