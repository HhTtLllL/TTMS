/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: EntityKey_Persit.h			  
* Description :  ��������ͷ�ļ�
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef COMMON_PERSIST_H_
#define COMMON_PERSIST_H_


/*
��ʶ����TTMS_SCU_EntKey_Perst_GetNewKeys
���ܣ����ݴ����ʵ����entName��ʵ�����count��Ϊ���count����ʵ�����һ������Ϊcount������ֵ���䣬
     ʹ��ÿ����ʵ���ڸ������ڶ����Է��䵽 Ψһ�� ����������ֵΪ�������������Сֵ
*/
long EntKey_Perst_GetNewKeys(const char entName[], int count);

#endif /* COMMON_PERSIST_H_ */
