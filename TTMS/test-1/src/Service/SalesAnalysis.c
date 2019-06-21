/*
 * salesanalysis.c
 *
 *  Created on: 2015年6月12日
 *      Author: Administrator
 */
/*#include <string.h>
#include <stdio.h>
#include "SalesAnalysis.h"
//#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "../Common/list.h"

//获取剧目票房
int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list){
	play_list_t playList;
	play_node_t *pos;
	salesanalysis_node_t *newNode;
	int sold = 0;
	List_Free(list,salesanalysis_node_t);
	List_Init(playList,play_node_t);
	Play_Srv_FetchAll(playList);
	List_ForEach(playList,pos){
		newNode->data.end_date = pos->data.end_date;
		newNode->data.start_date = pos->data.start_date;
		strcpy(newNode->data.area,pos->data.area);
		newNode->data.play_id = pos->data.id;
		newNode->data.price = pos->data.price;
		newNode->data.duration = pos->data.duration;
		Ticket_Srv_StatRevBySchID(pos->data.id, newNode->data.totaltickets);
		strcpy(newNode->data.name,pos->data.name);
		//newNode->data.sales
		List_AddTail(list,newNode);
	//wen ti 	
	}
	List_Destroy(playList,play_node_t);
	return sold;

}

//剧目票房排行
void SalesAnalysis_Srv_SortBySale(salesanalysis_list_t list){
	assert(list!=NULL);
       salesanalysis_list_t listLeft;
       salesanalysis_list_t p;
       if(List_IsEmpty(list)){
              return ;
       }
       else{
              list->prev->next = NULL;
              listLeft = list->next;
              list->next = list->prev = list;
              
              while(listLeft != NULL){
                     p = listLeft;
                     listLeft = listLeft->next;
                     SalesAnalysis_Srv_AddToSoftedList(list,p);   
              } 
       }
       return ;
}

void SalesAnalysis_Srv_AddToSoftedList(salesanalysis_list_t list, salesanalysis_list_t node) {
       
       salesanalysis_list_t p ;
       assert(list!=NULL && node!=NULL);
       if(List_IsEmpty(list)){
              List_AddTail(list,node);
       }
       else{
              p = list->next;
              while(p!=list&&p->data.sales < node->data.sales){
                     p=p->next;
              }
              List_InsertBefore(p,node);
       }
}


//根据演出计划ID获取票房
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount){
	int value;
	ticket_list_t list;
	ticket_node_t * sale;
	sale_node_t p;
	*soldCount = 0;
	List_Init(list,ticket_node_t);
	*soldCount = Ticket_Srv_FetchBySchID(list,schedule_id);
	List_ForEach(list,sale){
		Sale_Srv_FetchByTicketID(sale->data.id,&p);
		if(sale->data.status == 1){
			(*soldCount)++;
			value+=p->data.price;
		}
	}
	List_Destroy(list,ticket_node_t);

	return value;

}

int Schedule_Srv_StatRevByPlay(int play_id,int *soldCount){
	int value,sold;
	schedule_list_t list;
	schedule_node_t * p;
	*soldCount = 0;
	List_Init(list,schedule_node_t);
	Schedule_Perst_SelectByPlay(list,play_id);
	List_ForEach(list,p){
		(*soldCount) = *soldCount + sold;
		value+=Ticket_Srv_StatRevBySchID(p->data.id,&sold);
	}
	List_Destroy(list,ticket_node_t);

	return value;

}


int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id){
	int Count = 0;
	ticket_list_t tickList;
	List_Free(list,ticket_node_t);
	Count = Ticket_Perst_SelectBySchID(tickList,schedule_id);
	if(Count<=0){
		List_Destroy(tickList,ticket_node_t);
		return 0;
	}
	else{
		
		return Count;
	}

}
//根据票ID获取销售记录
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){
	//wenti
	return sale_Perst_SelByTicketID(ticket_id);

}
*/