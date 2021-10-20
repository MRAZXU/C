#include "comp.h"
//E-----S-----C
//预编译
//gcc中的预编译：gcc -E file.c -o file.i
//处理了注释，以空格代替
//删除#define展开所有宏定义
//处理条件编译
//删除#inculde替换为头文件内容，保留编译器需要的#pragma指令
/************************************************************/
//编译
//对.i文件进行词法分析，语法分析，语义分析
//gcc -S file.i -o file.s
/************************************************************/
//汇编
//对汇编语言翻译成机器指令
//gcc -C file.s -o file.o
#define GREETING "Hello world!"
#define INC(x) x++

int main()
{   
    p = GREETING;
    INC(i);
    return 0;
}
//
//最终需要链接
//gcc ./comp.o