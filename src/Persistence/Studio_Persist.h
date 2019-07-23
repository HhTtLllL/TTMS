/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_01	 
* File name: Studio_Persist.h			  
* Description : 演出厅用例持久化层头文件	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef STUDIO_PERSIST_H_
#define STUDIO_PERSIST_H_

#include "../Service/Studio.h"

//标识符：TTMS_SCU_Studio_Perst_Insert 
//功能：向文件中存储新演出厅 
int Studio_Perst_Insert(studio_t *data);	 

//标识符：TTMS_SCU_Studio_ Perst_Update 
//功能：在文件中更新演出厅
int Studio_Perst_Update(const studio_t *data);

//标识符：TTMS_SCU_Studio_Perst_DeleteByID
//功能：在文件中删除演出厅
int Studio_Perst_DeleteByID(int ID);

//标识符：TTMS_SCU_Studio_Perst_SelectByID 
//功能：根据ID从文件中载入演出厅
int Studio_Perst_SelectByID(int ID, studio_t *buf);

//标识符：TTMS_SCU_Studio_Perst_SelAll 
//功能：从文件中载入全部演出厅
int Studio_Perst_SelectAll(studio_list_t list);


#endif /* STUDIO_PERSIST_H_ */
