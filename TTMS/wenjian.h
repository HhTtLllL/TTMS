#include<stdio.h>

typedef struct     //定义学生结构体                                                                                                                                                                           
{
        long ID; 
        char num[10];
        char name[30];
}student_t;



const char *file_student = "student.dat";   //学生文件名
const char *file_course = "course.dat";//课程文件名
const char *file_key = "key.dat";    //主键文件名

const char *file_scorse = "scorse.dat";   //成绩文件名
long GetNewkey(const char *entName);     //为业务数据分配主键
void Student_InitFile(void);     //初始化学生数据文件
void Course_InitFile(void);     //初始化课程数据文件

