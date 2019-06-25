#ifndef ACCOUNT_UI_H_
#define ACCOUNT_UI_H_
#include"../Service/Account.h"


//标识符：TTMS_SCU_Studio_UI_Add 
//功能：添加新演出厅界面
int Account_UI_Add(account_list_t list);

//标识符：TTMS_SCU_Studio_UI_Mod
//功能：根据ID修改演出厅界面
int Account_UI_Modify(account_list_t,char usrName[]);


//标识符：TTMS_SCU_Studio_UI_Del
//功能：根据ID删除演出厅界面 
int Account_UI_Delete(account_list_t list,char usrName[]);

//标识符：TTMS_SCU_Studio_UI_MgtEnt  
//功能：根据ID删除演出厅界面 
void Account_UI_MgtEntry();

int Account_UI_Query(account_list_t list,char usrName[]);
//功能：根据ID删除演出厅界面

#endif /* ACCOUNT_UI_H_ */
