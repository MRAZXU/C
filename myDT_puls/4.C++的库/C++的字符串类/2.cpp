#include <iostream>
#include <sstream>//字符串流类==字符串和数组的转换
#include <string>
//字符串和数组的转换
using namespace std;
//定义全局函数
//定义宏完成所有数字类型的转换---以后可以用函数模板
#define TO_NUMBER(s, n) (istringstream(s) >> n)//直接调用构造函数生成临时对象
//
#define TO_STRING(n) (((ostringstream&)(ostringstream() << n)).str())//里面有一个强制类型转换
//istringstream字符串输入流---字符串转数字
//用法：
//istringstream iss("123.45")
//double num;
//iss>>num;
//ostringstream字符串输出流---数字转字符串
//用法：
//ostringstream oss
//oss<<651.22
//string s=oss.str();
int main()
{
    double n = 0;
    if( TO_NUMBER("234.567", n) )
    {
        cout << n << endl;    
    }
    string s = TO_STRING(12345);
    cout << s << endl;     
    return 0;
}