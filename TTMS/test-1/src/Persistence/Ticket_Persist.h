#ifndef TICKET_PERSIST_H_
#define TICKET_PERSIST_H_

#include"../Service/Ticket.h"
#include"../Service/Schedule.h"

int Schedule_Perst_SelectByID(int id,schedule_t *buf);   //  cong wen jian zhong zai ru zhi ding ID de yan chu ji hua 


void Ticket_Perst_Insert(ticket_list_t list,int schedule_id);      //zai piao xin xi wen jian ticket.dat zhong pi liang jia ru list lian biao shang e suo you piao de xin xi


void Tick_Perst_Rem(int schedule_id);    //pi liang shan chu yan chu ji hua de ID hao

#endif