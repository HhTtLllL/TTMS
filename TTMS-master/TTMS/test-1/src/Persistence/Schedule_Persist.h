
#ifndef SCHEDULE_PERSIST_H_
#define SCHEDULE_PERSIST_H_
#include"../Service/Schedule.h"


int Schedule_Perst_SelectByPlay(schedule_list_t list,int play_id);    //cong yan chu ji hua shu ju wen jian zhong zai ru yu zhi ding ju mu guna lian de yan chu ji hua xin xi , gou cheng lian biao 

int Schedule_Perst_Insert(schedule_t *data);   

int Schedule_Perst_Update(schedule_t *data); 

int Schedule_Perst_RemByID(int id);      //qu chu yan chu ji hua shu ju wen jian zhong zhi ding id de yan chu ji hua 

int Schedule_Perst_SelectByID(schedule_list_t list,int id);

int Schedule_Perst_SelectByID_ticket(int id,schedule_t *buf);

int Schedule_Perst_SelectAll(schedule_list_t list);

int Schedule_Perst_DeleBystduio_id(int studio_id);
#endif
