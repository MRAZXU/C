#include <stdio.h>
//struct占用多大内存？
//gcc:为0
//bcc:不允许出现
//vc:不允许
struct TS
{
};

int main()
{
    struct TS t1;
    struct TS t2;
    
    printf("sizeof(struct TS) = %d\n", sizeof(struct TS));
    printf("sizeof(t1) = %d, &t1 = %p\n", sizeof(t1), &t1);
    printf("sizeof(t2) = %d, &t2 = %p\n", sizeof(t2), &t2);
    
    return 0;
}