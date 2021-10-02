#include <stdio.h>
//int a[]={0}
//int* p=a
//p[i]=a[i]
//但是!!!!指针和数组不是一回事
//数组名并不是常量指针
int main()
{
    //int a[] = {1, 2, 3, 4, 5};(ext.c中)
    
    //extern  int* a;这里访问的空间已经越界 0x200000001
    extern  int a[];//如果是*a就不可 这就说明a[]并不是等于*a的
    
    printf("&a = %p\n", &a);
    printf("a = %p\n", a);
    printf("*a = %d\n", *a);
    return 0;
}
/*
&a = 0x562f51e9d010
a = 0x200000001
段错误 (核心已转储)
*/
