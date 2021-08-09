#include <stdio.h>
#include "mleak.h"
//m和f函数是标准库的函数
//m实际分配的内存可能比请求的多（可能n字节对齐） 不同系统下可能为不同
//当动态内存无法返回时malloc返回为NULL
//嵌入式中mallco可能不一样 
void f()
{
    MALLOC(100);
      /**************!!!面试题!!!****************/
    //malloc(0)也会申请到内存空间---->>>>>必须free
}

int main()
{
    int* p = (int*)MALLOC(3 * sizeof(int));
    
    f();
    
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    
    FREE(p);
    
    PRINT_LEAK_INFO();
    
    return 0;
}
