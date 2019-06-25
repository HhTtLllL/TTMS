/*
 * account.c
 *
 *  Created on: 2015年6月12日
 *      Author: Administrator
 */
#include "Account.h"
#include "../Common/list.h"
#include "../Persistence/Account_Persist.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

 account_t gl_CurUser;

//创建系统初始化账号admin
void Account_Srv_InitSys(){
	if(Account_Perst_CheckAccFile()==1){
		return ;
	}
	account_t data_admin;
	printf("it is no Account.dat,please init admin!!");
	setbuf(stdin,NULL);
    getchar();
	printf("please input you want init name :");
	setbuf(stdin,NULL);
    //getchar();
	gets(data_admin.username);
	//printf("%s\n",data_admin.username);
	printf("please input you want passsword :");
	setbuf(stdin,NULL);
	scanf("%s",data_admin.password);
	//printf("%s\n",data_admin.password);
	setbuf(stdin,NULL);
	printf("[0]anonymous   |   [1]Conductor   |   [2]manager   |   [9]admin");
	printf("(!!!admin must!!!)please input you want type ,plseae input [9]:");
	setbuf(stdin,NULL);
	scanf("%d",&data_admin.type);
	//printf("%d\n",data_admin.type);
	setbuf(stdin,NULL);
	Account_Srv_Add(&data_admin);

}

//验证登录账号是否已存在，存在，保存登录用户信息到全局变量gl_CurUser，return 1；否则return 0
inline int Account_Srv_Verify(char usrName[], char pwd[]){
	account_t usr;
	
	if(Account_Perst_SelByName(usrName,&usr)){
		if(strcmp(usr.password,pwd) == 0){
			gl_CurUser = usr;
			return 1;
		}
		else{
			return 0;
		}
	}
	return 0;
}


//验证用户名是否存在，遍历list，若存在，返回对应结点指针；否则，返回null
account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	account_list_t temp = list;
	while(list->next != temp){
		list = list->next;
		if(strcmp(usrName,list->data.username) == 0){
			return list;
		}
	}
	return NULL ;
}

//添加一个用户账号，通过调用Account_Perst_Insert(data)函数实现
inline int Account_Srv_Add(const account_t *data){
    return Account_Perst_Insert(data);

}

//修改一个用户账号，通过调用Account_Perst_Update(data)函数实现
inline int Account_Srv_Modify(const account_t *data){
	return Account_Perst_Update(data);
}

//删除一个用户账号，通过调用Account_Perst_DeleteByID(usrID)函数实现
inline int Account_Srv_DeleteByID(int usrID){
	return Account_Perst_DeleteByID(usrID);

}

//提取usrID对应的用户账号信息，通过调用Account_Perst_SelectByID(usrID, buf)函数实现
inline int Account_Srv_FetchByID(int usrID, account_t *buf){
	return Account_Perst_SelectByID(usrID, buf);
	
}

//提取usrName对应的用户账号信息，通过调用Account_Perst_SelByName(usrName, buf)函数实现
inline int Account_Srv_FetchByName(char usrName[], account_t *buf){
	return Account_Perst_SelByName(usrName, buf);

}

//提取所有用户账号信息，保存到list链表中，通过调用Account_Perst_SelectAll(list)函数实现
 int Account_Srv_FetchAll(account_list_t list){
    return Account_Perst_SelectAll(list);
  
}
