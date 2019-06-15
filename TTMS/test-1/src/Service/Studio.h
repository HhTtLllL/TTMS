/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* ������ţ�TTMS_UC_01	
* File name: Studio_c		  
* Description : �ݳ�������ҵ���߼���ͷ�ļ�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef STUDIO_H_
#define STUDIO_H_

//�ݳ������ݽṹ 
typedef struct {
	int id;			//��ӳ��ID
	char name[30];	//��ӳ������
	int rowsCount;	//��λ����
	int colsCount;	//��λ����
	int seatsCount;
} studio_t;

//˫������
typedef struct studio_node {
	studio_t data;				//ʵ������
	struct studio_node *next;	//����ָ��
	struct studio_node *prev;	//ǰ��ָ��
} studio_node_t, *studio_list_t;

//��ʶ����TTMS_SCU_Studio_Srv_Add 
//���ܣ�������ݳ�������
int Studio_Srv_Add(studio_t *data);

//��ʶ����TTMS_SCU_Studio_ Srv _Mod 
//���ܣ��޸��ݳ�������
int Studio_Srv_Modify(const studio_t *data);

//��ʶ����TTMS_SCU_Studio_Srv_DelByID 
//���ܣ�����IDɾ���ݳ�������
int Studio_Srv_DeleteByID(int ID);

//��ʶ����TTMS_SCU_Studio_Srv_FetchByID
//���ܣ�����ID��ȡ��Ӧ�ݳ��� 
int Studio_Srv_FetchByID(int ID, studio_t *buf);

//��ʶ����TTMS_SCU_Studio_Srv_FetchAll
//���ܣ���ȡȫ���ݳ�������
int Studio_Srv_FetchAll(studio_list_t list);

//��ʶ����TTMS_SCU_Studio_Srv_FindByID
//���ܣ�����ID�������л�ȡ��Ӧ�ݳ������
studio_node_t *Studio_Srv_FindByID(studio_list_t list, int ID);

#endif //STUDIO_H_
