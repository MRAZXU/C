/**************面试题***************/
//编写程序判断一个变量是不是指针
#include <iostream>
#include <string>
//调用优先级123
using namespace std;

class Test
{
public:
    Test()
    {
    }
    virtual ~Test()
    {
    }
};

template
<typename T>
char IsPtr(T* v) // match pointer
{
    return 'd';
}

//变参函数
int IsPtr(...)  // match non-pointer
{
    return 0;
}

#define ISPTR(p) (sizeof(IsPtr(p)) == sizeof(char))//只匹配不调用
//sizeof不是函数


int main(int argc, char *argv[])
{
    int i = 0;
    int* p = &i;
    
    cout << "p is a pointer: " << ISPTR(p) << endl;    // true
    cout << "i is a pointer: " << ISPTR(i) << endl;    // false
    
    Test t;
    Test* pt = &t;//这里可能有问题
    
    cout << "pt is a pointer: " << ISPTR(pt) << endl;    // true
    cout << "t is a pointer: " << ISPTR(t) << endl;    // false
    
    return 0;
}