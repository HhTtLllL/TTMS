#ifndef PLAY_UI_H_
#define PLAY_UI_H_

#include"../Service/Play.h"
int Play_UI_Add(void);

int Play_UI_Modify(int id);

int Play_UI_Delete(int id);

void Play_UI_MgtEntry(void);

int Play_UI_Query(int id);

int Schedule_UI_MgtEntry(int play_id);

int  Play_UI_screen();

#endif
