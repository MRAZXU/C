#include <stdio.h>

int main()
{
    int a[5] = {0};
    int* p = a;
    int i = 0;
    
    for(i=0; i<5; i++)
    {
        p[i] = i + 1;
    }
    for(i=0; i<5; i++)
    {
        //以指针的形式访问数组
        printf("a[%d] = %d\n", i, *(a + i));
    }
    printf("\n");

    for(i=0; i<5; i++)
    {
        i[a] = i + 10;
    }
    for(i=0; i<5; i++)
    {
        //数组名可以看作常量指针使用
        //指针也可当作数组名使用    但不是一个概念
        printf("p[%d] = %d\n", i, p[i]);
        printf("p[%d] = %d\n", i, i[p]);
        //p[i]=*(p+i)=*(i+p)=i[p]
    }
    return 0;
}
