#include <stdio.h>
//链接器
//静态链接-------把所有文件全部打包都在.out中
//在linux中创立静态库-->lib.a
//STEP1.编译静态库源码：gcc -c lib.c -o lib.o
//STEP2.生成静态文件：ar -q lib.a lib.o
//STEP3.使用静态库编译：gcc main.c lib.a -o main.out
extern char* name();
extern int add(int a, int b);

int main()
{
    printf("Name: %s\n", name());
    printf("Result: %d\n", add(2, 3));

    return 0;
}
