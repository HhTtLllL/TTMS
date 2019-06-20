#ifndef SALE_UI_H_
#define SALE_UI_H_
#include"../Service/Seat.h"
#include"../Service/Ticket.h"
void Sale_UI_MgtEntry(void);

void Sale_UI_ShowScheduler(int playID);

int Sale_UI_SellTicket(ticket_list_t ticketList,seat_list_t seatList);

int Sale_UI_ShowTicket();



//标识符:TTMS_SCU_Sale_UI_RetfundTicket
//用于实现退票
void Sale_UI_ReturnTicket();
#endif

