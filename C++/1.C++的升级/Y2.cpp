#include <stdio.h>
//const修饰&引用
void Example()
{
    printf("Example:\n");
    int a = 4;
    //赋予变量只读属性
    const int& b = a;

    int* p = (int*)&b;
    //b = 5;//error 因为这时的b为只读变量
    *p = 5;
    printf("a = %d\n", a);//5
    printf("b = %d\n", b);//5
}

void Demo()
{
    printf("Demo:\n");
    //使用常量对const引用初始化
    const int& c = 1;//产生一个只读变量

    int* p = (int*)&c;
    //c = 5;
    *p = 5;
    printf("c = %d\n", c);//5
}

int main(int argc, char *argv[])
{
    Example();
    printf("\n");
    Demo();
    return 0;
}