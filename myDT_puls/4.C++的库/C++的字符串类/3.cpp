/***********面试题！！！！***********************/
//字符串循环右移abcdefg 又移三位
#include <iostream>
#include <string>

using namespace std;
//用子串的思想---库函数中提取子串函数
//对>>符号重载
string operator >> (const string& s, unsigned int n)
{
    string ret = "";
    unsigned int pos = 0;
    //length是字符串
    n = n % s.length();//求余---求等价的移动步长
    pos = s.length() - n;//子串的开头
    //abcd.efg
    ret = s.substr(pos);
    ret += s.substr(0, pos);
    return ret;
}
/*
C语言中的方法
*/

int main()
{
    string s = "abcdefg";
    string r = (s >> 3);
    
    cout << r << endl;
    
    return 0;
}
