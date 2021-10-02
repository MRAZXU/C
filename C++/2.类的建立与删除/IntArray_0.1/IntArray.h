#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int* m_pointer;
public:
    int length();
 //以下都是构造函数
    IntArray(int len);

    //升级！对类进行深拷贝
    IntArray(const IntArray& obj);

    bool get(int index, int& value);
    bool set(int index ,int value);
    void free();
};

#endif