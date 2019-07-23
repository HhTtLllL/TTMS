/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: EntityKey_Persit.h			  
* Description :  主键服务头文件
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015年4月22日	
*/

#ifndef COMMON_PERSIST_H_
#define COMMON_PERSIST_H_


/*
标识符：TTMS_SCU_EntKey_Perst_GetNewKeys
功能：根据传入的实体名entName及实体个数count，为这个count个新实体分配一个长度为count的主键值区间，
     使得每个新实体在该区间内都可以分配到 唯一的 主键。返回值为该主键区间的最小值
*/
long EntKey_Perst_GetNewKeys(const char entName[], int count);

#endif /* COMMON_PERSIST_H_ */
