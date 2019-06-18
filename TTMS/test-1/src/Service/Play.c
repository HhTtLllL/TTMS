#include"Play.h"
#include"../Persistence/Play_persist.h"
#include<stdlib.h>
#include<assert.h>


int Play_Srv_FetchAll(play_list_t list)     //du qu wen jian zhong de suo you ju mu
{
	return Play_Perst_SelectAll(list);
}

int Play_Srv_Add(play_t *data)
{
	return Play_Perst_Insert(data);
}

int Play_Srv_DeleteByID(int id)
{
	return Play_Perst_RemByID(id);
}

int Play_Srv_FetchByID(int id,play_t * buf)
{
	return Play_Perst_SelectByID( id,buf);
}

int Play_Srv_Modify(const play_t *data)
{
	return Play_Perst_Update(data);
}

int Play_Srv_FetchByName(play_list_t list,char condt[])
{
	return Play_Perst_SelectByName(list,condt);
}
