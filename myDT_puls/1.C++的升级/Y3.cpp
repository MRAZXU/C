#include <stdio.h>
/*****************引用会有自己的空间吗？************************/
//引用与指针类似，也会占用八字节空间（64位）
//内部等价于C的常量指针
struct TRef
{
    char* before;
    char& ref;
    char* after;
};

int main(int argc, char* argv[])
{
    char a = 'a';
    char& b = a;
    char c = 'c';
    TRef r = {&a, b, &c};
    printf("sizeof(r) = %d\n", sizeof(r));//24
    printf("sizeof(r.before) = %d\n", sizeof(r.before));//8
    printf("sizeof(r.after) = %d\n", sizeof(r.after));//8
    printf("&r.before = %p\n", &r.before);//0x7fffc49003f0
    printf("&r.after = %p\n", &r.after);// 0x7fffc4900400
    // 0x7fffc4900400-0x7fffc49003f0=16(十进制)
    return 0;
}