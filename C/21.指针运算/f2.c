#include <stdio.h>
//指针减法
//减法===p1-p2====同类型(p1-p2)/sizeof(type)
//!!!!!!!!!!i指针所指向元素的下标查
int main()
{
    char s1[] = {'H', 'e', 'l', 'l', 'o'};
    int i = 0;
    char s2[] = {'W', 'o', 'r', 'l', 'd'};
    char* p0 = s1;
    char* p1 = &s1[3];
    char* p2 = s2;
    int* p = &i;
	
    printf("%ld\n", p0 - p1);
    //printf("%d\n", p0 + p2);不存在
    printf("%ld\n", p0 - p2);
    //printf("%d\n", p0 - p);//不是同一类型 不支持相减
    //printf("%d\n", p0 * p2);//没有
    //printf("%d\n", p0 / p2);//没有
	
    return 0;
}