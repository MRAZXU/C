#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int* m_pointer;
public:
    int length();
       
    //升级！对类进行深拷贝
    IntArray(const IntArray& obj);

    bool get(int index, int& value);
    bool set(int index ,int value);
 //下面函数为自定义的构造函数
    IntArray(int len);
    ~IntArray();

    //void free();
};

#endif