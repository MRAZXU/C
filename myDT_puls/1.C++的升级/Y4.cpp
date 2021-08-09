#include <stdio.h>
//引用有时候也很难避开内存错误
//比如函数返回的引用
int& demo()
{
    static int d = 0;
    // int d = 0;这里包括C语言一样指出
    //函数的局部变量不能作为返回值！
    //所有以常量指针为本质的引用自然避免不了这类内存错误
    printf("demo: d = %d\n", d);
    return d;
}

int& func()
{
    static int s = 0;
    printf("func: s = %d\n", s);
    return s;
}

int main(int argc, char* argv[])
{
    int& rd = demo();
    int& rs = func();
    
    printf("\n");
    printf("main: rd = %d\n", rd);
    printf("main: rs = %d\n", rs);
    printf("\n");
    
    rd = 10;
    rs = 11;
    
    demo();//10
    func();//11
    
    printf("\n");
    printf("main: rd = %d\n", rd);//10
    printf("main: rs = %d\n", rs);//11
    printf("\n");
    
    return 0;
}