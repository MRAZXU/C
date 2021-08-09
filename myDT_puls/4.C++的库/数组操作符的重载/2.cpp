//数组访问操作符本质上就是数组访问和指针运算
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a[5] = {0};
    for(int i=0; i<5; i++)
    {
        a[i] = i;
    }
    for(int i=0; i<5; i++)
    {
        cout << *(a + i) << endl;    // cout << a[i] << endl;
    }
    cout << endl;
    for(int i=0; i<5; i++)
    {   
        //*(i+a)==>*(a+i)==>a[i]
        i[a] = i + 10;    // a[i] = i + 10;
    }
    for(int i=0; i<5; i++)
    {
        cout << *(i + a) << endl;  // cout << a[i] << endl;
    }
    return 0;
}