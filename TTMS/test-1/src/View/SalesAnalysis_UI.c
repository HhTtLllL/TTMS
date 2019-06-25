#include "SalesAnalysis_UI.h"
#include "../Service/SalesAnalysis.h"
#include "../Common/list.h"
#include "../Service/Account.h"
#include "../Service/Ticket.h"
#include "../Service/Play.h"
#include "../Service/Schedule.h"
#include "../Service/Sale.h"

#include <stdio.h>
#include <stdlib.h>
static const int SALESANALYSIS_PAGE_SIZE = 5;
//统计票房界面
void SalesAanalysis_UI_MgtEntry(){
	if(gl_CurUser.type==USR_ADMIN||gl_CurUser.type==USR_ANOMY){
        printf("you can't join in there!please input the [Enter]");
        getchar();
		return 0;
	}
    int i;
    char choice;
	
    salesanalysis_list_t head;
    salesanalysis_node_t *pos;
    Pagination_t paging;

    List_Init(head,salesanalysis_node_t);
    paging.offset = 0;
	paging.pageSize = SALESANALYSIS_PAGE_SIZE;

    paging.totalRecords = SalesAnalysis_Srv_StaticSale(head);
	Paging_Locate_FirstPage(head, paging);
    SalesAnalysis_Srv_SortBySale(head);
	salesanalysis_node_t * newNode;

    do{
        
        printf(
				"\n===========================================================================\n");
		printf(
				"************************** Projection Room List ***************************\n");
		printf("%-3s|%-11s|%-11s|%-3s|%-6s|%-8s|%-5s|%-10s|%-10s\n", "ID", "Name", "area","len","ticket",
				"sales", "price","start_date","end_date");
		printf(
				"---------------------------------------------------------------------------\n");
		//��ʾ����
		Paging_ViewPage_ForEach(head, paging, salesanalysis_node_t, pos, i){
			printf("%-3d|%-11s|%-11s|%-3d|%-6d|%-8d|%-5d|%4d/%2d/%2d|%4d/%2d/%2d\n", pos->data.play_id,
					pos->data.name, pos->data.area, pos->data.duration,pos->data.totaltickets,pos->data.sales,
					pos->data.price,pos->data.start_date.year,pos->data.start_date.month,pos->data.start_date.day,pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day);
		}

		printf(
				"------- Total Records:%2d ------------------------------ Page %2d/%2d --------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"***************************************************************************\n");
		printf(
				"[P]revPage        |         [N]extPage         |           [R]eturn");
		printf(
				"\n===========================================================================\n");
		printf("Your Choice:");
		setbuf(stdin,NULL);
		scanf("%c", &choice);
		getchar();
		setbuf(stdin,NULL);

        
        switch(choice)
        {
            case 'p':
		    case 'P':
			    if (!Pageing_IsFirstPage(paging)) {
				    Paging_Locate_OffsetPage(head, paging, -1,salesanalysis_node_t);
			    }
			    break;
		    case 'n':
            case 'N':
                if (!Pageing_IsLastPage(paging)) {
                    Paging_Locate_OffsetPage(head, paging, 1, salesanalysis_node_t);
                }
                break;
        }    
    }while (choice != 'r' && choice != 'R');
    setbuf(stdin,NULL);
	List_Destroy(head,salesanalysis_node_t);
}
