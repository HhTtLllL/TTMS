#include"../View/Schedule_UI.h"
#include"../Common/list.h"
#include"../View/Ticket_UI.h"
#include"../Service/Schedule.h"
#include"../Service/Studio.h"

static const int SCHEDULE_PAGE_SIZE = 5;

#include<stdio.h>

void Schedule_UI_MgtEntry(int play_id)
{
	system("clear");
	int schedule_id;
	int i,id;
	int yan_id;
	char choice;

	schedule_list_t head;
	schedule_node_t *pos;
	Pagination_t paging;

	List_Init(head,schedule_node_t);  //chu  shi hua lian biao 

	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;

	paging.totalRecords = Schedule_Srv_FetchByPlay(head,play_id);
	Paging_Locate_FirstPage(head,paging);


	do
	{
		printf( "=================================================================================================\n");
		printf( "*****************************************Projection Schedue  List*******************************\n");

		printf( "%s  %10s    %10s    %15s    %15s    %15s","Schedule ID","Play ID","Studio ID","fang ying ri qi","fang ying shi jian","seat_count\n");
		printf( "-------------------------------------------------------------------------------------------------\n");
		Paging_ViewPage_ForEach(head,paging,schedule_node_t,pos,i)
		{
			printf("%3d                %3d       %3d              %d.%2d.%2d           %d:%2d:%2d                  %3d\n",pos->data.id,pos->data.play_id,pos->data.studio_id,pos->data.date.year,pos->data.date.month,pos->data.date.day,pos->data.time.hour,pos->data.time.minute,pos->data.time.second,pos->data.seat_count);
		}

		printf("---totalRecords: %2d ------------------------------------------Page %2d/%2d------------------------\n",paging.totalRecords,Pageing_CurPage(paging),Pageing_TotalPages(paging));

		printf("[P]revPage  [N]extPage [A]dd [U]pdate [D]elete [T]icket [R]eturn");

		printf("Your Choice:");
		setbuf(stdin,NULL);
		scanf("%c",&choice);
		getchar( );

		switch(choice)
		{
			case'a':
			case'A':
				if(Schedule_UI_Add(play_id))
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(head,play_id);
					Paging_Locate_LastPage(head,paging,schedule_node_t);
				}
				break;
			case'd':
			case'D':
				printf("Schedule ID:");
				scanf( "%d",&yan_id);
				getchar( );
				if(Schedule_UI_Delete(yan_id))
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(head,play_id);
					List_Paging(head, paging, schedule_node_t);
				}
				break;
			case'U':
			case'u':
				printf( "Schedule ID: ");
				scanf( "%d",&yan_id);
				getchar( );
				if(Schedule_UI_Modify(yan_id))
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(head,play_id);
					List_Paging(head, paging, schedule_node_t);
				}
				break;
			case't':
			case'T':
				printf( "Schedule ID :");
				scanf( "%d",&schedule_id);
				getchar( );
				Ticket_UI_MgtEntry(schedule_id);
				break;

		}
	}while(choice != 'r' && choice != 'R');
	List_Destroy(head,schedule_node_t);




}

void Schedule_UI_ListAll(void)
{
	system("clear");
	int i;
	char choice;

	char play_name[50];
	schedule_list_t list;
	List_Init(list,schedule_node_t);
	play_t play;
	studio_t studio; 
	schedule_node_t *pos;
	Pagination_t paging;

	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;

	paging.totalRecords = Schedule_Srv_FetchByAll(list);
	Paging_Locate_FirstPage(list,paging);

	do
	{
		printf( "\n===========================================================\n");
		printf( "*********************Inquiry Performance*********************\n");
		Paging_ViewPage_ForEach(list,paging,schedule_node_t,pos,i)
		{
			//if(i % paging.pageSize != 0)
			{
				printf( "%5s %20s %5s %10s %3s %3s %8s %8s %3s\n","ID","NAME","TYPE","AREA","RATING","DURATION","STARTDATA","ENDDATA","PRICE");
				Play_Srv_FetchByID(pos->data.play_id,&play);
				printf( "%5d %20s %5d %10s %3d %3d %4d %2d %2d %4d %2d %2d %4d\n",play.id,play.name,play.type,play.area,play.rating,play.duration,play.start_date.year,play.start_date.month,play.start_date.day,play.end_date.year,play.end_date.month,play.end_date.day,play.price);	
				Studio_Srv_FetchByID(pos->data.studio_id,&studio);
				printf("%5s  %18s  %10s  %10s  %10s\n", "ID", "Name", "Rows Count","Columns Count", "Seats Count");
				printf("%5d  %18s  %10d  %10d  %10d\n", studio.id,studio.name,studio.rowsCount,studio.colsCount,studio.seatsCount);
			}
		}

		printf( "--------------Total Records : %2d ----------------------Page %2d / %2d-----\n",paging.totalRecords,Pageing_CurPage(paging),Pageing_TotalPages(paging));
		printf( "===============================================================================\n");
		printf( "[R]eturn   [N]ext     [P]rev       [Q]ry");
		printf( "\n**********************************************************************\n");

		printf( "Your choice:");
		
		setbuf(stdin,NULL);

		scanf( "%c",&choice);
		getchar();

		switch(choice)
		{
			case'n':
			case'N':
				setbuf(stdin,NULL);
				if(!Pageing_IsLastPage(paging))
				{
					Paging_Locate_OffsetPage(list,paging,1,schedule_node_t);
				}
				break;
			case'P':
			case'p':
				setbuf(stdin,NULL);
				if(!Pageing_IsFirstPage(paging))
				{
					Paging_Locate_OffsetPage(list,paging,-1,schedule_node_t);
				}
				break;
			case'Q':
			case'q':
				setbuf(stdin,NULL);
				printf( "please input the name you want to find :");
				gets(play_name);
				Schedule_UI_Qry(play_name);
				break;
			default:
				printf( "worry answer");
		}
	}while(choice != 'R' && choice != 'r');

	List_Destroy(list,schedule_node_t);

	return 0;

}

int Schedule_UI_Qry(char *play_name)
{
	int rtn = 0;
	play_list_t list;
	schedule_list_t list_s;
	
	List_Init(list,play_node_t);
	List_Init(list_s,schedule_node_t);

	
	Play_Srv_FetchByName(list,play_name);
	play_list_t temp = list;

	list = list->next;

	while(list != temp)
	{
		Schedule_Srv_FetchByPlay(list_s,list->data.id);
		schedule_list_t temp_s = list_s;
	
		list_s = list_s->next;

	
		while(list_s != temp_s)
		{
			rtn++;
			printf( "%s %10s %10s %20s %20s %20s","Play ","Play Time  ","Studio ID ","fang ying ri qi","fang ying shi jian","seat_count\n");
			printf("%6s %3d %3d %3d %3d %3d %3d %3d %3d %3d\n",list->data.name,list->data.duration,list_s->data.studio_id,list_s->data.date.year,list_s->data.date.month,list_s->data.date.day,list_s->data.time.hour,list_s->data.time.minute,list_s->data.time.second,list_s->data.seat_count);
			list_s = list_s->next;
		}
list = list->next;
	}

	printf("please press Enter !\n");
	getchar();

	return rtn;
}
int Schedule_UI_Add(int play_id)
{
	system("reset");
	schedule_t rec;
	int newRecCount  = 0;
	char choice;

	do
	{
		studio_t buf;
		printf( "\n================================================\n");
		printf( "********************************Add New Projection Schedule*************************\n");
		printf( "------------------------------------------------------------\n");
		
		setbuf(stdin,NULL);
		
		rec.play_id = play_id;
		while(1)
		{
			printf( "studio ID:");
			scanf( "%d",&rec.studio_id);
			if(Studio_Srv_FetchByID(rec.studio_id,&buf))
			{
					break;
			}
			else
			{			
				printf("the studio is not exist!\n");
				continue;
			}
			
		}

		
		printf( "Screening Date:");
		scanf( "%d%d%d",&rec.date.year,&rec.date.month,&rec.date.day);
		printf( "show time :");
		scanf( "%d%d%d",&rec.time.hour,&rec.time.minute,&rec.time.second);
		printf( "seat count :");
		scanf( "%d",&rec.seat_count);
		
		setbuf(stdin,NULL);

		printf("==================================================================================\n");

		if(Schedule_Srv_Add(&rec))
		{
			newRecCount += 1;
			printf( "the new Schedule successfully!\n");
		}
		else
		{
			printf( "the new Schedule failed!\n");
		}

		printf( "-------------------------------------------\n");

		printf( "[A]dd more  [R]eturn:");

		setbuf(stdin,NULL);

		scanf( "%c",&choice);
		getchar( );
	}while('a' == choice || 'A' == choice);


	return newRecCount;

}


int Schedule_UI_Delete(int play_id)
{
	int rtn = 0;

	if(Schedule_Srv_DeleteByID(play_id))
	{
		printf( "the show is deleted successfully!\n");
		rtn = 1;
	}
	else
	{
		printf( "the show is deleted failed!\n");
	}

	return rtn;
}


int Schedule_UI_Modify(int id)
{
   	 schedule_list_t list;
	 schedule_t rec;
	 int rtn = 0;

	 List_Init(list,schedule_node_t);
	 if(!Schedule_Srv_FetchByID(list,id))
	 {
		 printf( "the schedule does not exist!\n[Enter] key to return \n");
		 getchar( );
		 return 0;
	 }

	printf( "\n ===========================================================\n");
	printf( "*****************************Update Project Schedule ********************\n");
	printf( "-----------------------------------------------------------------\n");
	
	rec.id = id;
	printf( "Enter modify data: ");
	printf( "studio ID:");
	scanf( "%d",&rec.studio_id);
	printf( "Screening Date:");
	scanf( "%d%d%d",&rec.date.year,&rec.date.month,&rec.date.day);
	printf( "show time :");
	scanf( "%d%d%d",&rec.time.hour,&rec.time.minute,&rec.time.second);
	printf( "seat count :");
	scanf( "%d",&rec.seat_count);

	printf( "------------------------------------------\n");
	if(Schedule_Srv_Modify(&rec))
	{
		rtn = 1;
		printf( "the scheudle data uodata successfully!\npress[Enter] key to return!\n");
	}
	else
	{
		printf( "the scheudele data update failed!\npress [Enter] key to return !\n");
	}

	getchar();
	return rtn;


	return 1;

}



