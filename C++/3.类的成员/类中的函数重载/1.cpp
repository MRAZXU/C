#include <stdio.h>
/*****************************************/
void func()
{
    printf("void func()\n");
}
void func(int i)
{
    printf("void func(int i), i = %d\n", i);
}
/*****************************************/
class Test
{
    int i;
public:
/***********************构造函数****************************/
//重载
    Test()
    {
        printf("Test::Test()\n");
        this->i = 0;
    }
    Test(int i)
    {
        printf("Test::Test(int i)\n");
        this->i = i;
    }
    Test(const Test& obj)//拷贝构造函数
    {
        printf("Test(const Test& obj)\n");
        this->i = obj.i;
    }
    /********************构造函数**************************/
    /********************静态成员函数**************************/
    static void func()
    {
        printf("void Test::func()\n");
    }
    
    void func(int i)
    {
        printf("void Test::func(int i), i = %d\n", i);
    }
      /********************静态成员函数**************************/
    int getI()
    {
        return i;
    }
};
int main()
{
    func();
    func(1);
    
    Test t;        // Test::Test()
    Test t1(1);    // Test::Test(int i)
    Test t2(t1);   // Test(const Test& obj)
    
    func();        // void func()
    Test::func();  // void Test::func()
    func(2);       // void func(int i), i = 2;
    //这里不会冲突的原因是全局函数和静态成员函数的作用域不相同
    //不会构成重载的关系
    t1.func(2);    // void Test::func(int i), i = 2 通过类名调用，静态成员函数
    t1.func();     // void Test::func()
    

    return 0;
}