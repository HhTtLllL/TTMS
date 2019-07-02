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
#include "../Common/md5.h"


 account_t gl_CurUser;
const int len1;
//创建系统初始化账号admin
void Account_Srv_InitSys(){
	if(Account_Perst_CheckAccFile()==1){
		return ;
	}
	char encrypt[20];
	unsigned char decrypt[16];
	account_t data_admin;
	printf("it is no Account.dat,please init admin!!please input[E]nter");
	setbuf(stdin,NULL);
    getchar();
	printf("please input you want init name :");
	setbuf(stdin,NULL);
    //getchar();
	gets(data_admin.username);
	
	printf("please input you want passsword :");
	setbuf(stdin,NULL);
	//scanf("%s",encrypt);

	for (int i = 0; i < len1; i++)
	{
		encrypt[i] = getch();
		if (encrypt[i] == '\n')
		{
			encrypt[i] = '\0';
			break;
		}
		if ((int)encrypt[i] == 127)
		{
			printf("\b \b");
			i = i - 2;
		}
		else
		{
			printf("*");
		}
		if (i < 0)
			encrypt[0] = '\0';
	}

	MD5_CTX md5;
	MD5Init(&md5);         		
	MD5Update(&md5,encrypt,strlen((char *)encrypt));
	MD5Final(&md5,decrypt);
	//printf("加密前:%s\n加密后:",encrypt);
	for(int i=0;i<16;i++)
	{
		//printf("%02x",decrypt[i]);
		data_admin.password[i] = decrypt[i];
	}
	
	//getchar();
	/*putchar('\n');
	for(int i=0;i<16;i++)
	{
		printf("%02x",data_admin.password[i]);
	}*/
	setbuf(stdin,NULL);
	printf("\n[0]anonymous   |   [1]Conductor   |   [2]manager   |   [9]admin");
	printf("(!!!admin must!!!)please input you want type ,plseae input [9]:");
	setbuf(stdin,NULL);
	scanf("%d",&data_admin.type);
	getchar();

	printf("please input your mibao number:(only you know):\n");
	scanf("%s",data_admin.mipao);
	//printf("%s",data_admin.mipao);
	getchar();

	setbuf(stdin,NULL);
	Account_Srv_Add(&data_admin);

}

//验证登录账号是否已存在，存在，保存登录用户信息到全局变量gl_CurUser，return 1；否则return 0
inline int Account_Srv_Verify(char usrName[],unsigned char pwd[]){
	account_t usr;
	
	if(Account_Perst_SelByName(usrName,&usr)){
		int x = 1;
		for(int i = 0;i < 16;i++){
			
			if(pwd[i]!=usr.password[i])
				x = 0;
		}
		if(x){
			gl_CurUser = usr;
			return 1;
		}
		else{
			return 0;
		}
	}
	return 0;
}


int Account_Srv_Verifyno(char usrName[]){
	account_t usr;
	if(Account_Perst_SelByName(usrName,&usr)){
			gl_CurUser = usr;
			return 1;
	}
	else{
		return 0;
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
