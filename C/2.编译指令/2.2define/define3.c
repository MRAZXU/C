#include <stdio.h>
//宏定义的范围：没有作用域的限制
//作用域只针对函数和变量
void def()
{
    #define PI 3.1415926
    #define AREA(r) r * r * PI
}

double area(double r)
{
    return AREA(r);
}

int main()
{
    double r = area(5);
    printf("PI = %f\n", PI);
    printf("d = 5; a = %f\n", r);
    return 0;
}