#include"Play_persist.h"
#include"../Service/Play.h"
#include"EntityKey_Persist.h"
#include"../Common/list.h"
#include"stdlib.h"
#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

static const char PLAY_DATA_FILE[] = "Play.dat"; 
static const char PLAY_DATA_TEMP_FILE[] = "PlayTmp.dat";
static const char PLAY_KEY_NAME[] = "Play";

int Play_Perst_SelectAll(play_list_t list)
{

	play_node_t *newNode;
	play_t data;
	int recCount = 0;     //yong lai ji lu zong ge shu

	assert(NULL != list);

	List_Free(list,play_node_t);

	FILE *fp = fopen(PLAY_DATA_FILE,"rb");

	if(NULL == fp)   return 0;

	while(!feof(fp))
	{
		if(fread(&data,sizeof(play_t),1,fp))
		{
			newNode = (play_node_t *)malloc(sizeof(play_node_t));

			if(!newNode)
			{
				printf("Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
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

int Play_Perst_Insert(play_t *data)
{
	assert(NULL != data);
	long key = EntKey_Perst_GetNewKeys(PLAY_KEY_NAME,1);

	if(key <= 0)   return 0;

	data->id = key;


	FILE *fp = fopen(PLAY_DATA_FILE,"ab");
	int rtn = 0;
	if(fp == NULL)
	{
		printf( "cannot open file %s!\n",PLAY_DATA_FILE);
		return 0;
	}

	rtn = fwrite(data,sizeof(play_t),1,fp);

	fclose(fp);

	return rtn;
}
int Play_Perst_RemByID(int id)
{
	if(rename(PLAY_DATA_FILE,PLAY_DATA_TEMP_FILE) < 0 )
	{
		printf( "cannot open file %s!\n",PLAY_DATA_FILE);
		return 0;
	}

	FILE *fpsuor,*fpTarg;

	fpsuor = fopen(PLAY_DATA_TEMP_FILE,"rb");

	if(NULL == fpsuor)
	{
		printf( "cannot open file %s!\n",PLAY_DATA_TEMP_FILE);
		return 0;
	}

	fpTarg = fopen(PLAY_DATA_FILE,"wb");

	if(NULL == fpTarg)
	{
		printf( "cannot open file %s\n!",PLAY_DATA_FILE);
		return 0;
	}

	play_t buf;

	int found = 0;
	while(!feof(fpsuor))
	{
		if(fread(&buf,sizeof(play_t),1,fpsuor))
		{
			if(id == buf.id)
			{
				found = 1;
				continue;
			}

			fwrite(&buf,sizeof(play_t),1,fpTarg);
		}

	}

	fclose(fpTarg);
	fclose(fpsuor);

	remove(PLAY_DATA_TEMP_FILE);

	return found;



}

int Play_Perst_SelectByID(int id,play_t *buf)
{
	assert(NULL != buf);
	FILE *fp = fopen(PLAY_DATA_FILE,"rb+");

	if(fp == NULL)
	{
		printf("the file not exist!\n");
		return 0;
	}

	play_t data;
	int found = 0;
	while(!feof(fp))
	{
		if(fread(&data,sizeof(play_t),1,fp))
		{
			if(id == data.id)
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

int Play_Perst_Update(const play_t *data)
{
	printf(" late  %s\n",data->name);
	assert(NULL != data);

	FILE *fp = fopen(PLAY_DATA_FILE,"rb+");
	if(fp == NULL )
	{
		printf("the file is not exist !\n");
		return 0;
	}

	play_t buf;

	int found = 0;

	while(!feof(fp))
	{
		if(fread(&buf,sizeof(play_t),1,fp))
		{
			if(buf.id == data->id)
			{
				fseek(fp,-((int)sizeof(play_t)),SEEK_CUR);
				fwrite(data,sizeof(play_t),1,fp);
				found = 1;
				break;
			}
		}
	}

	fclose(fp);

	return found;
}


int Play_Perst_SelectByName(play_list_t list,char condt[])
{
	play_node_t *newNode;
	play_t data;

	int rtn = 0;

	assert(NULL != list);

	List_Free(list,play_node_t);

	FILE *fp = fopen(PLAY_DATA_FILE,"rb");
	if(NULL == fp)   return 0;

	while(!feof(fp))
	{
		int flag = 0;
		if(fread(&data,sizeof(play_t),1,fp))
		{
			newNode = (play_node_t *)malloc(sizeof(play_node_t));
			newNode->data = data;

			if(!newNode)
			{
				printf( "Waring,Memory OverFlow!!!\nCannot Load more Data into memory!!!\n");
				break;
			}
			char s1[100];
			char s2[100];
			
			for(int i = 0;i < strlen(condt);i++)
			{
				s1[i] = condt[i];
			}
			for(int i = 0;i < strlen(newNode->data.name);i++)
			{
				s2[i] = newNode->data.name[i];
			}




			for(int i = 0;i < strlen(s1);i++)
			{
				s1[i] = toupper(s1[i]);
			}
			for(int i = 0;i < strlen(s2);i++)
			{
				s2[i] = toupper(s2[i]);
			}
			int j;
			for(int i = 0;i < strlen(s2);i++)
			{
				int temp = i;
				for(j = 0;j < strlen(s1);j++)
				{
					if(s2[temp] == s1[j])
					{
						temp++;
						if(j == (strlen(s1) - 1))
							flag = 1;
						continue;
					}
					else
					{
						break;
					}



				}

			}
			
/*			for(int i = 0;i < strlen(condt);i++)         第二版 模糊搜索
			{
				if(condt[i] == newNode->data.name[i])
				{
					continue;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			printf( " flag = %d \n",flag);*/
			if(flag == 1)
			{
				List_AddTail(list,newNode);
				rtn++;
			}

/*			if(!strcmp(newNode->data.name,condt))     第一版搜索
			{
				List_AddTail(list,newNode);
				rtn++;
			}
*/
		}
	}
	
	fclose(fp);

	return rtn;

}
int Play_Perst_screen(play_list_t list)
{
	struct mydate
	{
		unsigned year;
		unsigned month;
		unsigned day;
	};

	struct mydate Today( )
	{
		struct mydate today;
		time_t rawtime;
		struct tm *timeinfo;
		time ( &rawtime );
		timeinfo = localtime(&rawtime);
		today.year = timeinfo->tm_year + 1900;
		today.month = timeinfo->tm_mon + 1;
		today.day = timeinfo->tm_mday;
		return today;
	}

	struct mydate today = Today();

	if(rename(PLAY_DATA_FILE,PLAY_DATA_TEMP_FILE) < 0)
	{
		printf( "can not open file %s\n",PLAY_DATA_FILE);
		return 0;
	}

	FILE *fpsuor,*fpTarg;
	fpsuor = fopen(PLAY_DATA_TEMP_FILE,"rb");

	if(NULL == fpsuor)
	{
		printf( "cannot open file %s!\n",PLAY_DATA_TEMP_FILE);
		return 0;
	}

	fpTarg = fopen(PLAY_DATA_FILE,"wb");

	if(NULL == fpTarg)
	{
		printf( "cannot open file %s\n!",PLAY_DATA_FILE);
		return 0;
	}

	play_t buf;
	play_node_t *newNode;
	int found = 0;
	
 printf("%4d/%02d/%02d\n",today.year,today.month,today.day);

	while(!feof(fpsuor))
	{
		if(fread(&buf,sizeof(play_t),1,fpsuor))
		{
			if((buf.end_date.year >= today.year && buf.end_date.month >= today.month && buf.end_date.day >= today.day)  ||	
			   (buf.end_date.year > today.year)   || (buf.end_date.year >= today.year  && buf.end_date.month > today.month)
					)
			{
				  fwrite(&buf,sizeof(play_t),1,fpTarg);
				  found++;
			}
			else
			{
				newNode = (play_node_t *)malloc(sizeof(play_node_t));
				if(!newNode)
				{
					printf( "Warning, Memory OverFlow!!!\nCannot Load more Data into memory!!!\n");
				}
				newNode->data = buf;
				List_AddTail(list,newNode);
			}
		}
	}

	fclose(fpTarg);
	fclose(fpsuor);


	remove(PLAY_DATA_TEMP_FILE);

	return found;

}

