#include<stdio.h>

int time_judge(int year,int month,int day)
{
	int flag = 1;
	int found = 1;   //这起始 值  为 平年
	if(year%4==0&&year%100!=0&&year%200!=0&&year%300!=0&&year%400!=0)   //判断这一年 是否为闰年
	{
		found = 0;   //  闰年
	}

	if(found == 1)
	{
		switch(month)
		{
			case 1:
				if(day <= 0 || day > 31)
				{
					printf( " January is January 1 - 31\n");
					flag = 0;
				}
				break;
			case 2:
				if(day <= 0 || day > 28)
				{
					printf( "February is 1-28 in %d year .\n",year);
					flag = 0;
				}
				break;
			case 3:
				if(day <= 0 || day > 31)
				{
					printf( " March is 1 - 31\n ");
					flag = 0;
				}
				break;
			case 4:
				if(day <= 0 || day > 30)
				{
					printf( " April is from 1 to 30. \n");
					flag = 0;
				}
				break;
			case 5:
				if(day <= 0 || day > 31)
				{
					printf( " May is from 1 - 31\n ");
					flag = 0;
				}
				break;
			case 6:
				if(day <= 0 || day > 30)
				{
					printf( "June is from 1 - 30\n");
					flag = 0;
				}
				break;
			case 7:
				if(day <= 0 || day > 31)
				{
					printf( "July is from 1 - 31\n");
					flag = 0;
				}
				break;
			case 8:
				if(day <= 0 || day > 31)
				{
					printf( "August is from 1 - 31\n");
					flag = 0;
				}
				break;
			case 9:
				if(day <= 0 || day > 30)
				{
					printf( "September is from 1 - 30\n");
					flag = 0;
				}
				break;
			case 10:
				if(day <= 0 || day > 31)
				{
					printf( "October is from 1 - 31\n");
					flag = 0;
				}
				break;
			case 11:
				if(day <= 0 || day > 30)
				{
					printf( "November is from 1 - 30\n");
					flag = 0;
				}
				break;
			case 12:
				if(day <= 0 || day > 31)
				{
					printf( "December is from 1 - 31\n");
					flag = 0;
				}
				break;

		}
	}
	else
	{
		switch(month)
		{
			case 1:
				if(day <= 0 || day > 31)
				{
					printf( " January is January 1 - 31\n");
					flag = 0;
				}
				break;
			case 2:
				if(day <= 0 || day > 28)
				{
					printf( "February is 1-28 in %d year .\n",year);
					flag = 0;
				}
				break;
			case 3:
				if(day <= 0 || day > 31)
				{
					printf( " March is 1 - 31\n ");
					flag = 0;
				}
				break;
			case 4:
				if(day <= 0 || day > 30)
				{
					printf( " April is from 1 to 30. \n");
					flag = 0;
				}
				break;
			case 5:
				if(day <= 0 || day > 31)
				{
					printf( " May is from 1 - 31\n ");
					flag = 0;
				}
				break;
			case 6:
				if(day <= 0 || day > 30)
				{
					printf( "June is from 1 - 30\n");
					flag = 0;
				}
				break;
			case 7:
				if(day <= 0 || day > 31)
				{
					printf( "July is from 1 - 31\n");
					flag = 0;
				}
				break;
			case 8:
				if(day <= 0 || day > 31)
				{
					printf( "August is from 1 - 31\n");
					flag = 0;
				}
				break;
			case 9:
				if(day <= 0 || day > 30)
				{
					printf( "September is from 1 - 30\n");
					flag = 0;
				}
				break;
			case 10:
				if(day <= 0 || day > 31)
				{
					printf( "October is from 1 - 31\n");
					flag = 0;
				}
				break;
			case 11:
				if(day <= 0 || day > 30)
				{
					printf( "November is from 1 - 30\n");
					flag = 0;
				}
				break;
			case 12:
				if(day <= 0 || day > 31)
				{
					printf( "December is from 1 - 31\n");
					flag = 0;
				}
		}

	}


	
	return flag;
}
