#include <stdio.h>
//非零为true 零为false
//占用一个字节
int main(int argc, char *argv[])
{
    bool b = false;
    int a = b;
    printf("sizeof(b) = %d\n", sizeof(b));
    printf("b = %d, a = %d\n", b, a);
    b = 3;
    a = b;
    printf("b = %d, a = %d\n", b, a);
    b = -5;
    a = b;
    printf("b = %d, a = %d\n", b, a);
    a = 10;
    b = a;
    printf("a = %d, b = %d\n", a, b);
    a = 0;
    b = a;
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
//C++中三目运算可以作为左值，对最后的结果赋值