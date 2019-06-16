#include"Schedule.h"
#include"../Persistence/Schedule_Persist.h"
#include<stdlib.h>
#include<assert.h>

int Play_Srv_FetchByPlay(schedule_list_t head ,int play_id)
{
	return Schedule_Perst_SelectByPlay(head,play_id);
}
