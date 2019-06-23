#include "MaiAccount_UI.h"
#include <string.h>
#include <stdio.h>
#include "../Common/list.h"
#include "../Service/Account.h"
//extern  account_t gl_CurUser;
//维护个人资料界面
void MaiAccount_UI_MgtEntry () {
    system("clear");
    account_t cdata = gl_CurUser;
    char cpassword1[30],cpassword[30];
    printf("you have 3 times to input you now password\n");
    printf("please input you now password:");
    setbuf(stdin,NULL);
    scanf("%s",cpassword);
    if(strcmp(cdata.password,cpassword)==0){
        printf("accept!!\n");
        int j = 3;
        while(j--){
            printf("you have %d times\n",j);
            printf("please input you new password:");
            setbuf(stdin,NULL);
            scanf("%s",cpassword);
                if(strcmp(cdata.password,cpassword)==0){
                printf("the password is same as you old password,please input again!!");
                }
                else{
                printf("please input the password again and the password is same like before!\n");
                setbuf(stdin,NULL);
                scanf("%s",cpassword1);
                if(strcmp(cpassword,cpassword1)==0){
                    strcpy(cdata.password,cpassword);
                    Account_Srv_Modify(&cdata);
                    return 1;
                }
                else{
                    printf("The passwords entered two times are inconsistent. Please try again.\n");
                }
            }
        }
        return 0;
    }
    int i = 2;
    while(i--){
        printf("you have %d times to input you now password\n",i);
        printf("the password input error!!please input you now password again:");
        setbuf(stdin,NULL);
        scanf("%s",cpassword);
        if(strcmp(cdata.password,cpassword)==0){
            printf("accept!!\n");
            int j = 3;
            while(j--){
                printf("you have %d times\n",j);
                printf("please input you new password:");
                setbuf(stdin,NULL);
                scanf("%s",cpassword);
                    if(strcmp(cdata.password,cpassword)==0){
                    printf("the password is same as you old password,please input again!!");
                    }
                    else{
                    printf("please input the password again and the password is same like before!\n");
                    setbuf(stdin,NULL);
                    scanf("%s",cpassword1);
                    if(strcmp(cpassword,cpassword1)==0){
                        strcpy(cdata.password,cpassword);
                        Account_Srv_Modify(&cdata);
                        return 1;
                    }
                    else{
                        printf("The passwords entered two times are inconsistent. Please try again.\n");
                    }
                }
            }
            return 0;
        }
    }
    return 0;
}
