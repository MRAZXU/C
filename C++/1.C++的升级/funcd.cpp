#include <stdio.h>
//函数参数的默认值，这样的表达是C中不允许的，但是C++可以
int mul(int x = 0);
//参数的默认值必须从右往左提供（调用是从左往右）
int add(int x, int y = 1, int z = 2);
int main(int argc, char *argv[])
{
    printf("%d\n", mul());//这里就使用了声明中的默认值
    printf("%d\n", mul(-1));//1
    printf("%d\n", mul(2));//4
    
    printf("%d\n", add(0));//3
    printf("%d\n", add(2, 3));//7
    printf("%d\n", add(3, 2, 1));//6
    
    return 0;
}

//int mul(int x=5) 参数的默认值必须在声明中指定
int mul(int x)
{
    return x * x;
}

int add(int x, int y, int z)
{
    return x + y + z;
}