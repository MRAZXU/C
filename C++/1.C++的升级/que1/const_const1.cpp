#include <stdio.h>
//const在修饰变量为只读属性以外，在C++中还可以作为"常量"
//那么什么时候为只读变量，什么时候为常量？
//只有用字面量初始化的const常量才能进入符号表,变为真正意义上的常量
//使用其他变量初始化的，被volatile修饰的都只能是只读变量
int main()
{
    //const与引用
    const int x = 1;//！！！！！！！！！！！！！！！！只有这里变成了常量！！！！！！！！！
    const int& rx = x;//只读
    int& nrx = const_cast<int&>(rx);//只读
    nrx = 5;
    printf("x = %d\n", x);//1 进入了符号表 变成了常量
    printf("rx = %d\n", rx);//5
    printf("nrx = %d\n", nrx);//5
    //这个空间只有指针和引用可以用
    printf("&x = %p\n", &x);//0x7ffd150004c0
    printf("&rx = %p\n", &rx);//0x7ffd150004c0
    printf("&nrx = %p\n", &nrx);//0x7ffd150004c0
    
    volatile const int y = 2;//只读，没有进入符号表
    int* p = const_cast<int*>(&y);
    *p = 6;
    printf("y = %d\n", y);//6
    printf("p = %p\n", p);//0x7ffd150004c4
    
    const int z = y;//只读，没有进入
    p = const_cast<int*>(&z);
    *p = 7;
    printf("z = %d\n", z);//7
    printf("p = %p\n", p);//0x7ffd150004c8
    
    char c = 'c';//连只读属性都没有
    char& rc = c;
    //当引用类型与初始化变量类型不同时，就定义一个新的变量
    const int& trc = c;//有且只有这种情况下const把字面量修饰成了常量(其实就是进入了符号表)
    rc = 'a';
    int*pc=const_cast<int*>(&trc);
    *pc=5;
    printf("c = %c\n", c);//a
    printf("rc = %c\n", rc);//a
    printf("trc = %d\n", trc);//c
    
    return 0;
}