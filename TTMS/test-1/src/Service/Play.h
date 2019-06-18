#ifndef PLAY_H_
#define PLAY_H_

typedef enum      //type
{
	PLAY_TYPE_FILE = 1,
	PLAY_TYPE_OPEAR = 2,
	PLAY_TYPE_CONCERT = 3
}play_type_t;


typedef enum        //rate
{
	PLAY_RATE_CHILD = 1,
	PLAY_RATE_TEENAGE = 2,
	PLAY_RATE_ADULT = 3
}play_rating_t;


typedef struct       //date
{
	int year;
	int month;
	int day;
}ttms_date_t;


typedef struct
{
	int        id;               //ju mu id
	char       name[30];        //ju mu ming zi
	play_type_t     type;        //lei xing 
	char      area[10];         //chu pin di qu
	play_rating_t      rating;     // deng ji 
	int        duration;             //shi chang 
	ttms_date_t      start_date;        //kai shi ri qi
	ttms_date_t      end_date;       //jie   shu   ri qi;
	int         price;             //piao jia
}play_t;

typedef struct play_node
{
	play_t data;
	struct play_node *next;
	struct play_node *prev;
}play_node_t,*play_list_t;


int Play_Srv_FetchAll(play_list_t list);     //huo qu quan bu ju mu


int Play_Srv_Add(play_t *data);            //tian jia xin ju mu

int Play_Srv_Modify(const play_t *data);    //xiu gai ju mu

int Play_Srv_DeleteByID(int id);           //geng ju id shan chu ju mu
int Play_Srv_FetchByID(int id,play_t *buf);     //   geng ju id huo qu ju mu

int Play_Srv_FetchByName(play_list_t list,char condt[]);

#endif
