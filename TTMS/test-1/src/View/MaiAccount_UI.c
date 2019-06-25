#include "MaiAccount_UI.h"
#include <string.h>
#include <stdio.h>
#include "../Common/list.h"
#include "../Service/Account.h"

const int len = 20;
/*int getch()
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
}*/

//维护个人资料界面
void MaiAccount_UI_MgtEntry () {
    system("clear");
    account_t cdata = gl_CurUser;
    char cpassword1[30],cpassword[30];
    printf("you have 3 times to input you now password\n");
    printf("please input you now password:");
    setbuf(stdin,NULL);
    for(int i=  0;i<len;i++)
    {
        cpassword[i] = getch();
        if(cpassword[i] == '\n')
        {
            cpassword[i] = '\0';
            break;
        }
        if((int)cpassword[i] == 127)
        {
            printf("\b \b");
            i = i-2;
        }
        else
        {
            printf("*");
        }
        if(i < 0) cpassword[0] = '\0';
    }
    if(strcmp(cdata.password,cpassword)==0){
        printf("accept!!\n");
        int j = 3;
        while(j--){
            printf("\nyou have %d times\n",j);
            printf("please input you new password:");
            for(int i=  0;i<len;i++)
            {
                cpassword[i] = getch();
                if(cpassword[i] == '\n')
                {
                    cpassword[i] = '\0';
                    break;
                }
                if((int)cpassword[i] == 127)
                {
                    printf("\b \b");
                    i = i-2;
                }
                else
                {
                    printf("*");
                }
                if(i < 0) cpassword[0] = '\0';
            }

                if(strcmp(cdata.password,cpassword)==0){
                printf("\nthe password is same as you old password,please input again!!");
                }
                else{
                printf("\nplease input the password again and the password is same like before!\n");
                setbuf(stdin,NULL);
                for(int i=  0;i<len;i++)
                {
                    cpassword1[i] = getch();
                    if(cpassword1[i] == '\n')
                    {
                        cpassword1[i] = '\0';
                        break;
                    }
                    if((int)cpassword1[i] == 127)
                    {
                        printf("\b \b");
                        i = i-2;
                    }
                    else
                    {
                        printf("*");
                    }
                    if(i < 0) cpassword1[0] = '\0';
                }
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
        printf("\nyou have %d times to input you now password\n",i);
        printf("the password input error!!please input you now password again:");
        setbuf(stdin,NULL);
        for(int i=  0;i<len;i++)
        {
            cpassword[i] = getch();
            if(cpassword[i] == '\n')
            {
                cpassword[i] = '\0';
                break;
            }
            if((int)cpassword[i] == 127)
            {
                printf("\b \b");
                i = i-2;
            }
            else
            {
                printf("*");
            }
            if(i < 0) cpassword[0] = '\0';
        }
        if(strcmp(cdata.password,cpassword)==0){
            printf("accept!!\n");
            int j = 3;
            while(j--){
                printf("you have %d times\n",j);
                printf("please input you new password:");
                setbuf(stdin,NULL);
                for(int i=  0;i<len;i++)
                {
                    cpassword[i] = getch();
                    if(cpassword[i] == '\n')
                    {
                        cpassword[i] = '\0';
                        break;
                    }
                    if((int)cpassword[i] == 127)
                    {
                        printf("\b \b");
                        i = i-2;
                    }
                    else
                    {
                        printf("*");
                    }
                    if(i < 0) cpassword[0] = '\0';
                }
                    if(strcmp(cdata.password,cpassword)==0){
                    printf("the password is same as you old password,please input again!!");
                    }
                    else{
                    printf("\nplease input the password again and the password is same like before!\n");
                    setbuf(stdin,NULL);
                    for(int i=  0;i<len;i++)
                    {
                        cpassword1[i] = getch();
                        if(cpassword1[i] == '\n')
                        {
                            cpassword1[i] = '\0';
                            break;
                        }
                        if((int)cpassword1[i] == 127)
                        {
                            printf("\b \b");
                            i = i-2;
                        }
                        else
                        {
                            printf("*");
                        }
                        if(i < 0) cpassword1[0] = '\0';
                    }
                    printf("%s\n",cpassword1);
                    if(strcmp(cpassword,cpassword1)==0){
                        strcpy(cdata.password,cpassword);
                        Account_Srv_Modify(&cdata);
                        return 1;
                    }
                    else{
                        printf("\nThe passwords entered two times are inconsistent. Please try again.\n");
                    }
                }
            }
            return 0;
        }
    }
    return 0;
}
