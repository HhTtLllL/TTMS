/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_02		 
* File name: Seat_UI.h			  
* Description : 设置座位用例界面层头文件	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef SEAT_UI_H_
#define SEAT_UI_H_
#include "../Common/list.h"
#include "../Service/Seat.h"

//标识符：TTMS_SCU_Seat_UI_MgtEnt 
//功能：管理座位界面
void Seat_UI_MgtEntry(int roomID);

//标识符：TTMS_SCU_Seat_UI_S2C 
//功能：根据座位状态获取界面显示符号界面
char Seat_UI_Status2Char(seat_status_t status);

//标识符：TTMS_SCU_Seat_UI_C2S
//功能：根据输入符号获取座位状态界面
seat_status_t Seat_UI_Char2Status(char statusChar);

//标识符：TTMS_SCU_Seat_UI_Add
//功能：添加新座位界面 
int Seat_UI_Add(seat_list_t list, int roomID, int rowsCount,int colsCount);

//标识符：TTMS_SCU_Seat_UI_Mod 
//功能：修改座位界面
int Seat_UI_Modify(seat_list_t list, int rowsCount, int colsCount);

//标识符：TTMS_SCU_Seat_UI_Del
//功能：根删除座位界面
int Seat_UI_Delete(seat_list_t list, int rowsCount, int colsCount);


#endif /* SEAT_UI_H_ */
