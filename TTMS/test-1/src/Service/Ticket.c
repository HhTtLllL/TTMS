#include"Ticket.h"
#include"../Common/list.h"
#include"Seat.h"
#include<stdlib.h>
#include"../Service/Schedule.h"
#include"../Persistence/Ticket_Persist.h"
#include<assert.h>
#include"Ticket.h"	

int  Ticket_Srv_GenBatch(int schedule_id)
{
	int count = 0;
	seat_list_t seat_head;

	List_Init(seat_head,seat_node_t);

	schedule_t buf;
	
	Schedule_Srv_FetchByID_ticket(schedule_id,&buf);
	count = Seat_Srv_FetchValidByRoomID(seat_head,buf.studio_id);
	Ticket_Perst_Insert(seat_head,schedule_id);

	return count;

}

void Ticket_Srv_deleteBatch(int schedule_id)
{
	return Ticket_Perst_Rem(schedule_id);
}

int Ticket_Srv_FetchAll(ticket_list_t list)
{
	return Ticket_Perst_SelectAll(list);
}

int Ticket_Srv_FetchByticketID(int ticket_id,ticket_t *buf)
{
	return Ticket_Perst_SelByticketID(ticket_id,buf);
}
int Ticket_Srv_FetchByID(int id,ticket_t *buf)      //gen ju  seat ID   get ticket
{
        return Ticket_Perst_SelByID(id,buf);
}

int Ticket_Srv_Modify(const ticket_t *data)
{
	return Ticket_Perst_Update(data);
}
