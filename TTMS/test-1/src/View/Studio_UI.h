/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_01		 
* File name: Studio_UI.h			  
* Description : �ݳ������������ͷ�ļ�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef STUDIO_UI_H_
#define STUDIO_UI_H_

//��ʶ����TTMS_SCU_Studio_UI_Add 
//���ܣ��������ݳ�������
int Studio_UI_Add(void);

//��ʶ����TTMS_SCU_Studio_UI_Mod
//���ܣ�����ID�޸��ݳ�������
int Studio_UI_Modify(int id);


//��ʶ����TTMS_SCU_Studio_UI_Del
//���ܣ�����IDɾ���ݳ������� 
int Studio_UI_Delete(int id);

//��ʶ����TTMS_SCU_Studio_UI_MgtEnt  
//���ܣ�����IDɾ���ݳ������� 
void Studio_UI_MgtEntry(void);

#endif /* STUDIO_UI_H_ */
