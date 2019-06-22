#include "MaiAccount_UI.h"
#include <string.h>
#include <stdio.h>
#include "../Common/list.h"
#include "../Service/Account.h"
//extern  account_t gl_CurUser;
//维护个人资料界面
void MaiAccount_UI_MgtEntry () {
    account_t cdata = gl_CurUser;
    char cpassword[30];
    printf("please input you now password:");
    setbuf(stdin,NULL);
    scanf("%s",cpassword);

    strcpy(cdata.password,cpassword);

    Account_Srv_Modify(&cdata);
}
