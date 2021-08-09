#include <stdio.h>
//类的封装使得使用方式和内部细节相分离
int i = 1;
struct Test
{
private:
    int i;
public:
    int j;
    int getI()
    {
        i = 3;
        return i;
    }
};
int main()
{
    int i = 2;
    Test test;
    test.j = 4;
    printf("i = %d\n", i);              // i = 2;
    printf("::i = %d\n", ::i);          // ::i = 1;
    // printf("test.i = %d\n", test.i);    // Error  没有访问权限
    printf("test.j = %d\n", test.j);    // test.j = 4
    printf("test.getI() = %d\n", test.getI());  // test.getI() = 3
    return 0;
}