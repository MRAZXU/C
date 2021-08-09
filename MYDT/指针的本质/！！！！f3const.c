//这一节非常重要，面试必考！
#include <stdio.h>
//考试重点常量与指针
int main()
{
    int i = 0;
    //熟计口诀：左数右指：
    //const出现在*左边：指向的数据不能变
    //const出现在*右边：指针不能变
    const int* p1 = &i;//数据
    int const* p2 = &i;//数据
    int* const p3 = &i;//指针
    const int* const p4 = &i;//数据+指针
    
   // *p1 = 1;    // compile error
    p1 = NULL;  // ok
    
    //*p2 = 2;    // compile error
    p2 = NULL;  // ok
    
    *p3 = 3;    // ok
    //p3 = NULL;  // compile error
    
    //*p4 = 4;    // compile error
    //p4 = NULL;  // compile error
    
    return 0;
}