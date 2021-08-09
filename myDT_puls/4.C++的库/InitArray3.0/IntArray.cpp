#include "IntArray.h"
//尘归尘，土归土
/*IntArray::IntArray(int len)
{
    m_pointer = new int[len];//如果申请不成功 m_pointer=NULL
    //避免的方案就是二阶构造
    for(int i=0; i<len; i++)
    {
        m_pointer[i] = 0;
    }
    m_length = len;
}
void IntArray::free()
{
    delete[]m_pointer;
}*/

/***************************用二阶构造进行替代*************************************/
//1.第一阶段：资源无关的初始操作
IntArray::IntArray(int len)
{
    m_length = len;
}
//2.第二阶段：系统资源操作(使用资源)（成功-->返回对象 失败-->删除半成品对象 返回NULL）
bool IntArray::construct()
{
    bool ret = true;
    m_pointer = new int[m_length];
    if( m_pointer )
    {
        for(int i=0; i<m_length; i++)
        {
            m_pointer[i] = 0;
        }
    }
    else
    {
        ret = false;
    }
    return ret;
}


IntArray* IntArray::NewInstance(int length) 
{
    IntArray* ret = new IntArray(length);
    if( !(ret && ret->construct()) ) //创建的对象完整，construct成功
    {
        delete ret;
        ret = 0;
    }
    return ret;
}
/***************************用二阶构造进行替代*************************************8/

/****************************/
//在对象销毁时自动调用
IntArray::~IntArray()
{
    //在构造函数是如果使用了堆空间 记得清理
    delete[]m_pointer;
}
/****************************/
int IntArray::length()
{
    return m_length;
}

bool IntArray::get(int index, int& value)
{
    bool ret = (0 <= index) && (index < length());
    if( ret )
    {
        value = m_pointer[index];
    }
    return ret;
}

bool IntArray::set(int index, int value)
{
    bool ret = (0 <= index) && (index < length());
    if( ret )
    {
        m_pointer[index] = value;
    }
    return ret;
}
//对[]进行了重载使得变成
int& IntArray::operator [] (int index)
{
    return m_pointer[index];
}
//返回自身
IntArray& IntArray::self()
{
    return *this;
}
//试试看看能不能写出对应的拷贝函数
//通过重载赋值操作符进行深拷贝-----不可能调用二阶构造里面的
//要实现这类深拷贝必须对赋值操作符号进行重载
IntArray& IntArray::operator = (const IntArray& obj)//2
{
    if( this != &obj )//1
    {
        int* pointer = new int[obj.m_length];
        if( pointer )
        {
            for(int i=0; i<obj.m_length; i++)
            {
                pointer[i] = obj.m_pointer[i];
            }
            m_length = obj.m_length;//更新长度
            delete[] m_pointer;//释放空间
            m_pointer = pointer;
        }
    }
    return *this;//
}