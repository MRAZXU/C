#include <stdio.h>
#include <malloc.h>
//声明和定义的不同
//定义必定内存分配，而申明没有
extern int g_var;//进行申明
extern struct Test;

int main()
{
    extern void f(int i, int j);
    extern int g(int x);
    //如果struct Test* p =(struct Test*)malloc(sizeof(struct Test));
    //但是找不到TEST的定义，拿不到具体内存大小这里只是申明
    struct Test* p =NULL;// (struct Test*)malloc(sizeof(struct Test));
    
    printf("p = %p\n", p);
    
    //g_var = 10;
    
    printf("g_var = %d\n", g_var);
    f(1, 2);
    printf("g(3) = %d\n", g(3));
    
    free(p);
    return 0;
}
