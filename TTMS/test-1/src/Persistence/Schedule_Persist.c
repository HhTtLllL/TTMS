#include"Schedule_Persist.h"
#include"../Service/Schedule.h"
#include"EntityKey_Persist.h"
#include"../Common/list.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<assert.h>

static const char SCHEDULE_DATA_FILE[] = "Schedule.dat";
static const char SCHEDULE_DATA_TEMP_FILE[] = "ScheduleTmp.dat";
static const char SCHEDULE_KET_NAME[] = "Schedule";



int Schedule_Perst_SelectByPlay(schedule_list_t list,int play_id)
{
	schedule_node_t *newNode;
	schedule_t data;
	int recCount = 0;
	assert(NULL != list);

	List_Free(list,schedule_node_t);

	FILE *fp = fopen(SCHEDULE_DATA_FILE,"rb");

	if(NULL == fp)
	{
		return 0;
	}

	while(!feof(fp))
	{
		if(fread(&data,sizeof(schedule_t),1,fp))
		{
			newNode = (schedule_node_t *)malloc(sizeof(schedule_node_t));
			if(!newNode)
			{
				printf("Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
				break;
			}

			if(data.play_id == play_id)
			{
				newNode->data = data;
				List_AddTail(list,newNode);
				recCount++;
			}
		}
	}

	fclose(fp);

	return recCount;
}

