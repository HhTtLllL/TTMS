/*
* Copyright(C), 2007-2008, XUPT Univ.	
* 锟斤拷锟斤拷锟斤拷牛锟絋TMS_UC_02 
* File name: Seat.c		  
* Description : 锟斤拷锟斤拷锟斤拷位锟斤拷锟斤拷业锟斤拷锟竭硷拷锟斤拷	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015锟斤拷4锟斤拷22锟斤拷	
*/
#include <stdlib.h>
#include "../Common/list.h"
#include "Seat.h"
#include "../Persistence/Seat_Persist.h"

/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷位锟斤拷锟捷★拷
锟斤拷锟斤拷说锟斤拷锟斤拷data为seat_t锟斤拷锟斤拷指锟诫，锟斤拷示锟斤拷要锟斤拷锟接碉拷锟斤拷位锟斤拷锟捷斤拷锟�?
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷谋锟街撅拷锟�?
*/

/*int Seat_UI_Status2Char(seat_status_t status){
	// 锟诫补锟斤拷锟斤拷锟斤拷

       return 0;
}
*/
int Seat_Srv_Add(const seat_t *data){

       return Seat_Perst_Insert(data);
}
/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷位锟斤拷锟捷★拷
锟斤拷锟斤拷说锟斤拷锟斤拷list为seat_list_t锟斤拷锟斤拷指锟诫，锟斤拷示锟斤拷要锟斤拷锟接碉拷锟斤拷锟斤拷锟斤拷位锟斤拷锟斤拷锟轿成碉拷锟斤拷锟斤拷锟斤拷
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷谋锟街撅拷锟�?
*/
int Seat_Srv_AddBatch(seat_list_t list){
	// 锟诫补锟斤拷锟斤拷锟斤拷
       return 0;
}
/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟睫革拷一锟斤拷锟斤拷位锟斤拷锟捷★拷
锟斤拷锟斤拷说锟斤拷锟斤拷data为seat_t锟斤拷锟斤拷指锟诫，锟斤拷示锟斤拷要锟睫改碉拷锟斤拷位锟斤拷锟捷斤拷锟�?
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟斤拷薷锟斤拷锟斤拷锟轿伙拷谋锟街撅拷锟�?
*/

int Seat_Srv_Modify(const seat_t *data){
       return Seat_Perst_Update(data);
	// 锟诫补锟斤拷锟斤拷锟斤拷

}
/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟斤拷位ID删锟斤拷一锟斤拷锟斤拷位锟斤拷
锟斤拷锟斤拷说锟斤拷锟斤拷ID为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷要删锟斤拷锟斤拷锟斤拷位锟斤拷锟捷斤拷锟�?
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟缴撅拷锟斤拷锟斤拷锟轿伙拷谋锟街撅拷锟�?
*/
int Seat_Srv_DeleteByID(int ID){
       return Seat_Perst_DeleteByID(ID);
       // 锟诫补锟斤拷锟斤拷锟斤拷
}

/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟斤拷位ID锟斤拷取锟斤拷位锟斤拷锟捷★拷
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷ID为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位ID锟斤拷锟节讹拷锟斤拷锟斤拷锟斤拷buf为seat_t指锟诫，指锟斤拷锟斤拷锟饺★拷锟斤拷锟轿伙拷锟斤拷萁锟姐。
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟斤拷锟饺★拷锟斤拷锟轿伙拷谋锟街撅拷锟�?
*/
int Seat_Srv_FetchByID(int ID, seat_t *buf){
	// 锟诫补锟斤拷锟斤拷锟斤拷
       return 0;
}

/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟捷筹拷锟斤拷ID删锟斤拷锟斤拷锟斤拷锟斤拷位锟斤拷
锟斤拷锟斤拷说锟斤拷锟斤拷roomID为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷要删锟斤拷锟斤拷锟斤拷锟斤拷位锟斤拷锟捷筹拷锟斤拷ID锟斤拷
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟缴撅拷锟斤拷锟斤拷莩锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷谋锟街撅拷锟�?
*/

inline int Seat_Srv_DeleteAllByRoomID(int roomID){
       return Seat_Perst_DeleteAllByRoomID(roomID);
	// 锟诫补锟斤拷锟斤拷锟斤拷
}



/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟捷革拷锟斤拷锟捷筹拷锟斤拷锟斤拷锟叫★拷锟斤拷锟斤拷锟斤拷始锟斤拷锟捷筹拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷位锟斤拷锟捷ｏ拷锟斤拷锟斤拷每锟斤拷锟斤拷位锟斤拷惆达拷胁锟斤拷锟斤拷锟轿伙拷锟斤拷锟斤拷锟�?
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷list为seat_list_t锟斤拷锟斤拷指锟诫，指锟斤拷锟斤拷位锟斤拷锟斤拷头指锟诫，锟节讹拷锟斤拷锟斤拷锟斤拷rowsCount为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位锟斤拷锟斤拷锟叫号ｏ拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷colsCount为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位锟斤拷锟斤拷锟叫号★拷
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟斤拷锟绞硷拷锟斤拷锟斤拷莩锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷锟�?
*/

int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID){
       int SeatCount;
       SeatCount = Seat_Perst_SelectByRoomID(list,roomID);
       Seat_Srv_SortSeatList(list);
       return SeatCount; 
}
/*

锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟捷筹拷锟斤拷ID锟斤拷酶锟斤拷莩锟斤拷锟斤拷锟斤拷锟叫э拷锟轿伙拷锟�?
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷list为seat_list_t锟斤拷锟酵ｏ拷锟斤拷示锟斤拷取锟斤拷锟斤拷锟斤拷效锟斤拷位锟斤拷锟斤拷头指锟诫，锟节讹拷锟斤拷锟斤拷锟斤拷roomID为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷要锟斤拷取锟斤拷效锟斤拷位锟斤拷锟捷筹拷锟斤拷ID锟斤拷
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟捷筹拷锟斤拷锟斤拷锟斤拷效锟斤拷位锟斤拷锟斤拷锟斤拷
*/

int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID)
{
       //??????不确定？？？？？
       int SeatCount;
       SeatCount = Seat_Perst_SelectByRoomID(list,roomID);
       seat_list_t temp = list;
       while(list->next!=temp){
              list = list->next;
              if(list->data.status!=SEAT_GOOD){
                     SeatCount--;
              }
       }
       Seat_Srv_SortSeatList(list);
       return SeatCount;

       // 锟诫补锟斤拷锟斤拷锟斤拷
}



/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟捷革拷锟斤拷锟捷筹拷锟斤拷锟斤拷锟叫★拷锟斤拷锟斤拷锟斤拷始锟斤拷锟捷筹拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷位锟斤拷锟捷ｏ拷锟斤拷锟斤拷每锟斤拷锟斤拷位锟斤拷惆达拷胁锟斤拷锟斤拷锟轿伙拷锟斤拷锟斤拷锟�?
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷list为seat_list_t锟斤拷锟斤拷指锟诫，指锟斤拷锟斤拷位锟斤拷锟斤拷头指锟诫，锟节讹拷锟斤拷锟斤拷锟斤拷rowsCount为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位锟斤拷锟斤拷锟叫号ｏ拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷colsCount为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位锟斤拷锟斤拷锟叫号★拷
锟斤拷 锟斤拷 值锟斤拷锟斤拷锟酵ｏ拷锟斤拷示锟角凤拷晒锟斤拷锟绞硷拷锟斤拷锟斤拷莩锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷锟�?
*/

int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,int colsCount) {

       seat_list_t tem;
       //List_Init(list,seat_node_t);
       for(int i = 1;i <= rowsCount;i++){
              for(int j = 1;j <= colsCount;j++){
                     //printf("jincneglllll\n");
                     tem = (seat_list_t)malloc(sizeof(seat_node_t));
                     tem->data.column = j;
                     tem->data.row = i;
                     tem->data.roomID = roomID;
                     tem->data.status = SEAT_GOOD;
                     List_AddTail(list,tem);
              }
       }
       return Seat_Perst_InsertBatch(list);
       
}


/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷位锟斤拷锟斤拷list锟斤拷锟斤拷位锟叫号★拷锟叫号斤拷锟斤拷锟斤拷锟斤拷
锟斤拷锟斤拷说锟斤拷锟斤拷list为seat_list_t锟斤拷锟酵ｏ拷锟斤拷示锟斤拷锟斤拷锟斤拷锟斤拷位锟斤拷锟斤拷头指锟诫。
锟斤拷 锟斤拷 值锟斤拷锟睫★拷
*/

void Seat_Srv_SortSeatList(seat_list_t list) {
       assert(list!=NULL);
       seat_list_t listLeft;
       seat_list_t p;
       if(List_IsEmpty(list)){
              return ;
       }
       else{
              list->prev->next = NULL;
              listLeft = list->next;
              list->next = list->prev = list;
              
              while(listLeft != NULL){
                     p = listLeft;
                     listLeft = listLeft->next;
                     Seat_Srv_AddToSoftedList(list,p);   
              } 
       }
       return ;
}


/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷一锟斤拷锟斤拷位锟斤拷锟斤拷锟诫到锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷锟斤拷锟斤拷小锟�?
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷list为seat_list_t锟斤拷锟酵ｏ拷锟斤拷示锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿伙拷锟斤拷锟酵分革拷耄�锟节讹拷锟斤拷锟斤拷锟斤拷node为seat_node_t指锟诫，锟斤拷示锟斤拷要锟斤拷锟斤拷锟斤拷锟轿伙拷锟斤拷萁锟姐。
锟斤拷 锟斤拷 值锟斤拷锟睫★拷
*/

void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
       //问题
       seat_list_t p ;
       assert(list!=NULL && node!=NULL);
       if(List_IsEmpty(list)){
              List_AddTail(list,node);
       }
       else{
              p = list->next;
              while(p!=list&&(p->data.row < node->data.row||(p->data.row == node->data.row && p->data.column < node->data.column))){
                     p=p->next;
              }
              List_InsertBefore(p,node);
       }
       // 锟诫补锟斤拷锟斤拷锟斤拷
}

/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟斤拷位锟斤拷锟叫★拷锟叫号伙拷取锟斤拷位锟斤拷锟捷★拷
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷list为seat_list_t锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位锟斤拷锟斤拷头指锟诫，
锟节讹拷锟斤拷锟斤拷锟斤拷row为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷锟斤拷取锟斤拷位锟斤拷锟叫号ｏ拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷column为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷锟斤拷取锟斤拷位锟斤拷锟叫号★拷
锟斤拷 锟斤拷 值锟斤拷为seat_node_t指锟诫，锟斤拷示锟斤拷取锟斤拷锟斤拷锟斤拷位锟斤拷锟捷★拷
*/
seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column) {
       seat_list_t p;
       p = list;
       list = list->next;
       while(!((list->data.row == row) && (list->data.column == column)))
       {
              printf("row    =  %d,col = %d\n",list->data.row,list->data.column);
              list = list->next;
              if(list == p){
                     break;
              }
       }
       if(list->data.row == row && list->data.column == column){
              return list;
       }
       else{
              return NULL;
       }
       // 锟诫补锟斤拷锟斤拷锟斤拷
      
}
/*
锟斤拷锟斤拷锟斤拷锟杰ｏ拷锟斤拷锟斤拷锟斤拷位ID锟斤拷锟斤拷锟斤拷锟叫伙拷取锟斤拷位锟斤拷锟捷★拷
锟斤拷锟斤拷说锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷list为seat_list_t锟斤拷锟酵ｏ拷指锟斤拷锟斤拷位锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟节讹拷锟斤拷锟斤拷锟斤拷ID为锟斤拷锟酵ｏ拷锟斤拷示锟斤拷位ID锟斤拷
锟斤拷 锟斤拷 值锟斤拷seat_node_t锟斤拷锟酵ｏ拷锟斤拷示锟斤拷取锟斤拷锟斤拷位锟斤拷锟捷★拷
*/

seat_node_t * Seat_Srv_FindByID(seat_list_t list, int rowID) {
       // 锟诫补锟斤拷锟斤拷锟斤拷
       return NULL;
}


