#include <stdio.h>
//#将预处理信息转化成字符串
#define STRING(x) #x

int main()
{
    
    printf("%s\n", STRING(Hello world!));
    printf("%s\n", STRING(100));
    printf("%s\n", STRING(while));
    printf("%s\n", STRING(return));

    return 0;
}