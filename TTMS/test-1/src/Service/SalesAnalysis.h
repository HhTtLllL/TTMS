/*
 *salesanalysis.h
 *
 *  Created on: 2015年5月8日
 *      Author: Administrator
 */
/*#ifndef SALESANALYSIS_H_
#define SALESANALYSIS_H_

#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "../Common/List.h"

typedef struct {
	int play_id; 	//剧目编号
	char name[31]; 	//剧目名称
	char area[9]; 	//剧目区域
	int duration; 	//以分钟为单位
	long totaltickets; //剧目票销售数量
	long sales; 	//电影票房
	int price; 		//剧目票价
	ttms_date_t start_date; 	//剧目上映日期
	ttms_date_t end_date; 	//剧目下映日期
} salesanalysis_t;

//双向链表
typedef struct salesanalysis_node {
	salesanalysis_t data;
	struct salesanalysis_node *next, *prev;
} salesanalysis_node_t, *salesanalysis_list_t;

//获取剧目票房
int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list);

//剧目票房排行
void SalesAnalysis_Srv_SortBySale(salesanalysis_list_t list);

//根据剧目ID获取票房
//int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount);
//根据演出计划ID获取票房
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount);

//根据演出计划ID获取票的数据
//int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id);

//根据票ID获取销售记录
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale);

#endif 
*/