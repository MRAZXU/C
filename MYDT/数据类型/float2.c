//浮点数
//浮点型的精度比整型低所致范围
//浮点数是如何转化为内存里的数据
#include <stdio.h>
//浮点数不精确的证明
int main()
{
    float f = 3.1415f;
    float fl = 123456789;
    printf("%0.10f\n", f);
    printf("%0.10f\n", fl);
    return 0;
}
