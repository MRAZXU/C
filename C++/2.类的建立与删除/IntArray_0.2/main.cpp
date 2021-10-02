#include <stdio.h>
#include "IntArray.h"
//数组类解决C语言原生数组的安全性问题（无长度信息到时候的访问越界问题）
int main()
{
    IntArray a(5);    
    for(int i=0; i<a.length(); i++)
    {
        a.set(i, i + 1);
    }
    for(int i=0; i<a.length(); i++)
    {
        int value = 0;
        if( a.get(i, value) )
        {
            printf("a[%d] = %d\n", i, value);
        }
    }
    //这里就需要拷贝构造函数
    //如果类成员是指向动态内存的，就必须进行深拷贝
    IntArray b = a;
    
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
    //b.free();
    return 0;
}
