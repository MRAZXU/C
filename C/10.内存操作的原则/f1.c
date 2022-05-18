#include <stdio.h>
#include <malloc.h>
//常见的内存错误
//1.结构体成员指针未初始化
//2.结构体成员指针未分配足够的内存
//3.内存分配成功，但是未初始化
//4.内存操作越界
void test(int* p, int size)
{
    int i = 0;
    for(i=0; i<size; i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);
}
void func(unsigned int size)
{
    //如果是奇数内存空间就释放不了
    int* p = (int*)malloc(size * sizeof(int));
    int i = 0;
    if( size % 2 != 0 )
    {
        return; 
    }
    for(i=0; i<size; i++)
    {
        p[i] = i;
        printf("%d\n", p[i]);
    }
    free(p);
}
int main()
{
    int* p = (int*)malloc(5 * sizeof(int));
    test(p, 5);
    //重复释放指针
    free(p); 
    func(9);
    func(10);
    return 0;
}