#include <iostream>
#include <string>
//C++中就要用C++的思想，不要混用！！！
using namespace std;

int main()
{
    string s = "12345";//C++的字符串类
    
    const char* p = s.c_str();//相当于C语言字符串---问题在这里
    cout << s << endl;     
    s.append("abced");  // p 成为了野指针
    //cout << p << endl;     
    cout << s << endl;  
    return 0;
}
