/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: Main_Menu.c			 	 
* Description : TTMS ϵͳ���˵�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Da
*/
#include "MaiAccount_UI.h"
#include "../View/Main_Menu.h"
#include "SalesAnalysis_UI.h"
#include <stdio.h>
#include "StaSales_UI.h"
#include "../View/Studio_UI.h"

//ϵͳ���˵� 
void Main_Menu(void) {
	if(SysLogin()==0){
		return ;
	}
	
	
	char choice;
	do {
		system("clear");
		printf("\n==================================================================\n");
		printf("**************** Theater Ticket Management System ****************\n");
		printf("[S]tudio Management.\n");
		printf("[P]lay Management.\n");
		printf("[T]icket Sale.\n");
		printf("[I]nquiry Performance.\n");
		printf("[R]eturn Ticket.\n");
		printf("StaSa[L]es\n");
		printf("[Q]SalesAanalysis.\n");
		printf("[A]ccount Management.\n");
		printf("[M]aiAccount\n");
		printf("[E]xist.\n");
		printf("\n==================================================================\n");
		printf("Please input your choice:");
		setbuf(stdin,NULL);
		choice = getchar();
		getchar();
		setbuf(stdin,NULL);
		switch (choice) {
		setbug(stdin,NULL);
		case 'S':
		case 's':
			Studio_UI_MgtEntry();
			break;
		case 'P':
		case 'p':
			Play_UI_MgtEntry();
			break;
		case'I':
		case'i':
			Schedule_UI_ListAll();
			break;
		case 'T':
		case 't':
			Sale_UI_MgtEntry();
			break;
		case 'R':
		case 'r':
			Sale_UI_ReturnTicket();
			break;
		case 'L':
		case 'l':
			StaSales_UI_MgtEntry();
			break;
		case 'Q':
		case 'q':
			SalesAanalysis_UI_MgtEntry();
			break;
		case 'A':
		case 'a':
			Account_UI_MgtEntry();
			break;
		case 'M':
		case 'm':
			MaiAccount_UI_MgtEntry();
			break;
		}
		
	} while ('E' != choice && 'e' != choice);
}

