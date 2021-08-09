#include <iostream>
#include <string>
#include "IntArray.h"
//数组类解决C语言原生数组的安全性问题（无长度信息到时候的访问越界问题）
using namespace std;
int main()
{
   // IntArray a(5);    error
    IntArray* a = IntArray::NewInstance(5);    //后续还可用智能指针彻底消除*

    if( a != NULL )
    {
        IntArray& array = a->self();
        cout << "array.length() = " << array.length() << endl;
        array[0] = 1;
        for(int i=0; i<array.length(); i++)
        {  
            cout << array[i] << endl;
        }
    }
     delete a;
    //这里就需要拷贝构造函数
    //如果类成员是指向动态内存的，就必须进行深拷贝
    /*IntArray b = a;
    
    for(int i=0; i<b.length(); i++)
    {
        int value = 0;
        
        if( b.get(i, value) )
        {
            printf("b[%d] = %d\n", i, value);
        }
    }
    //淘汰了大量的free的使用
    //a.free();
    //b.free();*/
    return 0;
}
