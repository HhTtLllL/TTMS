/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_01		 
* File name: Studio_Persist.c			  
* Description : 演出厅用例持久化层	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#include "Studio_Persist.h"
#include "../Service/Studio.h"
#include "EntityKey_Persist.h"	 
#include "../Common/list.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>


static const char STUDIO_DATA_FILE[] = "Studio.dat"; //演出厅文件名常量 
static const char STUDIO_DATA_TEMP_FILE[] = "StudioTmp.dat"; //演出厅临时文件名常量 
static const char STUDIO_KEY_NAME[] = "Studio"; //演出厅名常量 

/*
标识符：TTMS_SCU_Studio_Perst_Insert
函数功能：用于向文件中添加一个新演出厅数据。
参数说明：data为studio_t类型指针，是需要添加的演出厅数据结点。
返 回 值：整型，表示是否成功添加了演出厅的标志。
*/ 
int Studio_Perst_Insert(studio_t *data) {	 
	assert(NULL!=data);

	////以下是新设计方案方案添加的代码
	////以下是新设计方案方案添加的代码
	long key = EntKey_Perst_GetNewKeys(STUDIO_KEY_NAME, 1); //为新演出厅分配获取
	if(key<=0)			//主键分配失败，直接返回
		return 0;
	data->id = key;		//赋给新对象带回到UI层
	////以上是新设计方案方案添加的代码
	////以上是新设计方案方案添加的代码



	FILE *fp = fopen(STUDIO_DATA_FILE, "ab");
	int rtn = 0;
	if (NULL == fp) {
		printf("Cannot open file %s!\n", STUDIO_DATA_FILE);
		return 0;
	}

	rtn = fwrite(data, sizeof(studio_t), 1, fp);

	fclose(fp);
	return rtn;
}

/*
标识符：TTMS_SCU_Studio_Perst_Update 
函数功能：用于在文件中更新一个演出厅数据。
参数说明：data为studio_t类型指针，是需要更新的演出厅数据结点。
返 回 值：整型，表示是否成功更新了演出厅的标志。
*/
int Studio_Perst_Update(const studio_t * data) {
	assert(NULL!=data);

	FILE *fp = fopen(STUDIO_DATA_FILE, "rb+");
	if (NULL == fp) {
		printf("Cannot open file %s!\n", STUDIO_DATA_FILE);
		return 0;
	}

	studio_t buf;
	int found = 0;

	while (!feof(fp)) {
		if (fread(&buf, sizeof(studio_t), 1, fp)) {
			if (buf.id == data->id) {
				fseek(fp, -((int)sizeof(studio_t)), SEEK_CUR);
				fwrite(data, sizeof(studio_t), 1, fp);
				found = 1;
				break;
			}

		}
	}
	fclose(fp);

	return found;
}

/*
标识符：TTMS_SCU_Studio_Perst_DeleteByID
函数功能：用于从文件中删除一个演出厅的数据。
参数说明：第一个参数ID为整型，表示需要载入数据的演出厅ID；第二个参数buf为studio_t指针，指向载入演出厅数据的指针。
返 回 值：整型，表示是否成功删除了演出厅的标志。
*/
int Studio_Perst_DeleteByID(int ID) {

	//将原始文件重命名，然后读取数据重新写入到数据文件中，并将要删除的实体过滤掉。

	//对原始数据文件重命名
	
	
	if(rename(STUDIO_DATA_FILE, STUDIO_DATA_TEMP_FILE)<0){
		printf("Cannot open file %s!\n", STUDIO_DATA_FILE);
		return 0;
	}

	FILE *fpSour, *fpTarg;
	fpSour = fopen(STUDIO_DATA_TEMP_FILE, "rb");
	if (NULL == fpSour ){
		printf("Cannot open file %s!\n", STUDIO_DATA_FILE);
		return 0;
	}

	fpTarg = fopen(STUDIO_DATA_FILE, "wb");
	if ( NULL == fpTarg ) {
		printf("Cannot open file %s!\n", STUDIO_DATA_TEMP_FILE);
		return 0;
	}


	studio_t buf;

	int found = 0;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(studio_t), 1, fpSour)) {
			if (ID == buf.id) {
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(studio_t), 1, fpTarg);
		}
	}

	fclose(fpTarg);
	fclose(fpSour);

	//删除临时文件
	remove(STUDIO_DATA_TEMP_FILE);
	Seat_Srv_DeleteAllByRoomID(ID);//删除已有的座位信息
	
	return found;
}

/*
标识符：TTMS_SCU_Studio_Perst_SelectByID 
函数功能：用于从文件中载入一个演出厅的数据。
参数说明：第一个参数ID为整型，表示需要载入数据的演出厅ID；第二个参数buf为studio_t指针，指向载入演出厅数据的指针。
返 回 值：整型，表示是否成功载入了演出厅的标志。
*/
int Studio_Perst_SelectByID(int ID, studio_t *buf) {
	assert(NULL!=buf);

	FILE *fp = fopen(STUDIO_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}

	studio_t data;
	int found = 0;

	while (!feof(fp)) {
		if (fread(&data, sizeof(studio_t), 1, fp)) {
			if (ID == data.id) {
				*buf = data;
				found = 1;
				break;
			};
		}
	}
	fclose(fp);

	return found;
}

/*
标识符：TTMS_SCU_Studio_Perst_SelAll 
函数功能：用于从文件中载入所有演出厅数据。
参数说明：list是studio_list_t类型指针，指向演出厅链表的头指针。
返 回 值：整型，表示成功载入了演出厅的个数。
*/
int Studio_Perst_SelectAll(studio_list_t list) {
	studio_node_t *newNode;
	studio_t data;
	int recCount = 0;

	assert(NULL!=list);

	List_Free(list, studio_node_t);

	FILE *fp = fopen(STUDIO_DATA_FILE, "rb");
	if (NULL == fp) { //文件不存在
		return 0;
	}

	while (!feof(fp)) {
		if (fread(&data, sizeof(studio_t), 1, fp)) {
			newNode = (studio_node_t*) malloc(sizeof(studio_node_t));
			if (!newNode) {
				printf(
						"Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
				break;
			}
			newNode->data = data;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}
