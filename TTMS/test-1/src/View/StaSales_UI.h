#ifndef STASALES_UI_H_
#define STASALES_UI_H_

#include "../Common/List.h"
//#include "../Service/Sale.h"
#include "../Service/Account.h"

static const int STASALES_PAGE_SIZE=6;

//统计销售额界面
void StaSales_UI_MgtEntry ();

//统计个人销售额界面
void StaSales_UI_Self();

//统计售票员销售额界面
void StaSales_UI_Clerk();

#endif /* STASALES_UI_H_ */
