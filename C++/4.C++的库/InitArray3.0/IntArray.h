#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int* m_pointer;
/***************二阶构造类声明***********************/  
//说明了二阶构造的安全性
    IntArray(int len);
    IntArray(const IntArray& obj);
    bool construct();//----->>>在private内
/***************二阶构造类声明***********************/    
public:
//创建函数，这里的创建函数也是静态成员函数！！！！！！
    static IntArray* NewInstance(int length); 
    int length();
       
    //升级！对类进行深拷贝
    //IntArray(const IntArray& obj);

    bool get(int index, int& value);
    bool set(int index ,int value);
    //重载[]操作符号
    int& operator [] (int index);
    //重载=操作符实现深拷贝
    IntArray& operator = (const IntArray& obj);
    //返回自身
     IntArray& self();
    //下面函数为自定义的构造函数
    ~IntArray();

    //void free();
};

#endif