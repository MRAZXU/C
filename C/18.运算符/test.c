#include <stdio.h>
#include <assert.h>
/*******************面试题！！！！*****************************/
//一行代码实现字符串长度
int str_len(const char* s)
{  
    //assert函数　assert的作用是先计算表达式 expression ，
    //如果其值为假（即为0）打印一条出错信息，然后通过调用 abort 来终止程序运行。
    //return s, (*s ? str_len(s + 1) + 1 : 0);
    return assert(s), (*s ? str_len(s + 1) + 1 : 0);//用assert对NULL报错
}
//缺点是s不能为NULL
int main()
{   
    printf("len = %d\n", str_len("Delphi"));
    //printf("len = %d\n", strlen(NULL));//error

    return 0;
}
