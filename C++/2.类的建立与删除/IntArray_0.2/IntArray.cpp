#include "IntArray.h"
//尘归尘，土归土
IntArray::IntArray(int len)
{
    m_pointer = new int[len];
    for(int i=0; i<len; i++)
    {
        m_pointer[i] = 0;
    }
    m_length = len;
}
/*void IntArray::free()
{
    delete[]m_pointer;
}*/
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

//拷贝
IntArray::IntArray(const IntArray& obj)
{
    m_length = obj.m_length;
    
    m_pointer = new int[obj.m_length];
    
    for(int i=0; i<obj.m_length; i++)
    {
        m_pointer[i] = obj.m_pointer[i];
    }
}
