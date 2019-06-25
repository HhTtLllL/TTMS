/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_01		 
* File name: Studio_UI.h			  
* Description : 演出厅用例界面层头文件	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef STUDIO_UI_H_
#define STUDIO_UI_H_

//标识符：TTMS_SCU_Studio_UI_Add 
//功能：添加新演出厅界面
int Studio_UI_Add(void);

//标识符：TTMS_SCU_Studio_UI_Mod
//功能：根据ID修改演出厅界面
int Studio_UI_Modify(int id);


//标识符：TTMS_SCU_Studio_UI_Del
//功能：根据ID删除演出厅界面 
int Studio_UI_Delete(int id);

//标识符：TTMS_SCU_Studio_UI_MgtEnt  
//功能：根据ID删除演出厅界面 
void Studio_UI_MgtEntry(void);

#endif /* STUDIO_UI_H_ */
