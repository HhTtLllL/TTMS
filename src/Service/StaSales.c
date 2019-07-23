#include "StaSales.h"
#include "../Common/list.h"
#include "../Common/common.h"
#include "../Persistence/Sale_Persist.h"
#include "../Persistence/Account_Persist.h"

//根据ID获取销售额统计
int StaSales_Srv_CompSaleVal(int usrID, ttms_date_t stDate, ttms_date_t endDate){
	int amount = 0;
	sale_list_t saleList;
	sale_node_t *pSale;
	List_Init(saleList,sale_node_t);
	Sale_Perst_SelByID(saleList,usrID);
	List_ForEach(saleList,pSale)
	{
		if(pSale->data.date.day<=endDate.day&&pSale->data.date.day>=stDate.day&&
		pSale->data.date.year<=endDate.year&&pSale->data.date.year>=stDate.year&&
		pSale->data.date.month<=endDate.month&&pSale->data.date.month>=stDate.month
		){
			amount += pSale->data.value;
		}
	}
	return amount;
}