#include"../View/Schedule_UI.h"
#include"../Common/list.h"
#include"../View/Ticket_UI.h"
#include"../Service/Schedule.h"


static const int SCHEDULE_PAGE_SIZE = 5;

#include<stdio.h>

void Schedule_UI_MgtEntry(int play_id)
{
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
		printf( "\n============================================\n");
		printf( "************************************Projection Schedue  List**************************\n");

		printf( "%20s  %20s%20s%20s%20s%20s","yan chu ID","shang ying ju mu","yan chu ding id","fang ying ri qi","fang ying shi jian","seat_count\n");
		printf( "---------------------------------------------------------------\n");
		Paging_ViewPage_ForEach(head,paging,schedule_node_t,pos,i)
		{
			printf("%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d",pos->data.id,pos->data.play_id,pos->data.studio_id,pos->data.date.year,pos->data.date.month,pos->data.date.day,pos->data.time.hour,pos->data.time.minute,pos->data.time.second,pos->data.seat_count);
		}

		printf("---totalRecords: %2d -----------Page %2d/%2d------\n",paging.totalRecords,Pageing_CurPage(paging),Pageing_TotalPages(paging));

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
				printf("yan chu ji hua ID:");
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
				printf( "yan chu ji hua ID: ");
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
				printf( "yu piao xiang guan de yan chu ji hua de ID :");
				scanf( "%d",&schedule_id);
				getchar( );
				Ticket_UI_MgtEntry(schedule_id);
				break;

		}
	}while(choice != 'r' && choice != 'R');
	List_Destroy(head,schedule_node_t);




}

int Schedule_UI_Add(int play_id)
{
	schedule_t rec;
	int newRecCount  = 0;
	char choice;

	do
	{
		printf( "\n================================================\n");
		printf( "********************************Add New Projection Schedule*************************\n");
		printf( "------------------------------------------------------------\n");
		
		setbuf(stdin,NULL);
		
		rec.play_id = play_id;
		printf( "studio ID:");
		scanf( "%d",&rec.studio_id);
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



