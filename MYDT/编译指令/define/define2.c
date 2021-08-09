#include <stdio.h>
//宏表达式
/**********************面试重点！！！***********************************/

#define _SUM_(a, b) (a) + (b)
#define _MIN_(a, b) ((a) < (b) ? (a) : (b))
//有些计算只有利用宏表达式才能做到最简
//比函数更加强大，没有调用开销。但是跳过预编译也使得它更容易出错
#define _DIM_(a) sizeof(a)/sizeof(*a)
int main()
{
    int a = 1;
    int b = 2;
    int c[4] = {0};

    int s1 = _SUM_(a, b);//3
    //但是宏表达式也经常出现错误
    int s2 = _SUM_(a, b) * _SUM_(a, b);//5
    int m = _MIN_(a++, b);//2
    int d = _DIM_(c);//4
    //中间结果.i文件为:
/*
    int s1 = (a) + (b);
    int s2 = (a) + (b) * (a) + (b);
    int m = ((a++) < (b) ? (a++) : (b));
    int d = sizeof(c)/sizeof(*c);
*/
    printf("s1 = %d\n", s1);
    printf("s2 = %d\n", s2);
    printf("m = %d\n", m);
    printf("d = %d\n", d);
    return 0;
}
