#include <stdio.h>
//函数的数组参数经过编译退化为了指针
//C语言里不存在数组参数
void func1(char a[5])
{
    printf("In func1: sizeof(a) = %ld\n", sizeof(a));
    *a = 'a';
    a = NULL;//数组名为右值 不可能被通过
}

void func2(char b[])
{
    printf("In func2: sizeof(b) = %ld\n", sizeof(b));
    *b = 'b';
    b = NULL;
}

int main()
{
    char array[10] = {0};
    func1(array);
    printf("array[0] = %c\n", array[0]);
    func2(array);
    printf("array[0] = %c\n", array[0]);
    return 0;
}