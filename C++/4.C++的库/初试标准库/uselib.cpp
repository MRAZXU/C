//C++标准库的子库
//这个子库的缺点是要改头文件
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
//使用标准库的话需要打开标准库的命名空间
using namespace std;


int main()
{
    printf("Hello world!\n");
    
    char* p = (char*)malloc(16);
    
    strcpy(p, "D.T.Software");
    
    double a = 3;
    double b = 4;
    double c = sqrt(a * a + b * b);
    
    printf("c = %f\n", c);
    
    free(p);
    
    return 0;
}