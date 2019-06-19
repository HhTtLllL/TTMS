/*#include "StaSales.h"
#include "../Common/List.h"
#include "../Common/common.h"
#include "../Persistence/Sale_Persist.h"
#include "../Persistence/Account_Persist.h"

//根据ID获取销售额统计
int StaSales_Srv_CompSaleVal(int usrID, ttms_date_t stDate, ttms_date_t endDate){
	int amount = 0;
	sale_list_t saleList;
	sale_node_t pSale;
	List_Init(saleList,sale_node_t);
	Sale_Persat_SelectByUsrID();
	List_ForEach(saleList,pSale)
	{
		amount+=pSale->data.value;
	}
	return amount;
}
*/