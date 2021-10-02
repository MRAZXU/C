#include <stdio.h>
//C语言中只有一个全局作用域
//C++命名空间将全局作用域分成不同部分
//不同空间中的标识符可以同名，不会发生冲突
//可以相互嵌套

namespace First
{
    int i = 0;
}

namespace Second
{
    int i = 1;
    
    namespace Internal
    {
        struct P
        {
            int x;
            int y;
        };
    }
}

int main()
{
    using namespace First;//使用整个命名空间
    using Second::Internal::P;//使用子空间的变量
    //::var使用默认空间（全局作用域）的变量
    printf("First::i = %d\n", i);
    printf("Second::i = %d\n", Second::i);
    P p = {2, 3};
    printf("p.x = %d\n", p.x);
    printf("p.y = %d\n", p.y);
    
    return 0;
}