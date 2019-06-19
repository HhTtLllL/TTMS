/*#include "StaSales_UI.h"
#include <time.h>
#include "../Common/List.h"
#include "../Service/Sale.h"
#include "../Service/Account.h"

//统计销售额界面
void StaSales_UI_MgtEntry (){
    if(GI_CurUser.type==USR_CLERK){
        StaSales_UI_Self();
    }
    else if(GI_CurUser.type==USR_MANG){
        StaSales_UI_Clerk();
    }
}

//统计个人销售额界面
void StaSales_UI_Self(){
    int id = GI_CurUser.id;
    char choice;
    typedef struct{
        ttms_date_t curdate,startdate,enddate;
    }user_date_t;
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
        Salesanalysis_Srv_CompSaleVal(id,curdate,curdate);
        break;
        case 'm':
        case 'M'://当月
        Salesanalysis_Srv_CompSaleVal(id,startdate,enddate);
        break;
    }


}

//统计售票员销售额界面
void StaSales_UI_Clerk(){
    account_t tem;
    int id = GI_CurUser.id;
    struct user_date_t;{
        ttms_date_t curdate,startdate,enddate;
    };
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

    char Usrname[20];
    printf("please input the shouhuyuan username:");
    scanf("%s",Usrname);
    Account_Srv_FetchByName(Usrname,&tem);
    id = tem.id;
    printf("please input startdate:");
    scanf("%d",);
    printf("please input enddate:");
    scanf("%d",);
    if(){

    }
    else{
        return 0;
    }
    Salesanalysis_Srv_CompSaleVal(id,startdate,enddate);
    
}
*/