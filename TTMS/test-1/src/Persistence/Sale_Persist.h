#ifndef SALE_PERSIST_H_
#define SALE_PERSIST_H_
#include"../Service/Sale.h"
int Sale_Perst_Insert( sale_t *data);


int Ticket_Perst_Update(const ticket_t *data);

int Ticket_Srv_SelBySchID(int id,ticket_list_t list);

int Sale_Perst_SelByTicketID (int ticket_id, sale_t *sale);

int Sale_Perst_SelByID (sale_list_t list, int usrID);

#endif
