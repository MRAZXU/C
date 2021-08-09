#include <iostream>
#include <string>
//通过数组的方式单个访问字符
using namespace std;

int main()
{
    string s = "a1b2c3d4e";
    int n = 0;
        
    for(int i = 0; i<s.length(); i++)
    {
        //isdigit
        if( isdigit(s[i]) )
        {
            n++;
        }
    }
    
    cout << n << endl;
    
    return 0;
}
