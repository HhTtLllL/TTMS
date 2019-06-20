#ifndef SALE_PERSIST_H_
#define SALE_PERSIST_H_
#include"../Service/Sale.h"
int Sale_Perst_Insert( sale_t *data);


int Ticket_Perst_Update(const ticket_t *data);

int Ticket_Srv_SelBySchID(int id,ticket_list_t list);

#endif
