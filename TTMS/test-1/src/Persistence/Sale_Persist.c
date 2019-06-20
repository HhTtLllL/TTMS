#include"../Common/list.h"
#include"Sale_Persist.h"
#include"EntityKey_Persist.h"
#include"../Service/Sale.h"
#include<stdio.h>


static const char SALE_DATA_FILE[] = "Sale.dat";
static const char SALE_DATA_TEMP_FILE[] = "SaleTmp.dat";
static const char SALE_KEY_NAME[] = "Sale";

int Sale_Perst_Insert(sale_t *data)
{

	int rtn = 0;
	int key = EntKey_Perst_GetNewKeys(SALE_KEY_NAME,1);
	if(key <= 0)     return 0;
	data->id = key;
	FILE *fp = fopen(SALE_DATA_FILE,"ab");

	if(NULL == fp)
	{
		printf( "cannot open file %s!!\n",SALE_DATA_FILE);
		return 0;
	}

	rtn = fwrite(data,sizeof(sale_t),1,fp);

	fclose(fp);

	return rtn;

}

