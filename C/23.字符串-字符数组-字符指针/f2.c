#include <stdio.h>
#include <string.h>

int main()
{
    #define STR "Hello, \0D.T.Software\0"//define又又又躲过去了
    
    char* src = STR;//作为字符数组直接从第一个\0开始结束
    char buf[255] = {0};
    
    snprintf(buf, sizeof(buf), src);
    
    printf("strlen(STR) = %ld\n", strlen(STR));//7
    printf("sizeof(STR) = %ld\n", sizeof(STR));//22
    
    printf("strlen(src) = %ld\n", strlen(src));//7
    printf("sizeof(src) = %ld\n", sizeof(src));//8
    
    printf("strlen(buf) = %ld\n", strlen(buf));//7
    printf("sizeof(buf) = %ld\n", sizeof(buf));//255
    
    printf("src = %s\n", src);//Hello,
    printf("buf = %s\n", buf);//Hello,
    
    return 0;
}
