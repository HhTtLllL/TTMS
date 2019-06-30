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
int Schedule_Perst_Insert(schedule_t *data)
{
	assert(NULL != data);

	long key = EntKey_Perst_GetNewKeys(SCHEDULE_KET_NAME,1);

	if(key <= 0)
	{
		return 0;
	}

	data->id = key;


	FILE *fp = fopen(SCHEDULE_DATA_FILE,"ab");

	int rtn = 0;
	if(NULL == fp)
	{
		printf( "cannot opne file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}


	rtn = fwrite(data,sizeof(schedule_t),1,fp);

	fclose(fp);

	return rtn;
}

int Schedule_Perst_RemByID(int id)
{
	if(rename(SCHEDULE_DATA_FILE,SCHEDULE_DATA_TEMP_FILE) < 0)
	{
		printf("cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	FILE *fpsour,*fpTarg;

	fpsour = fopen(SCHEDULE_DATA_TEMP_FILE,"rb");
	if(NULL == fpsour)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	fpTarg = fopen(SCHEDULE_DATA_FILE,"wb");
	if(NULL == fpTarg)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_TEMP_FILE);
		return 0;
	}

	schedule_t buf;
	int found = 0;

	while(!feof(fpsour))
	{
		if(fread(&buf,sizeof(schedule_t),1,fpsour))
		{
			if(id == buf.id)
			{
				found = 1;
				continue;
			}
			fwrite(&buf,sizeof(schedule_t),1,fpTarg);
		}
	}

	fclose(fpsour);
	fclose(fpTarg);

	remove(SCHEDULE_DATA_TEMP_FILE);
	return found;
}


int Schedule_Perst_Update(schedule_t *data)
{
	assert(NULL != data);

	FILE *fp = fopen(SCHEDULE_DATA_FILE,"rb+");
	if(NULL == fp)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	schedule_t buf;
	int found = 0;
	while(!feof(fp))
	{
		if(fread(&buf,sizeof(schedule_t),1,fp))
		{
			if(buf.id == data->id)
			{
				data->play_id = buf.play_id;
				fseek(fp,-((int)sizeof(schedule_t)),SEEK_CUR);
				fwrite(data,sizeof(schedule_t),1,fp);
				found = 1;
				break;
			}
		}
	}

	fclose(fp);


	return found;
}

int Schedule_Perst_SelectByID(schedule_list_t list,int id)
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

			if(data.id == id)
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

int Schedule_Perst_SelectByID_ticket(int id,schedule_t *buf)
{
	assert(NULL != buf);

	int found = 0;
	schedule_t data;
	FILE *fp = fopen(SCHEDULE_DATA_FILE,"rb");
	

	if(NULL == fp)
	{
		printf( "the file cannot open!\n");
		return 0;
	}
	while(!feof(fp))
	{
		if(fread(&data,sizeof(schedule_t),1,fp))
		{
			if(data.id == id)
			{
				*buf = data;
				found = 1;
				break;
			}
		}
	}
	
	fclose(fp);

	return found;
}

int Schedule_Perst_SelectAll(schedule_list_t list)
{
	schedule_node_t *newNode;
	schedule_t data;

	int recCount = 0;

	assert(NULL != list);

	List_Free(list,schedule_node_t);

	FILE *fp = fopen(SCHEDULE_DATA_FILE,"rb");

	if(NULL == fp)    return 0;

	while(!feof(fp))
	{
		if(fread(&data,sizeof(schedule_t),1,fp))
		{
			newNode = (schedule_node_t *)malloc(sizeof(schedule_node_t));

			if(!newNode)
			{
				printf( "Waring ,Memory OverFlow!!!!\nCannot Load more Data into memory!!!\n");
				break;
			}

			newNode->data = data;
			List_AddTail(list,newNode);
			recCount++;
		}
	}
	fclose(fp);

	return recCount;
}


int Schedule_Perst_DeleBystduio_id(int studio_id)
{
		if(rename(SCHEDULE_DATA_FILE,SCHEDULE_DATA_TEMP_FILE) < 0)
	{
		printf("cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	FILE *fpsour,*fpTarg;

	fpsour = fopen(SCHEDULE_DATA_TEMP_FILE,"rb");
	if(NULL == fpsour)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	fpTarg = fopen(SCHEDULE_DATA_FILE,"wb");
	if(NULL == fpTarg)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_TEMP_FILE);
		return 0;
	}

	schedule_t buf;
	int found = 0;

	while(!feof(fpsour))
	{
		if(fread(&buf,sizeof(schedule_t),1,fpsour))
		{
			if(studio_id == buf.studio_id)
			{
				found = 1;
				continue;
			}
			fwrite(&buf,sizeof(schedule_t),1,fpTarg);
		}
	}

	fclose(fpsour);
	fclose(fpTarg);

	remove(SCHEDULE_DATA_TEMP_FILE);
	return found;
}

int Schedule_Perst_DeleByplayid(int play_id)
{
		if(rename(SCHEDULE_DATA_FILE,SCHEDULE_DATA_TEMP_FILE) < 0)
	{
		printf("cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	FILE *fpsour,*fpTarg;

	fpsour = fopen(SCHEDULE_DATA_TEMP_FILE,"rb");
	if(NULL == fpsour)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_FILE);
		return 0;
	}

	fpTarg = fopen(SCHEDULE_DATA_FILE,"wb");
	if(NULL == fpTarg)
	{
		printf( "cannot open file %s!\n",SCHEDULE_DATA_TEMP_FILE);
		return 0;
	}

	schedule_t buf;
	int found = 0;

	while(!feof(fpsour))
	{
		if(fread(&buf,sizeof(schedule_t),1,fpsour))
		{
			if(play_id == buf.play_id)
			{
				found = 1;
				continue;
			}
			fwrite(&buf,sizeof(schedule_t),1,fpTarg);
		}
	}

	fclose(fpsour);
	fclose(fpTarg);

	remove(SCHEDULE_DATA_TEMP_FILE);
	return found;
}

