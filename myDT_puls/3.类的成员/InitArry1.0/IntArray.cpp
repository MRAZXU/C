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

//试试看看能不能写出对应的拷贝函数
/*
IntArray*IntArray::NewInstance(const IntArray& obj)
{
}
*/