#include <stdio.h>
//去除友元
class Complex 
{
    int a;
    int b;
public:
    Complex(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    
    int getA()
    {
        return a;
    }
    
    int getB()
    {
        return b;
    }
    //将操作重载函数定义为类成员函数
    //这样就不需要外界函数访问，就不要友元了
    //this指针不要忘
    //!!!!编译器优先在成员函数中寻找操作符的重载函数
    Complex operator + (const Complex& p)
    {
        Complex ret;
        printf("Complex operator + (const Complex& p)\n");
        ret.a = this->a + p.a;
        ret.b = this->b + p.b;
        
        return ret;
    }
    
    //friend Complex operator + (const Complex& p1, const Complex& p2);
};
/*
Complex operator + (const Complex& p1, const Complex& p2)
{
    Complex ret;
    printf("Complex operator + (const Complex& p1, const Complex& p2)\n");
    ret.a = p1.a + p2.a;
    ret.b = p1.b + p2.b;
    
    return ret;
}
*/
int main()
{

    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2; // c1.operator + (c2)
    
    printf("c3.a = %d, c3.b = %d\n", c3.getA(), c3.getB());
    
    return 0;
}