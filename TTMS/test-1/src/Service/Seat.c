/*
* Copyright(C), 2007-2008, XUPT Univ.	
* ÓÃÀı±àºÅ£ºTTMS_UC_02 
* File name: Seat.c		  
* Description : ÉèÖÃ×ùÎ»ÓÃÀıÒµÎñÂß¼­²ã	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015Äê4ÔÂ22ÈÕ	
*/
#include<stdio.h>
#include <stdlib.h>
#include "../Common/list.h"
#include "Seat.h"

static const char SEAT_DATA_FILE[] = "Seat.dat";
static const char SEAT_DATA_TEMP_FILE[] = "SeatTmp.dat";
/*
º¯Êı¹¦ÄÜ£ºÓÃÓÚÌí¼ÓÒ»¸öĞÂ×ùÎ»Êı¾İ¡£
²ÎÊıËµÃ÷£ºdataÎªseat_tÀàĞÍÖ¸Õë£¬±íÊ¾ĞèÒªÌí¼ÓµÄ×ùÎ»Êı¾İ½áµã¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦Ìí¼ÓÁË×ùÎ»µÄ±êÖ¾¡£
*/
int Seat_Srv_Add(const seat_t *data){
						// Çë²¹³äÍêÕû
	Seat_Perst_Insert(*data);
	return 0;
}

/*
º¯Êı¹¦ÄÜ£ºÅúÁ¿Ìí¼Ó×ùÎ»Êı¾İ¡£
²ÎÊıËµÃ÷£ºlistÎªseat_list_tÀàĞÍÖ¸Õë£¬±íÊ¾ĞèÒªÌí¼ÓµÄÅúÁ¿×ùÎ»Êı¾İĞÎ³ÉµÄÁ´±í¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦Ìí¼ÓÁËÅúÁ¿×ùÎ»µÄ±êÖ¾¡£
*/
int Seat_Srv_AddBatch(seat_list_t list){
	// Çë²¹³äÍêÕû
       return 0;
}

/*
º¯Êı¹¦ÄÜ£ºÓÃÓÚĞŞ¸ÄÒ»¸ö×ùÎ»Êı¾İ¡£
²ÎÊıËµÃ÷£ºdataÎªseat_tÀàĞÍÖ¸Õë£¬±íÊ¾ĞèÒªĞŞ¸ÄµÄ×ùÎ»Êı¾İ½áµã¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦ĞŞ¸ÄÁË×ùÎ»µÄ±êÖ¾¡£
*/


int Seat_Srv_Del(const seat_t *data)
{
	Seat_Perst_Del(*data);
	return 0;
}
int Seat_Srv_Modify(const seat_t *data){
	
	Seat_Perst_Update(*data);
        //Seat_Perst_Del(*data);
	return 0;
}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İ×ùÎ»IDÉ¾³ıÒ»¸ö×ùÎ»¡£
²ÎÊıËµÃ÷£ºIDÎªÕûĞÍ£¬±íÊ¾ĞèÒªÉ¾³ıµÄ×ùÎ»Êı¾İ½áµã¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦É¾³ıÁË×ùÎ»µÄ±êÖ¾¡£
*/
int Seat_Srv_DeleteByID(int ID){
	// Çë²¹³äÍêÕû
       return 1;
}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İ×ùÎ»ID»ñÈ¡×ùÎ»Êı¾İ¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊıIDÎªÕûĞÍ£¬±íÊ¾×ùÎ»ID£¬µÚ¶ş¸ö²ÎÊıbufÎªseat_tÖ¸Õë£¬Ö¸Ïò´ı»ñÈ¡µÄ×ùÎ»Êı¾İ½áµã¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦»ñÈ¡ÁË×ùÎ»µÄ±êÖ¾¡£
*/
int Seat_Srv_FetchByID(int ID, seat_t *buf){
	// Çë²¹³äÍêÕû
       return 0;
}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İÑİ³öÌüIDÉ¾³ıËùÓĞ×ùÎ»¡£
²ÎÊıËµÃ÷£ºroomIDÎªÕûĞÍ£¬±íÊ¾ĞèÒªÉ¾³ıËùÓĞ×ùÎ»µÄÑİ³öÌüID¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦É¾³ıÁËÑİ³öÌüËùÓĞ×ùÎ»µÄ±êÖ¾¡£
*/
inline int Seat_Srv_DeleteAllByRoomID(int roomID)
{
	
	if(rename(SEAT_DATA_FILE, SEAT_DATA_TEMP_FILE)<0)//¿¿¿¿¿¿,¿¿¿ 0 ,¿¿¿¿ -1
	{
		printf("Cannot open file %s!\n", SEAT_DATA_FILE);
		return 0;
	}

	FILE *fpSour, *fpTarg;  

	fpSour = fopen(SEAT_DATA_TEMP_FILE, "rb"); 

	if (NULL == fpSour )
	{
		printf("Cannot open file %s!\n", SEAT_DATA_FILE);
		return 0;
	}

	fpTarg = fopen(SEAT_DATA_FILE, "wb");   

	if ( NULL == fpTarg ) 
	{
		printf("Cannot open file %s!\n", SEAT_DATA_TEMP_FILE);
		return 0;
	}

	seat_t buf;  

	int found = 0;
	while (!feof(fpSour)) 
	{
		if (fread(&buf, sizeof(seat_t), 1, fpSour)) //¿¿¿¿¿¿¿,¿¿ size ¿¿¿ ¿¿¿¿count ¿¿,¿fpsour¿¿
		{
			if (roomID == buf.id) 
			{
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(seat_t), 1, fpTarg);
		}

	}

	fclose(fpTarg);
	fclose(fpSour);

	remove(SEAT_DATA_TEMP_FILE);

	return found;

}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İ¸ø¶¨Ñİ³öÌüµÄĞĞ¡¢ÁĞÊı³õÊ¼»¯Ñİ³öÌüµÄËùÓĞ×ùÎ»Êı¾İ£¬²¢½«Ã¿¸ö×ùÎ»½áµã°´ĞĞ²åÈë×ùÎ»Á´±í¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊılistÎªseat_list_tÀàĞÍÖ¸Õë£¬Ö¸Ïò×ùÎ»Á´±íÍ·Ö¸Õë£¬µÚ¶ş¸ö²ÎÊırowsCountÎªÕûĞÍ£¬±íÊ¾×ùÎ»ËùÔÚĞĞºÅ£¬µÚÈı¸ö²ÎÊıcolsCountÎªÕûĞÍ£¬±íÊ¾×ùÎ»ËùÔÚÁĞºÅ¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦³õÊ¼»¯ÁËÑİ³öÌüµÄËùÓĞ×ùÎ»¡£
*/
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID)
{
	Seat_Perst_SelectByRoomID(list,roomID);
        return 0;

}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İÑİ³öÌüID»ñµÃ¸ÃÑİ³öÌüµÄÓĞĞ§×ùÎ»¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊılistÎªseat_list_tÀàĞÍ£¬±íÊ¾»ñÈ¡µ½µÄÓĞĞ§×ùÎ»Á´±íÍ·Ö¸Õë£¬µÚ¶ş¸ö²ÎÊıroomIDÎªÕûĞÍ£¬±íÊ¾ĞèÒªÌáÈ¡ÓĞĞ§×ùÎ»µÄÑİ³öÌüID¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾Ñİ³öÌüµÄÓĞĞ§×ùÎ»¸öÊı¡£
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID)
{
       // Çë²¹³äÍêÕû
       return 0;
}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İ¸ø¶¨Ñİ³öÌüµÄĞĞ¡¢ÁĞÊı³õÊ¼»¯Ñİ³öÌüµÄËùÓĞ×ùÎ»Êı¾İ£¬²¢½«Ã¿¸ö×ùÎ»½áµã°´ĞĞ²åÈë×ùÎ»Á´±í¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊılistÎªseat_list_tÀàĞÍÖ¸Õë£¬Ö¸Ïò×ùÎ»Á´±íÍ·Ö¸Õë£¬µÚ¶ş¸ö²ÎÊırowsCountÎªÕûĞÍ£¬±íÊ¾×ùÎ»ËùÔÚĞĞºÅ£¬µÚÈı¸ö²ÎÊıcolsCountÎªÕûĞÍ£¬±íÊ¾×ùÎ»ËùÔÚÁĞºÅ¡£
·µ »Ø Öµ£ºÕûĞÍ£¬±íÊ¾ÊÇ·ñ³É¹¦³õÊ¼»¯ÁËÑİ³öÌüµÄËùÓĞ×ùÎ»¡£
*/
int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,int colsCount)
{
	FILE *fp = NULL;
	fp = fopen(SEAT_DATA_FILE,"ab");
	if(fp == NULL)
	{
		printf( "the file not in here\n");
		return 0;
	}
//	fp = fseek(fp,-1L,SEEK_END);
	int n = 1;
	seat_list_t temp;
	List_Init(list,seat_node_t);
	for(int i = 0;i < rowsCount;i++)		// Çë²¹³äÍêÕû
	{
		for(int j = 0;j < colsCount;j++)
		{
			temp = (seat_list_t)malloc(sizeof(seat_node_t));
			temp->data.id = n;
			temp->data.roomID = roomID;
			temp->data.row = i;
			temp->data.column = j;
			temp->data.status = 1;
			List_AddTail(list,temp);
			printf( "n =   %d\n",n);
			if(fwrite(temp,sizeof(seat_node_t),1,fp))     n++;

		}
	}
/*	fseek(fp,-sizeof(seat_node_t),SEEK_CUR);

	fread(temp,sizeof(seat_node_t),1,fp);
	printf( "n  =  %d     stu =  %d      ",temp->data.id,temp->data.status);*/
	fclose(fp);
        return 0;
}

/*
º¯Êı¹¦ÄÜ£º¶Ô×ùÎ»Á´±ílist°´×ùÎ»ĞĞºÅ¡¢ÁĞºÅ½øĞĞÅÅĞò¡£
²ÎÊıËµÃ÷£ºlistÎªseat_list_tÀàĞÍ£¬±íÊ¾´ıÅÅĞò×ùÎ»Á´±íÍ·Ö¸Õë¡£
·µ »Ø Öµ£ºÎŞ¡£
*/
void Seat_Srv_SortSeatList(seat_list_t list) {
       // Çë²¹³äÍêÕû
}

/*
º¯Êı¹¦ÄÜ£º½«Ò»¸ö×ùÎ»½áµã¼ÓÈëµ½ÒÑÅÅĞòµÄ×ùÎ»Á´±íÖĞ¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊılistÎªseat_list_tÀàĞÍ£¬±íÊ¾´ı²åÈë½áµãµÄ×ùÎ»Á´±íÍ·Ö¸Õë£¬µÚ¶ş¸ö²ÎÊınodeÎªseat_node_tÖ¸Õë£¬±íÊ¾ĞèÒª²åÈëµÄ×ùÎ»Êı¾İ½áµã¡£
·µ »Ø Öµ£ºÎŞ¡£
*/
void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
       // Çë²¹³äÍêÕû
}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İ×ùÎ»µÄĞĞ¡¢ÁĞºÅ»ñÈ¡×ùÎ»Êı¾İ¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊılistÎªseat_list_tÀàĞÍ£¬±íÊ¾×ùÎ»Á´±íÍ·Ö¸Õë£¬
         µÚ¶ş¸ö²ÎÊırowÎªÕûĞÍ£¬±íÊ¾´ı»ñÈ¡×ùÎ»µÄĞĞºÅ£¬µÚÈı¸ö²ÎÊıcolumnÎªÕûĞÍ£¬±íÊ¾´ı»ñÈ¡×ùÎ»µÄÁĞºÅ¡£
·µ »Ø Öµ£ºÎªseat_node_tÖ¸Õë£¬±íÊ¾»ñÈ¡µ½µÄ×ùÎ»Êı¾İ¡£
*/
seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column) {
       // Çë²¹³äÍêÕû
       return NULL;
}

/*
º¯Êı¹¦ÄÜ£º¸ù¾İ×ùÎ»IDÔÚÁ´±íÖĞ»ñÈ¡×ùÎ»Êı¾İ¡£
²ÎÊıËµÃ÷£ºµÚÒ»¸ö²ÎÊılistÎªseat_list_tÀàĞÍ£¬Ö¸Ïò×ùÎ»Êı¾İÁ´±í£¬µÚ¶ş¸ö²ÎÊıIDÎªÕûĞÍ£¬±íÊ¾×ùÎ»ID¡£
·µ »Ø Öµ£ºseat_node_tÀàĞÍ£¬±íÊ¾»ñÈ¡µÄ×ùÎ»Êı¾İ¡£
*/
seat_node_t * Seat_Srv_FindByID(seat_list_t list, int rowID) {
       // Çë²¹³äÍêÕû
       return NULL;
}
