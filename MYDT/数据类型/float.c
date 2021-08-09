#include <stdio.h>
//浮点数

int main()
{
    float f = 8.25;
    
    unsigned int* p = (unsigned int*)&f;
    //STEP1:8.25=1000.01(0.25-->1/4-->0.01)
    //STEP2:科学计数法转换：1000.01=1.00001X2^3
    //STEP3:加上偏移127+3---->10000010.00001
    //SREP4:末尾补齐64位
    printf("0x%08X\n", *p);//0x41040000
    
    return 0;
}