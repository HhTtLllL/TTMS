#include"../View/Ticket_UI.h"
#include"../Common/list.h"
#include"../Service/Ticket.h" 
#include"../Service/Schedule.h"


//#include"../Service/Schedule.h"
#include"../Service/Play.h"
static const int TICKET_PAGE_SIZE = 5;

#include<stdio.h>


void Ticket_UI_MgtEntry(int schedule_id)    // xian shi yu can shu dui ying de yan chu ji hua de xn xi
{   //schedule_id      piaos his yu piao xiang guan de yan chu ji hua de ID hao 

	int i,id;
	int yan_id;
	char choice;
	schedule_t buf;
	play_t data;


	Schedule_Srv_FetchByID_ticket(schedule_id,&buf);
	Play_Srv_FetchByID(buf.play_id,&data);

	printf( "========================================================\n");
	
	printf( "%5s %10s %10s %10s ","NAME","studio ID","Date","Time");
	printf( "%s  %d  %d %d %d  %d %d %d",data.name,buf.studio_id,buf.date.year,buf.date.month,buf.date.day,buf.time.hour,buf.time.minute,buf.time.second);

	printf( "[G]sheng cheng yan chu piao    [E]chong xin xheng cheng yan chu piao \n");
	setbuf(stdin,NULL);
	scanf("%c",&choice);
	getchar( );

	switch(choice)
	{
		case'G':
		case'g':
			Ticket_Srv_GenBatch(schedule_id);
			break;
		case'e':
		case'E':
			Ticket_Srv_deleteBatch(schedule_id);
			Ticket_Srv_GenBatch(schedule_id);
			break;
	}

}
