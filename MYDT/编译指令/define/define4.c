#include <stdio.h>
#include <malloc.h>
//内置宏以及宏的综合示例
//强大的内置宏
//__FILE__当前被编译的文件名
//__LINE__当前行号
//__DATE__被编译的时间
//__STDC__是否遵循标准C规范

//宏可以做函数做不到的
#define MALLOC(type, x) (type*)malloc(sizeof(type)*x)

#define FREE(p) (free(p), p=NULL)

#define LOG(s) printf("[%s] {%s:%d} %s \n", __DATE__, __FILE__, __LINE__, s)

#define FOREACH(i, m) for(i=0; i<m; i++)
#define BEGIN {
#define END   }

int main()
{
    int x = 0;
    int* p = MALLOC(int, 5);
    
    LOG("Begin to run main code...");
    
    FOREACH(x, 5)
    BEGIN
        p[x] = x;
    END
    
    FOREACH(x, 5)
    BEGIN
        printf("%d\n", p[x]);
    END
    
    FREE(p);
    
    LOG("End");
    
    return 0;
}