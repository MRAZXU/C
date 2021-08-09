#include <stdio.h>
#include <stdarg.h>
//酷炫技能函数可变参数
/**********************！！！面试题！！！*******************/
//如何编写一个计算n个平均值的函数
//参数
//va_list  参数集合
//va_arg    去具体的值如果指定了错误的类型，将结果不可测
//va_start  标识参数访问的开始
//va_end    标识参数访问的结束
//前提
//1.必须从头到尾巴逐个访问
//2.参数至少存在一个确定的命名的参数
//3.可变参数函数无法确定
//4.
//应用实例库函数里面的printf函数
float average(int n, ...)//这个...为占位符
{
    va_list args;
    int i = 0;
    float sum = 0;   
    va_start(args, n); 
    for(i=0; i<n; i++)
    {
        sum += va_arg(args, int);
    }   
    va_end(args);   
    return sum / n;
}
int main()
{
    printf("%f\n", average(5, 1, 2, 3, 4, 5));
    printf("%f\n", average(4, 1, 2, 3, 4));
    return 0;
}
