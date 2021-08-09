#include <stdio.h>
#if 0
//显性的强制类型转换
struct TS
{
    int i;
    int j;
};
struct TS ts;
int main()
{
    short s = 0x1122;
    char c = (char)s;    // 0x22
    int i = (int)s;      // 0x00001122
    int j = (int)3.1415; // 3
    unsigned int p = (unsigned int)&ts;//64位中会产生截断
    //long l = (long)ts;   // error
    //ts = (struct TS)l;   // error
    
    printf("s = %x\n", s);
    printf("c = %x\n", c);
    printf("i = %x\n", i);
    printf("j = %x\n", j);

    printf("p = %x\n", p);
    printf("&ts = %p\n", &ts);
    /*
    p = 9a8ea018
    &ts = 0x55d19a8ea018
    */
    return 0;
}
#endif // 
//隐性的类型转换
//小的只能化大的
#if 1
int main()
{
    char c = 'a';
    
    int i = c;    // safe 4字节
    
    unsigned int j = 0x11223344;
    
    short s = j;  // unsafe 2字节
    
    printf("c = %c\n", c);
    printf("i = %d\n", i);
    printf("j = %x\n", j);
    printf("s = %x\n", s);
    printf("sizeof(c + s) = %d\n", sizeof(c + s));//相加取大
    
    return 0;
}
#endif 