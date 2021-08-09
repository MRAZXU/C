#include <stdio.h>
#include <string.h>
//字符串循环右移
void right_shift_r(const char* src, char* result, unsigned int n)
{
    const unsigned int LEN = strlen(src);//没有记录\0
    int i = 0;
    for(i=0; i < LEN; i++)
    {
        //以最高效率实现：下标求余数
        //O(len)
        result[(n + i) % LEN] = src[i];
    }
    //我们处理的是字符数组而不是字符串，且\0永远在末尾！！！！
    result[LEN] = '\0';//添加边界！！！！！！！
}
int main()
{
    char result[255] = {0};
    right_shift_r("abcde", result, 2);
    printf("%s\n", result);
    right_shift_r("abcde", result, 5);
    printf("%s\n", result);
    right_shift_r("abcde", result, 8);
    printf("%s\n", result);
    return 0;
}