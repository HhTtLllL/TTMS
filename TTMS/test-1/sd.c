/*/*
 * Account_UI.c
 *
 *  Created on: 2015��4��24��
 *      Author: Administrator
 */
#include "../View/Account_UI.h"

#include "../Common/List.h"
#include "../Service/Account.h"
#include <stdio.h>
#include <stdlib.h>
//#include "curses.h"
//#include <conio.h>
#define SIZE 5
#define len 100




#include<termios.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>

int getch()
{
 int c=0;
 struct termios org_opts, new_opts;
    int res=0;
    //-----  store old settings -----------
     res=tcgetattr(STDIN_FILENO, &org_opts);
     assert(res==0);
   //---- set new terminal parms --------
  memcpy(&new_opts, &org_opts, sizeof(new_opts));
  new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
  c=getchar();
   //------  restore old settings ---------
  res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
  assert(res==0);
  return c;
}









int SysLogin(){
	int i=1;
	if(i==1)
	{
		Account_Srv_InitSys();
		i++;
	}

	char name[30],passwd[30];

	int t;
	char *p;
	char ch;
	for(int i=0;i<3;i++)
	{
		printf("请输入用户名：");
		while(getchar()!='\n');
		scanf("%s",name);
		while(1)
   		{
    	printf("\n请输入密码:");
    	for(int i=  0;i<len;i++)
		{
			setbuf(stdin,NULL);
			passwd[i] = getch();
			if(passwd[i] == '\n')
			{
				passwd[i] = '\0';
				break;
			}
			if((int)passwd[i] == 127)
			{
				printf("\b \b");
				i = i-2;
			}
			else
			{
				printf("*");
			}
			if(i < 0) passwd[0] = '\0';
		}

		   }
		t=Account_Srv_Vertify(name,passwd);
		if(t==1)
		{
			printf("登陆成功！");
			return 1;
		}	
		else
		{
			printf("输入错误，请重新输入！");
		}
		
	}

	return 0;

}

//ϵͳ�û���������
void Account_UI_MgtEntry(){
	account_list_t head;
	account_node_t *pos;
	head=(account_list_t)malloc(sizeof(account_node_t));
	pos=(account_node_t *)malloc(sizeof(account_node_t));
	int i;
	char name[100];
	//List_Init(head,account_node_t);

	Pagination_t paging;

	List_Init(head, account_node_t);
	paging.offset = 0;
	paging.pageSize = SIZE;
	int choice;

	//��������
	paging.totalRecords = Account_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
	system("clear");
	// List_ForEach(head,pos)
	// {
	// 	printf("%5d  %5d  %10s  %10s\n", pos->data.id,
	// 				pos->data.type, pos->data.username, pos->data.password);
	// }

	do {
		
		printf("\n============================================================\n");
		printf("********************** 系统用户信息 ***************************\n");
		printf("%5s  %5s  %10s  %10s  \n", "ID", "类型", "用户名","密码");
		printf("----------------------------------------------------------------\n");
		//��ʾ����
		
		Paging_ViewPage_ForEach(head, paging, account_node_t, pos, i){
			printf("%5d  %5d  %10s  %10s\n", pos->data.id,
					pos->data.type, pos->data.username, pos->data.password);
		}

		printf("-----------------总计:%2d ----------------------- Page %2d/%2d -------------------------\n",
				paging.totalRecords, Pageing_CurPage(paging),Pageing_TotalPages(paging));
		printf("**********************************************************\n");
		printf("[1]上一页|[2]下一页 | [3]添加系统用户|[4]修改系统用户密码|[5]删除系统用户 | [6]查询系统用户 | [0]eturn");
		printf("\n=================================================================\n");
		
		fflush(stdin);
		printf("Your Choice：");
		fflush(stdin);
		scanf("%d", &choice);
		//printf("chiocce  = %c",choice);
		fflush(stdin);
		

		switch (choice) {
		case 3:system("clear");
			if (Account_UI_Add(head)) //�����ӳɹ����������һҳ��ʾ
			{
				paging.totalRecords = Account_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, account_node_t);
			}
			break;
		case 4:system("clear");
			printf("输入你要修改的用户名:");
			scanf("%s", name);
			if (Account_UI_Modify(head,name)) {	//������������
				paging.totalRecords = Account_Srv_FetchAll(head);
				List_Paging(head, paging, account_node_t);
			}
			break;
		case 5:system("clear");
			printf("请输入要删除的用户名：");
			scanf("%s", name);
			if (Account_UI_Delete(head,name)) {	//������������
				paging.totalRecords = Account_Srv_FetchAll(head);
				List_Paging(head, paging, account_node_t);
			}
			break;
		case 6:system("clear");
			printf("请输入要查询的用户名：");
			scanf("%s",name);
			if(Account_UI_Query(head,name))
			paging.totalRecords = Account_Srv_FetchAll(head);
			List_Paging(head, paging, account_node_t)
			;
			break;
		case 1:system("clear");
			if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, account_node_t);
			}
			break;
		case 2:system("clear");
			if (!Pageing_IsLastPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, account_node_t);
			}
			break;
		}
	} while (choice != 0);
	//�ͷ������ռ�
	List_Destroy(head, account_node_t);

}

//������ϵͳ�û�����
int  Account_UI_Add(account_list_t list){
	char name1[100];
	printf("请输入要添加的用户名称：");
	scanf("%s",name1);


	

	account_node_t *buf;
	buf=(account_list_t)malloc(sizeof(account_node_t));

	account_list_t flag;
	flag=(account_list_t)malloc(sizeof(account_node_t));
	flag=Account_Srv_FindByUsrName(list,name1);


	
	char passwd[len];
    char passwd2[len];
	if(flag==NULL)
	{

	while(1)
    {
    	printf("\n请输入密码:");
    	for(int i=  0;i<len;i++)
		{
			setbuf(stdin,NULL);
			passwd[i] = getch();
			if(passwd[i] == '\n')
			{
				passwd[i] = '\0';
				break;
			}
			if((int)passwd[i] == 127)
			{
				printf("\b \b");
				i = i-2;
			}
			else
			{
				printf("*");
			}
			if(i < 0) passwd[0] = '\0';
		}
		printf("\n请再次输入密码:");
		for(int i=  0;i<len;i++)
		{
			setbuf(stdin,NULL);
			passwd2[i] = getch();
			if(passwd2[i] == '\n')
			{
				passwd2[i] = '\0';
				break;
			}
			if((int)passwd2[i] == 127)
			{
				printf("\b \b");
				i = i-2;
			}
			else
			{
				printf("*");
			}
			if(i < 0) passwd2[0] = '\0';
		}
		if(strcmp(passwd,passwd2) == 0)
		{
			//printf("\n您输入的密码是:%s",passwd2);
			break;
		}
		else
		{
		printf("\n两次输入不一致!"); 
		}
    
    }

		// char ch;
		// char *p=buf->data.password;
		// while((ch=getchar())!='\n')
		// {
		// 	*p=ch;
		// 	p++;
		// }

		strcpy(buf->data.password,passwd);
		printf("\n输入id：");
		scanf("%d",&buf->data.id);	
		printf("输入用户类型（0,1,2,3）：");
		scanf("%d",&buf->data.type);
		strcpy(buf->data.username,name1);
		// printf("啊哈");
		// setbuf(stdin,NULL);
		// getchar();
		
	
		Account_Srv_Add(&buf->data);
		// printf("啊哈");
		// setbuf(stdin,NULL);
		// getchar();
		
		
		List_AddTail(list,buf);
		// printf("啊哈");
		// setbuf(stdin,NULL);
		// getchar();
		// system("pause");
		// system("clear");
		
		return 1;
	}
	
	else
	{
		printf("出错！用户已存在！");
		// getchar();
		// system("clear");
		return 0;
	}

}

//�޸�ϵͳ�û�����
int Account_UI_Modify(account_list_t list,char usrName[]){
	account_node_t *flag;
	flag=(account_list_t)malloc(sizeof(account_node_t));
	flag=Account_Srv_FindByUsrName(list,usrName);	
	

	char passwd[len];
    char passwd2[len];
	if(flag==NULL)
	{
		printf("该用户不存在！");
		// getchar();
		// system("clear");
		return;
	}
	else
	{
		while(1)
    {
		char passwd[len];
    	char passwd2[len];
    	printf("\n请输入密码:");
    	for(int i=  0;i<len;i++)
		{
			setbuf(stdin,NULL);
			passwd[i] = getch();
			if(passwd[i] == '\n')
			{
				passwd[i] = '\0';
				break;
			}
			if((int)passwd[i] == 127)
			{
				printf("\b \b");
				i = i-2;
			}
			else
			{
				printf("*");
			}
			if(i < 0) passwd[0] = '\0';
		}
		printf("\n请再次输入密码:");
		for(int i=  0;i<len;i++)
		{
			setbuf(stdin,NULL);
			passwd2[i] = getch();
			if(passwd2[i] == '\n')
			{
				passwd2[i] = '\0';
				break;
			}
			if((int)passwd2[i] == 127)
			{
				printf("\b \b");
				i = i-2;
			}
			else
			{
				printf("*");
			}
			if(i < 0) passwd2[0] = '\0';
		}
		if(strcmp(passwd,passwd2) == 0)
		{
			//printf("\n您输入的密码是:%s",passwd2);
			break;
		}
		else
		{
		printf("\n两次输入不一致!"); 
		}
		
	}




		strcpy(flag->data.password,passwd);
		// printf("啊哈");
		// setbuf(stdin,NULL);
		// getchar();
		
		Account_Srv_Modify(flag);
		// getchar();
		// system("clear");


	}


	return 1;

}

//ɾ��ϵͳ�û�����
int Account_UI_Delete(account_list_t list,char usrName[]){
	account_node_t *flag;
	flag=(account_list_t)malloc(sizeof(account_node_t));
	flag=Account_Srv_FindByUsrName(list,usrName);	
// printf("啊哈");
// 		setbuf(stdin,NULL);
// 		getchar();
	if(flag==NULL)
	{
		printf("该用户不存在！");
		// getchar();
		// system("clear");
		return;
	}
	else
	{
		// printf("啊哈1");
		// setbuf(stdin,NULL);
		// getchar();
		Account_Srv_DeleteByID(flag->data.id);
	// 	printf("啊哈2");
	// 	setbuf(stdin,NULL);
	// 	getchar();
 }
	


	return 1;

}

//��ѯϵͳ�û�����
int Account_UI_Query(account_list_t list,char usrName[]){
	account_node_t *flag;
	flag=(account_list_t)malloc(sizeof(account_node_t));
	flag=Account_Srv_FindByUsrName(list,usrName);	

	if(flag==NULL)
	{
		printf("该用户不存在！");
		return 0;
	}
	else
	{
		printf("id-------------%d\n",flag->data.id);
		printf("用户名----------%s\n",flag->data.username);
		printf("密码------------%s\n",flag->data.password);
		printf("用户类型---------%d\n",flag->data.type);
		printf("\n\n\n\n\n\n\n\n\n");
		// getchar();
		// system("clear");
	}
	return 1;

}



