int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list)
{
	int cnt = 0;
	assert(NULL!=list);
	play_list_t playlist;
	play_node_t *pos;
	int sold;//存储已售有效票数
	salesanalysis_list_t p;
	List_Free(list,salesanalysis_node_t);
	List_Init(playlist,play_node_t);
	Play_Srv_FetchAll(playlist);
	List_ForEach(playlist,pos)
	{
		p  =   (salesanalysis_list_t)malloc(sizeof(salesanalysis_node_t));
		strcpy(p->data.area,pos->data.area);
		p->data.duration = pos->data.duration;
		p->data.end_date = pos->data.end_date;
		strcpy(p->data.name,pos->data.name);
		p->data.play_id = pos->data.id;
		p->data.price = pos->data.price;
		p->data.start_date = pos->data.start_date;
		
		p->data.sales = Schedule_Srv_StatRevByPlay(pos->data.id,&sold);//票房
		p->data.totaltickets = sold;//上座

		List_AddTail(list,p);
		// printf("剧目id :%d\n",pos->data.id);
	}
	return cnt;

}
