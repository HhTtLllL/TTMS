#include"Ticket.h"
#include"../Common/list.h"
#include"Seat.h"
#include<stdlib.h>
#include"../Service/Schedule.h"
#include"../Persistence/Ticket_Persist.h"
#include<assert.h>

void Ticket_Srv_GenBatch(int schedule_id)
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
	return Tick_Perst_Rem(schedule_id);
}
