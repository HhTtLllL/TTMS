#include "StaSales_UI.h"
#include <time.h>
#include "../Common/list.h"
#include "../Service/Sale.h"
#include "../Service/Account.h"
#include "../Service/SalesAnalysis.h"
//统计销售额界面
void StaSales_UI_MgtEntry (){

    if(gl_CurUser.type==USR_CLERK){
        StaSales_UI_Self();
    }
    else if(gl_CurUser.type==USR_MANG){
        StaSales_UI_Clerk();
    }
    else{
        printf("you can't join in there!please input the [Enter]");
        getchar();
    }
}

//统计个人销售额界面
void StaSales_UI_Self(){
    int id = gl_CurUser.id;
    char choice;

    ttms_date_t curdate,startdate,enddate;
    struct tm *p;
    time_t timep;
    p = localtime(&timep);
    curdate.year = p->tm_year + 1900;
    curdate.month = p->tm_mon + 1;
    curdate.day = p->tm_mday;
    startdate.year = p->tm_year + 1900;
    startdate.month = p->tm_mon + 1;
    startdate.day = 1;
    enddate.year = p->tm_year + 1900;
    enddate.month = p->tm_mon + 1;
    enddate.day = 31;
    switch(choice){
        case 'd':
        case 'D'://当日
        printf("Your sales this day are %d\n",SalesAnalysis_Srv_CompSaleVal(id,curdate,curdate));
        break;
        case 'm':
        case 'M'://当月
        printf("Your sales this month are %d\n",SalesAnalysis_Srv_CompSaleVal(id,startdate,enddate));
        break;
    }


}

//统计售票员销售额界面
void StaSales_UI_Clerk(){
    account_t tem;
    int id;

    ttms_date_t startdate,enddate;

    char Usrname[20];
    printf("please input the Salesperson username:");
    scanf("%s",Usrname);
    if(Account_Srv_FetchByName(Usrname,&tem)){
        if(tem.type!=USR_CLERK){
            printf("This man is not a salesman,please input [Enter]");
            getchar();
            return ;
        }
        id = tem.id;
        printf("please input startdate(year month day):");
        scanf("%d%d%d",startdate.year,startdate.month,startdate.day);
        printf("please input enddate(year month day):");
        scanf("%d%d%d",enddate.year,enddate.month,enddate.day);
        printf("The salesman's sales during this period are %d\n",SalesAnalysis_Srv_CompSaleVal(id,startdate,enddate));
    }
    else{
        printf("the user is not in this company!!,please input [Enter]");
        getchar();
        return 0;
    }
}

