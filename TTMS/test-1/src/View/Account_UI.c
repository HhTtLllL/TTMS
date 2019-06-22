/*
 * Account_UI.c
 *
 *  Created on: 2015年4月24日
 *      Author: Administrator
 */
#include "../View/Account_UI.h"
#include <stdio.h>
#include <string.h>
#include "../Common/list.h"
#include "../Service/Account.h"
static const int Account_PAGE_SIZE = 5;
char ch;

//系统登录
int SysLogin(){
		system("clear");
		printf(
    "       ********\n"
    "      ************\n"                                              
    "      ####....#.      ##########  ##########  ####     ####         ############\n"
    "    #..###.....##.... ##########  ##########  #############       ######\n"
    "    ###.......######     ###         ###      ###  ###  ###      #####\n"
    "       ...........       #.#         #.#      ###   #   ###       #####\n"
    "      ##*#######         ###         ###      ###       ###          #####\n"
    "   ####*******######     #.#         #.#      ###       ###             #####\n"
    "  ...#***.****.*###....  #.#         #.#      ###       ###               #####\n"
    "  ....**********##.....  ###         ###      ###       ###                #####\n"
    "  ....****    *****....                                               ########\n"                                  
    "    ####        ####                                             ##########\n"
    "  ######        ######            欢迎使用TTMS影院管理系统\n"                     
    "################################################################################\n"
    "#...#......#.##...#......#.##...#......#.##------------------------------------#\n"
    "#..#....#....##..#....#....##..#....#....#######################################\n"
    "##########################################                     #----------#\n"
    "##########################################                     ############\n"
    );
		Account_Srv_InitSys();
		int i = 0;
		while(i<3){
			char usrName[20],pwd[20];
			printf("please input you name :");
			setbuf(stdin,NULL);

			gets(usrName);
			//printf("%s\n",usrName);
			printf("please input you password :");
			setbuf(stdin,NULL);

			gets(pwd);
			//printf("%s\n",pwd);
			if(Account_Srv_Verify(usrName,pwd)){
				printf("the user is accept\n");
				return 1;
			}
			else{
				printf("login in error\n");
				i++;
			}
		}
	return 0;
}

char Account_UI_Status2Char(account_type_t status) {
    if(status == 0)
        return 'N';
    else if(status == 1)
	    return 'X';
    else if(status == 9)
        return 'A';
	else if(status == 2)
        return 'M';
}


void Account_UI_MgtEntry(void) {
	
	int i,id;
	char choice,usrName[20];

	account_list_t head;
	account_node_t *pos;
	Pagination_t paging;

	List_Init(head, account_node_t);
	paging.offset = 0;
	paging.pageSize = Account_PAGE_SIZE;

	paging.totalRecords = Account_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
    
    
    do{
		printf("[N]匿名用户    |    [X]售票员     |     [A]经理     |     [M]系统管理员");
		printf(
				"\n==================================================================\n");
		printf(
				"********************* Account guangli jiemian *********************\n");
		printf("%7s  %18s  %18s  %15s\n", "ID", "username", "password",
				"type");
		printf(
				"------------------------------------------------------------------\n");
		
        Paging_ViewPage_ForEach(head, paging, account_node_t, pos, i){
		printf("%7d  %18s  %18s  %15c\n", pos->data.id,
		pos->data.username, pos->data.password, Account_UI_Status2Char(pos->data.type));
		}

        printf(
				"------- Total Records:%2d ----------------------- Page %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf(
				"******************************************************************\n");
		printf(
				"[P]revPage|[N]extPage | [A]dd | [D]elete | [Q]uery | [M]od | [R]eturn");
		printf(
				"\n==================================================================\n");
	
		printf("Your Choice:");
		setbuf(stdin,NULL);
		scanf("%c", &choice);
		//getchar();

		switch (choice)
        {
            case 'a':
            case 'A':system("clear");

                if (Account_UI_Add(head)) //�����ӳɹ����������һҳ��ʾ
                {
                    paging.totalRecords = Account_Srv_FetchAll(head);
                    Paging_Locate_LastPage(head, paging, account_node_t);
                }
                else{
                    printf("this user is already have\n");
            	}
			break;
            case 'd':
            case 'D':system("clear");

                printf("Input the username:");
				setbuf(stdin,NULL);
                scanf("%s", usrName);
				getchar();
                if (Account_UI_Delete(head,usrName)) {	//������������
				printf("delete accept\n");
                    paging.totalRecords = Account_Srv_FetchAll(head);
                    List_Paging(head, paging, account_node_t);
                }
                else{
                    printf("delete error\n");
                }
			    break;
		    case 'q':
		    case 'Q':system("clear");

    			printf("Input the username:");
				setbuf(stdin,NULL);
    			scanf("%s", usrName);
				getchar();
    			if (Account_UI_Query(head,usrName)) {	//������������
    				paging.totalRecords = Account_Srv_FetchAll(head);
    				List_Paging(head, paging, account_node_t);
    			}
                else{
                    printf("chaxun error\n");
                }
                break;
            case 'm':
            case 'M':system("clear");

                printf("Input the username:");
				setbuf(stdin,NULL);
                scanf("%s", usrName);
				getchar();
                if(Account_UI_Modify(head,usrName)){
				printf("mod accept\n");
                paging.totalRecords = Account_Srv_FetchAll(head);
                List_Paging(head, paging, account_node_t);
                }
                break;
            case 'p':
            case 'P'://system("clear");

                if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, account_node_t);
				}
			break;
		    case 'n':
		    case 'N'://system("clear");

			    if (!Pageing_IsLastPage(paging)) {
				    Paging_Locate_OffsetPage(head, paging, 1,account_node_t);
			    }
			    break;
        }
    }while(choice != 'r' && choice != 'R');
	List_Destroy(head, account_node_t);
}
int Account_UI_Add(account_list_t list){
	account_t data;
	int newRecCount = 0;
	char choice;

	do{
		printf("\n==================================================================\n");
		printf("**************************  Add New User **************************\n");
		printf("-------------------------------------------------------------------\n");
		printf("please input you want add newname :");
		setbuf(stdin,NULL);
		scanf("%s",data.username);
		//gets(data.password);
		getchar();
		printf("===================================================================\n");
		account_list_t temp = Account_Srv_FindByUsrName(list,data.username);
    	if(temp!=NULL){
			printf("this user is already have\n");
			printf("[A]dd other, [R]eturn:");
			setbuf(stdin,NULL);
			scanf("%c", &choice);
			getchar();

    	}
    	else{
    	    printf("please input you want passsword :");
			setbuf(stdin,NULL);
        	//getchar();
			scanf("%s",data.password);
			//gets(data.password);
			getchar();
			printf("please input you want type :\n");
			printf("===================================================================\n");
			printf("[0]匿名用户  |  [1]售票员  |  [2]经理  |  [9]系统管理员:");

			setbuf(stdin,NULL);
			scanf("%d",&data.type);
			getchar();
    	    if(Account_Srv_Add(&data)){
				newRecCount += 1;
				Account_Srv_FetchAll(list);
				printf("The new user added successfully!\n");
			}
			else
			printf("The new room added failed!\n");
		printf("-------------------------------------------------------------------\n");
		printf("[A]dd more, [R]eturn:");
		setbuf(stdin,NULL);
		scanf("%c", &choice);
		char ch;while((ch=getchar())!='\n'&&ch!=EOF);
		//printf("%d   ss",choice);
		//getchar();

    	}
	}while('a' == choice || 'A' == choice);
	return newRecCount;
}


//修改系统用户界面
int Account_UI_Modify(account_list_t list,char usrName[]){
	account_list_t temp = Account_Srv_FindByUsrName(list,usrName);
	if(temp != NULL){
		int choice = 10;
		do{
			char password[20];
			printf("prease input the new password:");
			setbuf(stdin,NULL);
			//char ch;while((ch=getchar())!='\n'&&ch!=EOF);
			scanf("%s", password);
			if(strcmp(password,temp->data.password)==0){
				printf("mod error,password the same,please choice next\n");
				printf("[0]exit  |   [1]input again\n");
				scanf("%d",&choice);
				setbuf(stdin,NULL);
			}
			else{
				strcpy(temp->data.password,password);
				int aaa = Account_Srv_Modify(temp);
				if(aaa == 0){
					return 0;
				}
				Account_Srv_FetchAll(list);
				
				return 1;
			}
		}while(choice!=0);
    }
	else{
		printf("The room does not exist!\n");
		return 0;
	}
	

}

//删除系统用户界面
int Account_UI_Delete(account_list_t list,char usrName[]){
	account_list_t temp = Account_Srv_FindByUsrName(list,usrName);
	if(temp != NULL){
		Account_Srv_DeleteByID(temp->data.id);
		Account_Srv_FetchAll(list);
		return 1;
	}
	return 0;

}

//查询用户界面
int Account_UI_Query(account_list_t list,char usrName[]){
	account_list_t temp = Account_Srv_FindByUsrName(list,usrName);
	if(temp != NULL){
		printf("user ID:%d\n",temp->data.id);
		printf("user password:%s\n",temp->data.password);
		printf("user username:%s\n",temp->data.username);
		printf("user type:%c\n",Account_UI_Status2Char(temp->data.type));
		//printf("\n\n\n\n\n\n\n\n\n");
		return 1;
	}
	return 0;
}
