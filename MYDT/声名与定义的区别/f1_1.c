#include <stdio.h>

int g_var = 10;
//float g_var = 10;
//这时f1.c中出现浮点数被整型数解释
struct Test
{
    int x;
    int y;
};

void f(int i, int j)
{
    printf("i + j = %d\n", i + j);
}

int g(int x)
{
    return (int)(2 * x + g_var);
}