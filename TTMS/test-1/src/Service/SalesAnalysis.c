/*
 * salesanalysis.c
 *
 *  Created on: 2015年6月12日
 *      Author: Administrator
 */
#include <string.h>
#include <stdio.h>
#include "SalesAnalysis.h"
#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "../Common/list.h"


//获取剧目票房
int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list){
	assert(list != NULL);
	play_list_t playList;
	play_node_t *pos;
	salesanalysis_node_t * newNode;
	int sold = 0;
	
	List_Free(list,salesanalysis_node_t);
	List_Init(playList,play_node_t);
	Play_Srv_FetchAll(playList);

	List_ForEach(playList,pos){
		sold++;
		newNode = (salesanalysis_node_t *)malloc(sizeof(salesanalysis_node_t));
		newNode->data.end_date = pos->data.end_date;
		newNode->data.start_date = pos->data.start_date;
		strcpy(newNode->data.area,pos->data.area);
		newNode->data.play_id = pos->data.id;
		newNode->data.price = pos->data.price;
		newNode->data.duration = pos->data.duration;
		strcpy(newNode->data.name,pos->data.name);
		newNode->data.sales = Schedule_Srv_StatRevByPlay(pos->data.id,&newNode->data.totaltickets);
		List_AddTail(list,newNode);	
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

void SalesAnalysis_Srv_AddToSoftedList(salesanalysis_list_t list, salesanalysis_node_t * p) {
       
    salesanalysis_node_t *cur;   
   	if(list == NULL){
		List_AddTail(list,p);
	}     
	  
   	else{        
	   cur = list->next;       
	     while(cur != list){            
			if(p->data.sales > cur->data.sales)
				break;  
			cur = cur->next;      
		}      
		List_InsertBefore(cur,p);    
	}   
	return ;
}


//根据演出计划ID获取票房
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount){
	int value = 0;

	ticket_list_t list;
	ticket_node_t * p;
	
	*soldCount = 0;
	List_Init(list,ticket_node_t);
//haode          
	*soldCount = Ticket_Srv_FetchBySchID(list,schedule_id);
	//printf("\n\n\n%d\n\n\n",list->next->data.price);
	
	List_ForEach(list,p){
		//printf("dadasdasad d\n");
		sale_node_t * sale = (sale_node_t * )malloc(sizeof(sale_node_t));
		int ci = Sale_Srv_FetchByTicketID(p->data.id,sale);
		//printf("pr :fdsfdsfsdfdsfds %d  ",p->data.price);
		//printf("pr : %d.........%d..........",p->data.status,ci);
		if(p->data.status == 1&&sale->data.type == 1){
			(*soldCount)++;
			value+=p->data.price;
			//printf("pr : %d.........  ",p->data.price);
		}
	}
	List_Destroy(list,ticket_node_t);

	return value;

}

int Schedule_Srv_StatRevByPlay(int play_id,int *soldCount){
	int value=0,sold=0;
	schedule_list_t list;
	schedule_node_t * p;
	*soldCount = 0;
	List_Init(list,schedule_node_t);
	Schedule_Perst_SelectByPlay(list,play_id);
	//haode
	List_ForEach(list,p){
		value+=Ticket_Srv_StatRevBySchID(p->data.id,&sold);
		*soldCount = *soldCount + sold;
	}
	//printf("%d ",value);
	List_Destroy(list,schedule_node_t);

	return value;

}


int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id){
	int Count = 0;
	List_Free(list,ticket_node_t);
	//ticket_list_t tickList,ticcc;
	//List_Init(tickList,ticket_node_t);
	//gengai
	
	Count = Ticket_Perst_SelBySchID(schedule_id,list);
	//List_ForEach(list,ticcc){
	//	printf(" tick ::%d  \n",ticcc->data.status);
	//}
	
	if(Count<=0){
		//List_Destroy(list,ticket_node_t);
		return 0;
	}
	else{
		//printf("count = %d",Count);
		//list = tickList;
		//List_Free(list,ticket_node_t);
		return Count;
	}

}
//根据票ID获取销售记录
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){
	//wenti
	return Sale_Perst_SelByTicketID(ticket_id,sale);

}


//计算员工usrID在给定时间区间的销售额，返回销售额
int SalesAnalysis_Srv_CompSaleVal(int usrID, ttms_date_t stDate, ttms_date_t endDate){
	int amount = 0;

	sale_list_t saleList;
	sale_node_t* pSale;
	List_Init(saleList, sale_node_t);
	Sale_Perst_SelByID (saleList,usrID);

	List_ForEach(saleList, pSale){
		if(pSale->data.date.day<=endDate.day&&pSale->data.date.day>=stDate.day&&
		pSale->data.date.year<=endDate.year&&pSale->data.date.year>=stDate.year&&
		pSale->data.date.month<=endDate.month&&pSale->data.date.month>=stDate.month
		){
			amount += pSale->data.value;
		}
		
	}

	List_Destroy(saleList, sale_node_t);

	return amount;
}