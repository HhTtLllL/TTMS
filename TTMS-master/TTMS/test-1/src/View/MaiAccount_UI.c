#include "MaiAccount_UI.h"
#include <string.h>
#include <stdio.h>
#include "../Common/list.h"
#include "../Service/Account.h"
#include "../Common/md5.h"

const int len = 20;

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

    unsigned char decrypt[16];
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5, cpassword, strlen((char *)cpassword));
    MD5Final(&md5, decrypt);
    int x = 1;
    for(int i = 0;i < 16;i++){
        
        if(decrypt[i]!=cdata.password[i])
            x = 0;
    }

    if(x){
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

                unsigned char decrypt[16];
                MD5_CTX md5;
                MD5Init(&md5);
                MD5Update(&md5, cpassword, strlen((char *)cpassword));
                MD5Final(&md5, decrypt);
                int x = 1;
                for(int i = 0;i < 16;i++){
                    
                    if(decrypt[i]!=cdata.password[i])
                        x = 0;
                }

                if(x){
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


                unsigned char decrypt1[16];
                MD5_CTX md51;
                MD5Init(&md51);
                MD5Update(&md51, cpassword1, strlen((char *)cpassword1));
                MD5Final(&md51, decrypt1);
                int x1 = 1;
                for(int i = 0;i < 16;i++){    
                    if(decrypt1[i]!=decrypt[i])
                        x1 = 0;
                }



                if(x){
                    for(int i=0;i<16;i++)
                    {
                        cdata.password[i] = decrypt[i];
                    }
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

        unsigned char decrypt[16];
        MD5_CTX md5;
        MD5Init(&md5);
        MD5Update(&md5, cpassword, strlen((char *)cpassword));
        MD5Final(&md5, decrypt);
        int x = 1;
        for(int i = 0;i < 16;i++){
            
            if(decrypt[i]!=cdata.password[i])
                x = 0;
        }


        if(x){
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

                unsigned char decrypt[16];
                MD5_CTX md5;
                MD5Init(&md5);
                MD5Update(&md5, cpassword, strlen((char *)cpassword));
                MD5Final(&md5, decrypt);
                int x = 1;
                for(int i = 0;i < 16;i++){
                    
                    if(decrypt[i]!=cdata.password[i])
                        x = 0;
                }



                    if(x){
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

                    unsigned char decrypt1[16];
                    MD5_CTX md51;
                    MD5Init(&md51);
                    MD5Update(&md51, cpassword1, strlen((char *)cpassword1));
                    MD5Final(&md51, decrypt1);
                    int x1 = 1;
                    for(int i = 0;i < 16;i++){    
                        if(decrypt1[i]!=decrypt[i])
                            x1 = 0;
                    }

                    if(x1){
                        for(int i=0;i<16;i++)
                        {
                            cdata.password[i] = decrypt[i];
                        }
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
