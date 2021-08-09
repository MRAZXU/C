#include <iostream>
#include <cmath>
//标准库中的iostream库
using namespace std;

//以后就可以愉快地用C++标准库了
int main()
{
   //endl=''\n'
    cout << "Hello world!" << endl;
    
    double a = 0;
    double b = 0;
    
    cout << "Input a: ";
    cin >> a;
    
    cout << "Input b: ";
    cin >> b;
    
    double c = sqrt(a * a + b * b);
    
    cout << "c = " << c << endl;
    
    return 0;
}