/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_01		 
* File name: Studio_c		  
* Description : 演出厅用例业务逻辑层	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#include "Studio.h"
#include "../Persistence/Studio_Persist.h"
#include <stdlib.h>
#include <assert.h>

/*
标识符：TTMS_SCU_Studio_Srv_Add 
函数功能：用于添加一个新演出厅数据。
参数说明：data为studio_t类型指针，是需要添加的演出厅数据结点。
返 回 值：整型，表示是否成功添加了演出厅的标志。
*/
int Studio_Srv_Add(studio_t *data) {
	return Studio_Perst_Insert(data);
}

/*
标识符：TTMS_SCU_Studio_ Srv _Mod 
函数功能：用于修改一个演出厅数据。
参数说明：data为studio_t类型指针，是需要修改的演出厅数据结点。
返 回 值：整型，表示是否成功修改了演出厅的标志。
*/
int Studio_Srv_Modify(const studio_t *data) {
	return Studio_Perst_Update(data);
}

/*
标识符：TTMS_SCU_Studio_Srv_DelByID 
函数声明：int Studio_Srv_DeleteByID(int id)。
函数功能：用于删除一个演出厅的数据。
参数说明：id为整型，是需要删除的演出厅ID。
返 回 值：整型，表示是否成功删除了演出厅的标志。
*/
int Studio_Srv_DeleteByID(int ID) {
	return Studio_Perst_DeleteByID(ID);
}

/*
标识符：TTMS_SCU_Studio_Srv_FetchByID
函数功能：根据演出厅ID获取一个演出厅的数据。
参数说明：第一个参数ID为整型，是需要获取数据的演出厅ID；第二个参数buf为studio_t类型指针，指向获取的演出厅数据。
返 回 值：整型，表示是否成功获取了演出厅数据的标志。
*/
int Studio_Srv_FetchByID(int ID, studio_t *buf) {
	return Studio_Perst_SelectByID(ID, buf);

}

/*
标识符：TTMS_SCU_Studio_Srv_FetchAll 
函数功能：获取所有演出厅的数据，形成以list为头指针的演出厅链表。
参数说明：list是studio_list_t类型指针，指向演出厅链表的头指针。
返 回 值：整型，表示是否成功获取了所有演出厅的标志。
*/
int Studio_Srv_FetchAll(studio_list_t list) {
	return Studio_Perst_SelectAll(list);
}

/*
标识符：TTMS_SCU_S             tudio_Srv_FindByID
函数功能：根据演出厅ID和链表头指针获取该链表上相应演出厅的数据。
参数说明：第一个参数list为studio_list_t类型指针，指向演出厅链表的头指针；第二个参数ID为整型，表示需要获取数据的演出厅ID。
返 回 值：studio_node_t指针，表示获取相应ID的演出厅数据。
*/
studio_node_t *Studio_Srv_FindByID(studio_list_t list, int ID){
	assert(NULL!=list);
	studio_node_t *ptr=list->next;
	while(ptr!=list){
		if(ptr->data.id==ID)
			return ptr;
		else
			ptr=ptr->next;
	}

	return NULL;
}
