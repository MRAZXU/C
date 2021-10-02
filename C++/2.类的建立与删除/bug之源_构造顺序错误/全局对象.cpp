#include "test.h"
//全局对象的构造顺序不确定
//C++中应该尽力避免全局构造
Test t4("t4");

int main()
{
    Test t5("t5");
}