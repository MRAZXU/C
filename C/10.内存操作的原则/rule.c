#include <stdio.h>
#include<malloc.h>
//内存操作的一些规则
//1.动态内存申请后，应立即检查指针值是否为NULL，防止使用空指针
int* p =(int*)malloc(56)
if (p!=NULL)
{

}
free(p);
//2.free指针之后必须立即赋值为NULL
int* p=(int*)malloc(20);
free(p);
p=NULL;
//
//
//
if (p!=NULL)
{
}
//3.任何与内存操作相关的函数都必须带长度信息
void print(int*p,int size)
{
    int i=0;
    char buf[128]={0};
    snprintf(buf,sizeof(buf),"%s","MYRULE");
    for(i=0;i<size;i++)
    {
        printf("%d\n"p[i]);
    }
}
//4.malloc与free必须一一对应的匹配
