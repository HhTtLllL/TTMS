#include"../View/Play_UI.h"
#include"../Common/list.h"
#include"../Service/Play.h"


#include<stdio.h>

static const int PLAY_PAGE_SIZE = 5;

void Play_UI_MgtEntry(void)
{
	
	setbuf(stdin,NULL);
	int i,id;
	char choice;

	play_list_t head;
	play_node_t *pos;
	Pagination_t paging;

	List_Init(head,play_node_t);
	paging.offset = 0;
	paging.pageSize = PLAY_PAGE_SIZE;


	paging.totalRecords = Play_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head,paging);
	do
	{
		printf(
				"\n==================================================================\n");
		printf(
				"********************** Projection PLAy List **********************\n");

		printf( "%5s %20s %5s %10s %3s %3s %8s %8s %3s\n","ID","NAME","TYPE","AREA","RATING","DURATION","STARTDATA","ENDDATA","PRICE");
		printf( "----------------------------------------------------------\n");

		Paging_ViewPage_ForEach(head,paging,play_node_t,pos,i)
		{
			printf( "%5d %20s %5d %10s %3d %3d %4d %2d %2d %4d %2d %2d %4d\n",pos->data.id,pos->data.name,pos->data.type,pos->data.area,pos->data.rating,pos->data.duration,pos->data.start_date.year,pos->data.start_date.month,pos->data.start_date.day,pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day,pos->data.price);	
		}
	

		printf( "-----------------Total Recoeds: %2d-------------------Page %2d   %2d   -----\n",paging.totalRecords,Pageing_CurPage(paging),Pageing_TotalPages(paging));
	
		printf("*******************************************************************\n");

		printf("[P]revPage|[N]extPage | [A]dd|[D]elete|[U]pdate | [S]earch | [F]ix up | [R]eturn");
		printf( "\n=============================================\n");
		setbuf(stdin,NULL);
		printf( "your choice:");
		scanf( "%c",&choice);
		printf( "choice = %c\n",choice);
		getchar( );
		setbuf(stdin,NULL);
		switch(choice)
		{
			case'a':
			case'A':
				if(Play_UI_Add())
				{
					paging.totalRecords = Play_Srv_FetchAll(head);
					Paging_Locate_LastPage(head,paging,play_node_t);
				}
				break;
			case'd':
			case'D':
				setbuf(stdin,NULL);
				printf("Input the ID:");
				scanf( "%d",&id);
				getchar( );
				if(Play_UI_Delete(id))
				{
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head,paging,play_node_t);
				}
				break;
			case'u':
			case'U':
				printf("Input the ID:");
				scanf("%d",&id);
				getchar( );
				if(Play_UI_Modify(id))
				{
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head,paging,play_node_t);
				}
				break;
			case's':
			case'S':
				printf( "Input the ju mu ID:");
				scanf( "%d",&id);
				getchar( );
				if(Play_UI_Query(id))
				{
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head,paging,play_node_t);
				}
				break;
			case'f':
			case'F':
				printf( "Input the ID:");
				scanf( "%d",&id);
				getchar( );
				Schedule_UI_MgtEntry(id);
				break;
			case'p':
			case'P':
			/*	if (!Pageing_IsFirstPage(paging)) 
				{
					Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
				}*/
				break;
			case'n':
			case'N':
	/*			if (!Pageing_IsLastPage(paging)) 
				{
					Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
				}*/
				break;
			}
	}while(choice != 'r' && choice != 'R');

	List_Destroy(head,play_node_t);
}


int Play_UI_Add(void)
{
	play_t rec;
	int newRecCount = 0;
	char choice;

	do
	{
		printf( "\n==================================\n");
		printf( "************Add New Play*************\n");
		printf( "-----------------------------------\n");
		
		printf( "play name  : ");
		fflush(stdin);
		gets(rec.name);
		printf( "the  type of the play  (1 is the FILE  ||  2  is the  opear   ||   3   is the concert)");
		scanf( "%d",&(rec.type));
		getchar( );
		printf( "the play destination area  ?   ");
		gets(rec.area);
		printf( "the grade of the play    (1 or 2 or 3)  ");
		scanf( "%d",&rec.rating);
		getchar( );
		printf( "how long does the play last  ?");
		scanf( "%d",&rec.duration);
		getchar( );
		printf( "When does the play begin ? ");
		scanf( "%d%d%d",&rec.start_date.year,&rec.start_date.month,&rec.start_date.day);
		getchar( );
		printf( "When does the play end ? ");
		scanf( "%d%d%d",&rec.end_date.year,&rec.end_date.month,&rec.end_date.day);
		getchar( );
		printf( "how much is it ?");
		scanf( "%d",&rec.price);
		printf( "==============================\n");
		printf( "%p\n",&rec);
		if(Play_Srv_Add(&rec))
		{
			newRecCount += 1;
			printf( "the new play added successfilly!\n");
		}
		else	printf( "the new play added failed! \n");
		
		printf( "-----------------------------\n");

		printf( "[A]dd more,[R]eturn :");
		fflush(stdin);
		scanf("%c",&choice);
		getchar( );
	}while('a' == choice || 'A' == choice);

	return newRecCount;
}



int Play_UI_Delete(int id)
{
	setbuf(stdin,NULL);

	int rtn = 0;
	printf("\nid = %d\n",id);
	if(Play_Srv_DeleteByID(id))
	{
		printf( " the play deleted successfully!\n");
	}
	else
	{
		{
			printf("the play deleted faile!\n");
		}
	}
	return ;
}




int Play_UI_Modify(int id)
{
	play_t rec;
	play_t data;
	int rtn = 0;

	if(!Play_Srv_FetchByID(id,&rec))
	{
		printf("the play does not exist!\npPress [Enter] key to return !\n");
		getchar();
		return 0;
	}
	printf("\n==================================================\n");
	printf("**********************updata    projection   play *******************\n");
	printf("play  id :  %d",rec.id);
	printf("please enter new repertoire information \n");
	printf( "play name  : ");
		gets(rec.name);
		printf( "the  type of the play  (1 is the FILE  ||  2  is the  opear   ||   3   is the concert)");
		scanf( "%d",&(rec.type));
		getchar( );
		printf( "the play destination area  ?   ");
		gets(rec.area);
		printf( "the grade of the play    (1 or 2 or 3)  ");
		scanf( "%d",&rec.rating);
		getchar( );
		printf( "how long does the play last  ?");
		scanf( "%d",&rec.duration);
		getchar( );
		printf( "When does the play begin ? ");
		scanf( "%d%d%d",&rec.start_date.year,&rec.start_date.month,&rec.start_date.day);
		getchar( );
		printf( "When does the play end ? ");
		scanf( "%d%d%d",&rec.end_date.year,&rec.end_date.month,&rec.end_date.day);
		getchar( );
		printf( "how much is it ?");
		scanf( "%d",&rec.price);
		printf( "==============================\n");
		printf( "%s\n",rec.name);
Play_Srv_Modify(&rec);
return 1;
}

int Play_UI_Query(int id)
{
	play_t buf;
	int rtn = 0;
	if(Play_Srv_FetchByID(id,&buf))
	{

		printf( "find success!\n");
		printf( "Play Existence\n");
		rtn = 1;
	}else
	{
		printf("find Failure\n");
		printf( "Plays Not Existing\n");
	}

	return rtn;

}
