#include"Sale.h"
#include"../Persistence/Sale_Persist.h"


int Sale_Srv_Add(const sale_t *data)
{
	return Sale_Perst_Insert(data);
}

