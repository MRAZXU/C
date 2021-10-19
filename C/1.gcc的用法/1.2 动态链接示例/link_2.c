#include <stdio.h>
#include <dlfcn.h>
//linux下创立动态库(.so)----动态库是不会自可执行程序中
//STEP1.编译gcc -shared dlib.c -o dlib.so
//STEP2.gcc main.c -ldl -o main.out
//linu下的系统调用函数
//dlopen:打开动态库文件
//dlsym:查找动态库中的函数并返回调用地址
//dlclose:关闭库
//使用gcc link_2.c -ldl -o main.out
int main()
{
    void* pdlib = dlopen("./dlib.so", RTLD_LAZY);//打开方式

    char* (*pname)();
    int (*padd)(int, int);

    if( pdlib != NULL )
    {
        pname = dlsym(pdlib, "name");
        padd = dlsym(pdlib, "add");
 
        if( (pname != NULL) && (padd != NULL) )
        {
            printf("Name: %s\n", pname());
            printf("Result: %d\n", padd(2, 3));
        }
        dlclose(pdlib);
    }
    else
    {
        printf("Cannot open lib ...\n");
    }
    return 0;
}