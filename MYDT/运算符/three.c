#include <stdio.h>
//三目运算符只能为右值
//(a < b ? a : b) = 3;error
int main()
{   
    char c = 0;//1
    short s = 0;//2
    int i = 0;//4
    double d = 0;//8
    char* p = "str";//8
  //三目运算符含有隐式转换，返回后两项较大空间的类型      
    printf( "1_%ld\n", sizeof(c ? c : s) );//返回为int!!! 4 见笔记中C语言隐式转换类型顺序
    printf( "2_%ld\n", sizeof(i ? i : d) );//8
    //三目运算符返回的必须是一个值
    //printf( "3%ld\n", sizeof(d ? d : p) );//error
    printf( "4_%ld\n", sizeof(d ? d : (*p) ));//8 

    return 0;
}