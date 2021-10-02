#include <iostream>
#include <string>

using namespace std;
//隐式转换也很坑爹
int main()
{   
    short s = 'a';
    unsigned int ui = 1000;
    int i = -2000;
    double d = i;
    
    cout << "d = " << d << endl;
    cout << "ui = " << ui << endl;
    cout << "ui + i = " << ui + i << endl;
    //ui + i = 4294966296
    if( (ui + i) > 0 )//这里发生了隐类型转换
    {
        cout << "Positive" << endl;//所以-2000+1000为正
    }
    else
    {
        cout << "Negative" << endl;
    }
    //int更为高效
    cout << "sizeof(s + 'b') = " << sizeof(s + 'b') << endl;//全变成int了
    
    return 0;
}
