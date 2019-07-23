#ifndef PLAYPERSIST_H_
#define PLAYPERSIST_H_

#include"../Service/Play.h"

int Play_Perst_SelectAll(play_list_t list);  //cong wen jian zhong zai ru suo you ju mu xin xin ,jia zai dao list shang 

int Play_Perst_Insert(play_t *data);   //xiang ju mu shu ju wen jian de mo wei tian jia yi tiao xin de ju mu xin xi

int Play_Perst_Update(const play_t *data);      //geng xin wen jian zhong de yi tiao ju mu xin xi   //can shu wei : dai xiu gai de ju mu xin xi

int Play_Perst_RemByID(int id);     //qu chu wen jian zhong de zhi ding de ID xin xi

int Play_Perst_SelectByID(int id,play_t *buf);    //zai wen jian zhong zai ru zhi ding ID de ju mu xin xi dao buf zhong 

int Play_Perst_screen(play_list_t list);
#endif
