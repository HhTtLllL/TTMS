/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* ������ţ�TTMS_UC_02
* File name: Seat_UI.c			  
* Description : ������λ���������	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "Seat_UI.h"
#include "../Service/Seat.h"

#include "../Service/Studio.h"
#include "../Common/list.h"
#include <stdio.h>
#include <string.h>

inline char Seat_UI_Status2Char(seat_status_t status) {
    if(status == 0)
        return ' ';
    else if(status == 1)
	    return '#';
    else if(status == 9)
        return '@';
}


inline seat_status_t Seat_UI_Char2Status(char statusChar) {
    if(statusChar == ' ')
	    return SEAT_NONE;
    else if(statusChar == '#')
        return SEAT_GOOD;
    else if(statusChar == '@')
        return SEAT_BROKEN;
}


void Seat_UI_MgtEntry(int roomID) {

    studio_t rec;
    char choice;
    
    if (!Studio_Srv_FetchByID(roomID, &rec)) {
		printf("The room does not exist!\nPress [Enter] key to return!\n");
		getchar();
		return;
	}
    seat_list_t head;
    List_Init(head,seat_node_t); 
    if(Seat_Srv_FetchByRoomID(head,roomID) == 0){
        rec.seatsCount = Seat_Srv_RoomInit(head,roomID,rec.rowsCount,rec.colsCount);
        Studio_Srv_Modify(&rec);
    }

    //printf("room = %d\n",rec.seatsCount);
    /*seat_list_t head;
    List_Init(head,seat_node_t); 
    if(Seat_Srv_FetchByRoomID(head,roomID) == 0){
        rec.seatsCount = Seat_Srv_RoomInit(head,roomID,rec.rowsCount,rec.colsCount);
        Studio_Srv_Modify(&rec);
    }
    */
    /*if(rec.seatsCount == 0){

        rec.seatsCount = Seat_Srv_RoomInit(head,roomID,rec.rowsCount,rec.colsCount);
    }
    else{
        rec.seatsCount = Seat_Srv_FetchByRoomID(head,roomID);
    }*/
    //Studio_Srv_Modify(&rec);
    do{

        printf("row:%d                   colum:%d                  seatsnumber:%d\n",rec.rowsCount,rec.colsCount,rec.seatsCount);    
        //printf("   %d   \n",head->next->data.id);
        
        printf("-------------------------------------------------------------------\n");
        setbuf(stdin,NULL);
        int x = 0,y = 1;
        for(int i=0;i<=rec.rowsCount;i++)
        {
            for(int j=0;j<=rec.colsCount;j++)
            {
     
                if(i==0){
                    printf("%3d",x++);
                }
                else if(j==0){
                    printf("%3d",y++);
                }
                else{
                    int flag=0;
                    seat_list_t temp;
                    List_ForEach(head,temp)
                    {
                        if(temp->data.row==i && temp->data.column==j)                  
                        {
                            flag = 1;
                            printf("%3c",Seat_UI_Status2Char(temp->data.status));
                            break;
                        }
                    }
                    if(!flag) printf("   ");//此处没有座位
                }
            }
            putchar('\n');
        }
        //用于显示座位情况列表
        setbuf(stdin,NULL);

        int row1,column1;
        printf(
                "******************************************************************\n");
        printf(
                "[A]dd  |  [M]od  |  [D]el  |  [R]eturn");
        printf(
                "\n==================================================================\n");
    
        printf("Your Choice:");
        setbuf(stdin,NULL);
        scanf("%c", &choice);
        setbuf(stdin,NULL);
        switch(choice)
        {
            case 'A':
            case 'a':
            printf("please input the row :");
            scanf("%d",&row1);
            setbuf(stdin,NULL);
            printf("please input the col :");
            scanf("%d",&column1);
            setbuf(stdin,NULL);
            if(!Seat_UI_Add(head,roomID,row1,column1))
            {
                printf("input error,添加失败\n");
            }
            else{
                rec.seatsCount = rec.seatsCount+1;
                Studio_Srv_Modify(&rec);
                Seat_Srv_FetchByRoomID(head,roomID);
                printf("add accept\n");
            }
            break;
            case 'M':
            case 'm':
            printf("please input the row :");
            scanf("%d",&row1);
            setbuf(stdin,NULL);
            printf("please input the col :");
            scanf("%d",&column1);
            setbuf(stdin,NULL);
            if(!Seat_UI_Modify(head,row1,column1))
            {
                printf("input error，修改失败\n");
            }
            else{
                Seat_Srv_FetchByRoomID(head,roomID);
                printf("mod accept\n");
            }
            break;
            case 'D':
            case 'd':
            printf("please input the row :");
            scanf("%d",&row1);
            setbuf(stdin,NULL);
            printf("please input the col :");
            scanf("%d",&column1);
            setbuf(stdin,NULL);
            if(!Seat_UI_Delete(head,row1,column1))
            {
                printf("input error，删除失败\n");
            }
            else{
                rec.seatsCount = rec.seatsCount-1;
                Studio_Srv_Modify(&rec);
                Seat_Srv_FetchByRoomID(head,roomID);
                printf("del accept\n");
            }
            break;
        }
    }while(choice!='r'&&choice!='R');
    setbuf(stdin,NULL);
	List_Destroy(head, seat_node_t);
}



int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //����һ����λ

    
    seat_list_t tmp = Seat_Srv_FindByRowCol(list,row,column);
    if(tmp == NULL){
        seat_t temp;

        temp.column = column;
        temp.row = row;
        temp.status = SEAT_GOOD;
        temp.roomID = roomID;
        //List_AddTail(list,temp);
        if(Seat_Srv_Add(&temp)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}



int Seat_UI_Modify(seat_list_t list, int row, int column) {
    

    seat_list_t tmp = Seat_Srv_FindByRowCol(list,row,column);
    
    if(tmp!=NULL){
        seat_t temp;
        Seat_Perst_SelectByID(tmp->data.id,&temp);
        char choice;
        printf(
	    		"*******************************************************************\n");
	    printf(
	    		"[#]Good | [@]Break | [ ]Empty | the seat's situation is %c",Seat_UI_Status2Char(temp.status));
	    printf(
	    		"\n==================================================================\n");
        printf("Your Choice:");
        setbuf(stdin,NULL);
	    scanf("%c", &choice);
        setbuf(stdin,NULL);
        tmp->data.status = Seat_UI_Char2Status(choice);

        if(Seat_Srv_Modify(&tmp->data)){

            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}



int Seat_UI_Delete(seat_list_t list, int row, int column) {
    
    seat_list_t tmp = Seat_Srv_FindByRowCol(list,row,column);
    
    if(tmp!=NULL){
        if(Seat_Srv_DeleteByID(tmp->data.id)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }  
}
