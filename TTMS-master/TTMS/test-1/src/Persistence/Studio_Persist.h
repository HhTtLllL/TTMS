/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_01	 
* File name: Studio_Persist.h			  
* Description : �ݳ��������־û���ͷ�ļ�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef STUDIO_PERSIST_H_
#define STUDIO_PERSIST_H_

#include "../Service/Studio.h"

//��ʶ����TTMS_SCU_Studio_Perst_Insert 
//���ܣ����ļ��д洢���ݳ��� 
int Studio_Perst_Insert(studio_t *data);	 

//��ʶ����TTMS_SCU_Studio_ Perst_Update 
//���ܣ����ļ��и����ݳ���
int Studio_Perst_Update(const studio_t *data);

//��ʶ����TTMS_SCU_Studio_Perst_DeleteByID
//���ܣ����ļ���ɾ���ݳ���
int Studio_Perst_DeleteByID(int ID);

//��ʶ����TTMS_SCU_Studio_Perst_SelectByID 
//���ܣ�����ID���ļ��������ݳ���
int Studio_Perst_SelectByID(int ID, studio_t *buf);

//��ʶ����TTMS_SCU_Studio_Perst_SelAll 
//���ܣ����ļ�������ȫ���ݳ���
int Studio_Perst_SelectAll(studio_list_t list);


#endif /* STUDIO_PERSIST_H_ */
