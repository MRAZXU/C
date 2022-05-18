#include <stdio.h>
//extern任何文件
//static只能只能本文件
extern int getI();
int main()
{
    printf("%d\n", getI());
       
    return 0;
}