#ifndef _OPERATOR_H_
#define _OPERATOR_H_
//类模板在头文件定义
//外部定义的成员函数需要加上<>申明

template < typename T >
class Operator
{
public:
    T add(T a, T b);
    T minus(T a, T b);
    T multiply(T a, T b);
    T divide(T a, T b);
};

template < typename T >
T Operator<T>::add(T a, T b)
{
    return a + b;
}


template < typename T >
T Operator<T>::minus(T a, T b)
{
    return a - b;
}


template < typename T >
T Operator<T>::multiply(T a, T b)
{
    return a * b;
}


template < typename T >
T Operator<T>::divide(T a, T b)
{
    return a / b;
}

#endif