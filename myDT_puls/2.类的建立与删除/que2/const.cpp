#include <stdio.h>
//const 能否修饰对象？
//能-----只读对象
//const成员函数
//只能调用，不能直接改写
class Test
{
    int mi;
public:
    Test(int i) ;
    Test(const Test& t);
    int getMi();
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
}
    
int Test::getMi()
{
    return mi;
}
int main()
{
    //const修饰类的对象 
    Test t(1);//error
    return 0;
}