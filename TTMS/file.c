#include<stdio.h>
#include"wenjian.h"


int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);    //取消标准输出缓冲区   
	Student_InitFile();
}



