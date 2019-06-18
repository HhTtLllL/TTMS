#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include"Play.h"

typedef struct 
{
	int hour;
	int minute;
	int second;
}ttms_time_t;

typedef struct 
{
	int id;          // yan chu ji hua id
	int play_id;        //shang ying ju mu id
	int studio_id;             // yan chu ding id
	ttms_date_t date;               // fang ying ri qi 
	ttms_time_t time;               //fang ying shi jian 
	int seat_count;                 //zuo   wei   shu
}schedule_t;


typedef  struct schedule_node
{
	schedule_t data;
	struct schedule_node *next;
	struct schedule_node *prev;
}schedule_node_t,*schedule_list_t;

int Schedule_Srv_FetchByPlay(schedule_list_t, int play_id);    //geng ju ju mu id huo qu yan chu ji hua 

int Schedule_Srv_Add(schedule_t *data);      

int Schedule_Srv_Modify(const schedule_t *data);

int Schedule_Srv_DeleteByID(int id);   
 
int Schedule_Srv_FetchByAll(schedule_list_t list);
 
int Schedule_Srv_FetchByID(schedule_list_t head ,int id);

int Schedule_Srv_FetchByID_ticket(int id,schedule_t *buf);


#endif
