#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
const int len = 20;
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
int main()
{
    while(1)
    {
    char passwd[len];
    char passwd2[len];
    printf("\n请输入密码:");
    for(int i=  0;i<len;i++)
    {
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
        printf("\n您输入的密码是:%s",passwd2);
        break;
    }
    else
    {
       printf("\n两次输入不一致!"); 
    }
    }
}

