#include <iostream>
#include <string>
#include "IntArray.h"
//数组类解决C语言原生数组的安全性问题（无长度信息到时候的访问越界问题）
using namespace std;
int main()
{
   // IntArray a(5);    error
    IntArray* a = IntArray::NewInstance(5);   
    IntArray* b = IntArray::NewInstance(10);
    
    if( a && b )//如果二阶构造都成功
    {
        IntArray& array = a->self();
        IntArray& brray = b->self();
        
        cout << "array.length() = " << array.length() << endl;
        cout << "brray.length() = " << brray.length() << endl;
    
        array = brray;
        
        cout << "array.length() = " << array.length() << endl;
        cout << "brray.length() = " << brray.length() << endl;
    }
    
    delete a;
    delete b;
    //二阶构造淘汰了大量的free的使用
    //a.free();
    //b.free();*/
    return 0;
}
