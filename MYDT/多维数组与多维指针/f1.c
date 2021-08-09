#include <stdio.h>
#include <malloc.h>
/***********************面试题！！！！********************************/
//重置动态空间大小
int reset(char**p, int size, int new_size)
{
    int ret = 1;
    int i = 0;
    int len = 0;
    char* pt = NULL;
    char* tmp = NULL;
    //定义指针的指针保存指针变量的地址值
    char* pp = *p;
    if( (p != NULL) && (new_size > 0) )
    {
        pt = (char*)malloc(new_size);
        //tmp指向了pt的地址值
        tmp = pt;
        len = (size < new_size) ? size : new_size;
        for(i=0; i<len; i++)
        {
            //这里是吧原来的地址值放入新的里面
            *tmp++ = *pp++;      
        }
        free(*p);
        *p = pt;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
int main()
{
    char* p = (char*)malloc(5);
    printf("%p\n", p);
    if( reset(&p, 5, 3) )
    {
        printf("%p\n", p);
    }
    free(p);
    return 0;
}
//不知理解是否正确，有时间可以再看看对应视频