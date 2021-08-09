#include <iostream>
#include <string>
/***************笔试题***************************/
//统计某个成员变量的访问次数
//得分点在针对const成员函数
//mutable修饰的变量将处于可变状态
//但是平时不能用
using namespace std;

class Test
{
    int m_value;
    int * const m_pCount;//设定为常量指针
    /* mutable int m_count; */
public:
    Test(int value = 0) : m_pCount(new int(0))//初始化
    {
        m_value = value;
        /* m_count = 0; */
    }
    
    int getValue() const
    {
        /* m_count++; */
        *m_pCount = *m_pCount + 1;//
        return m_value;
    }
    
    void setValue(int value)
    {
        /* m_count++; */
        *m_pCount = *m_pCount + 1;
        m_value = value;
    }
    
    int getCount() const
    {
        /* return m_count; */
        return *m_pCount;
    }

    ~Test()
    {
        delete m_pCount;
    }
};

int main(int argc, char *argv[])
{
    Test t;
    
    t.setValue(100);
    
    cout << "t.m_value = " << t.getValue() << endl;
    cout << "t.m_count = " << t.getCount() << endl;
    //对于只读对象
    const Test ct(200);
    
    cout << "ct.m_value = " << ct.getValue() << endl;
    cout << "ct.m_count = " << ct.getCount() << endl;
    
    return 0;
}