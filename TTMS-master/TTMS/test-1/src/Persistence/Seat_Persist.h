/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* 用例编号：TTMS_UC_02
* File name: Seat.h	  
* Description : 设置座位用例持久化层头文件	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef SEATPERSIST_H_
#define SEATPERSIST_H_

#include "../Service/Seat.h"

//标识符： TTMS_SCU_Seat_Perst_Insert
//功能：向文件中存储新座位
int Seat_Perst_Insert(seat_t *data);	

//标识符：TTMS_SCU_Seat_Perst_InsertBatch
//功能：向文件中批量存储座位
int Seat_Perst_InsertBatch(seat_list_t list);

//标识符：TTMS_SCU_Seat_Perst_Update
//功能：在文件中更新座位
int Seat_Perst_Update(const seat_t *data);


//标识符：TTMS_SCU_Seat_Perst_DelByID
//功能：根据座位ID删除座位 
int Seat_Perst_DeleteByID(int ID);

//标识符：TTMS_SCU_Seat_Perst_DelAllByID
//功能：根据演出厅ID删除座位 
int Seat_Perst_DeleteAllByRoomID(int roomID);

//标识符：TTMS_SCU_Seat_Perst_SelByRoomID
//功能：根据演出厅ID从文件中载入所有座位
int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID);

//标识符：TTMS_SCU_Studio_Perst_SelByID
//功能：根据ID从文件中载入座位 
int Seat_Perst_SelectByID(int ID, seat_t *buf);

//标识符：TTMS_SCU_Seat_Perst_SelAll
//功能：从文件中载入所有座位 
int Seat_Perst_SelectAll(seat_list_t list);

#endif /* SEATPERSIST_H_ */
