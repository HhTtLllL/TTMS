#include"wenjian.h"


void Student_InitFile(void)
{
	student_t stu_data[] = {{0,"001","stu_1"},{0,"002","stu_2"},{0,"003","stu_3"}};

	FILE *fp_stu = fopen(file_student,"wb");
	if(!fp_stu)
	{
		printf( "open file \" %s \" for write failed!\n",file_student);
		return ;
	}

	for(int i = 0;i < 3;i++)   stu_data[i].ID = GetNewkey("student");       
	fwrite(stu_data,sizeof(student_t),3,fp_stu);      //保存到学生文件中   
	fclose(fp_stu);
}

long GetNewkey(const char *entName)
{
	entity_key_t ent;
	FILE *fp;
	int found = 0;
	long newEntKey = 1;
	if(access(file_key,0))     //判断文件是否存在
	{
		if(!(fp = fopen(file_key,"wb+")));     //新建文件
		return 0;
	}
	else
	{
		if(!(fp = fopen(file_key,"rb+")));    //以读写更新模式打开
		return 0;
	}


	while(1)
	{
		if(fread(&ent,sizeof(entity_key_t),1,fp) < 1)    //读入每个主键记录
			break;
		if(0 == strcmp(ent.name,entName))   //配备业务数据名
		{
			fseek(fp,-((int)sizeof(entity_key_t), SEEK_CUR));
			ent.key++;     //主键值+1
			newEntKey = net.key;
			fwrite(&ent,sizeof(entity_key_t),1,fp);   //写入最新主键 值
			found = 1;
			break;
		}
	}

	if(!found)    //未找到业务数据的主键记录,将新家主键记录到文件末尾
	{
		strcpy(ent.name,entName);
		ent.key = 1;
		fwrite(&ent,sizeof(entity_key_t),1,fp);
	}

	fclose(fp);
	return newEntKey;
}

void Course_InitFile(void)
{
	course_t cour_data[] = {{0,"C Language",4},{0,"Advanced Mathematics",6}};
	FILE *fp_stu = fopen(file_scorse,"wb");    

	if(!fp_stu)
	{
		printf( "Open file \" %s \" for write failed!\n",file_scorse);
		return ;
	}

	for(int i = 0;i < 2;i++)	stu_data[i].ID = GetNewkey("score");     //使用 score 分配主键

	fwrite(stu_data,sizeof(score_t),2,fp_stu);
	fclose(fp_stu);
}

void Student_PrintAll(void)
{
	student_t stu_tmp;

	FILE * fp = fopen(file_student,"rb");
	if(!fp)
	{
		printf( "Open file \" %s \" for read failed!\n",file_student);
		return ;
	}

	printf( "\nData records in the file of students: \n");
	while(1)
	{
		if(fread(&stu_tmp,sizeof(student_t),1,fp) < 1)
			break;
		printf( "id: %ld,  num:%s,  name:%s\n",stu_tmp.ID,stu_tmp.num,stu_tmp.name);
	}

	fclose(fp);
}

void 
