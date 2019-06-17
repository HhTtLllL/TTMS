#ifndef TICKET_H_
#define TICKET_H_
#include"Schedule.h"

typedef enum
{
	TICKET_AVL = 0,   //dai shou
	TICKET_SOLD = 1,    //yi shou
	TICKET_RESV = 9    //yu  liu 
}ticket_status_t;

typedef struct 
{
	int id;          //paio   ID
	int schedule_id;     //yan hu ji hua ID
	int seat_id;       //zuo  wei    ID
	int price;        //piao jia 
	ticket_status_t status;      //piao zhuang tai 
}ticket_t;

typedef struct ticket_node
{
	ticket_t data;
	struct ticket_node *next,*prev;
}ticket_node_t,* ticket_list_t;



int Schedule_Srv_FetchByID_ticket(int id,schedule_t *buf);    //gen ju ID huo qu yan chu jia hua han shu

void Ticket_Srv_GenBatch(int schedule_id);       //pi liang zeng jia wen jian ticket zhong de piao de ge shu

void Ticket_Srv_deleteBatch(int schedule_id);    //shan chu yan chu piao han shu


#endif

