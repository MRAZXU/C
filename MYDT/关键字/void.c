#include <stdio.h>
//不能定义void类型的变量 但可以定义void类型的指针，而且这种指针很常用
//void抽象数据类型，有的编译器定义了大小，有的没有
//void*
//左值：接受任意类型指针
//右值：使用时需要强制类型转换
void MemSet(void* src, int length, unsigned char n)
{
    unsigned char* p = (unsigned char*)src;
    int i = 0;
    for(i=0; i<length; i++)
    {
        p[i] = n;
    }
}

int main()
{
    int a[5];
    int i = 0;
    
    MemSet(a, sizeof(a), 0);
    
    for(i=0; i<5; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}