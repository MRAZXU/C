#include <stdio.h>
//比C更为细致的类型转换
//C的类型转换1.强制类型转换2.隐式类型转换
//缺点：过于粗暴任意类型之间都可以转换；难于定位，编译器很难定位强制类型转换的位置
//C++中更为安全的类型转化出现！
typedef void(PF)(int);

struct Point
{
    int x;
    int y;
};

//基于基本类型之间的转换
//可用于具有继承关系类对象之间的转换和类指正之间的转换
//不能用于基本类型指针之间的转换
void static_cast_demo()
{
    int i = 0x12345;
    char c = 'c';
    int* pi = &i;
    char* pc = &c;
    c = static_cast<char>(i);
   // pc = static_cast<char*>(pi);//不允许！
}
//用于除去变量的只读属性
//强制类型转换的目标必须是指针或者引用
void const_cast_demo()
{
    const int& j = 1;
    int& k = const_cast<int&>(j);
    const int x = 2;
    int& y = const_cast<int&>(x);
    //int z = const_cast<int>(x);//不允许！
    k = 5;
    printf("k = %d\n", k);
    printf("j = %d\n", j);
    y = 8;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);
}
//用于指针类型之间的转换
//用于整数与指针类型之间的转换
void reinterpret_cast_demo()
{
    int i = 0;
    char c = 'c';
    int* pi = &i;
    char* pc = &c;
    
    pc = reinterpret_cast<char*>(pi);
    pi = reinterpret_cast<int*>(pc);
    pi = reinterpret_cast<int*>(i);
    //c = reinterpret_cast<char>(i); //不允许!
}
//用于继承关系的类指针之间的转换
//用于交叉关系的类指针之间的转换
//需要虚函数的支持
void dynamic_cast_demo()
{
    int i = 0;
    int* pi = &i;
    //char* pc = dynamic_cast<char*>(pi);//不允许！
}
int main()
{  
     /************************粗暴的强制类型转换*****************
    /*int v = 0x12345;
    //乱七八糟
    PF* pf = (PF*)v;//整型变量转指针变量  莫民奇妙 入口是多少都不知道
    char c = char(v);//整型转字符发生了截断
    Point* p = (Point*)v;//整型变量转结构体指针
    pf(5);
    printf("p->x = %d\n", p->x);
    printf("p->y = %d\n", p->y);
    
    //最后可以编译通过
  ********************新的类型转换*********************************/
//四种类型的强制类型转换
    static_cast_demo();
    const_cast_demo();
    reinterpret_cast_demo();
    dynamic_cast_demo();
    return 0;
}
