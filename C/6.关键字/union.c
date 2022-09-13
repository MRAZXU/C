#include <stdio.h>
/**********************************************/
//判断大小端
//利用union共享空间的性质
int system_mode()
{
    union SM
    {
        int i;
        char c;
    };
    union SM sm;

    sm.i = 1;
    return sm.c;
}


int main()
{
    //如果是1--->为小端
    //小端：低地址存低位
    //大端：高地址存低位
    printf("System Mode: %d\n", system_mode());
    return 0;
}