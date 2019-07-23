#ifndef SALE_H_
#define SALE_H_

#include"Ticket.h"

typedef enum
{
	SALE_SELL = 1,  //买票
	SALE_REFOUND = -1   //退票
}sale_type_t;

typedef struct 
{
	long id;     //销售ID
	int user_id;    //售票员ID   shou p
	int ticket_id;    //票ID
	ttms_date_t date;    //处理日期
	ttms_time_t time;    //处理时间 
	int value;      //票价
	sale_type_t type;     //交易类型
}sale_t;


typedef struct sale_node
{
	sale_t data;
	struct sale_node *next;
	struct sale_node *prev;
}sale_node_t,*sale_list_t;



int Sale_Srv_Add(const sale_t *data);

#endif
