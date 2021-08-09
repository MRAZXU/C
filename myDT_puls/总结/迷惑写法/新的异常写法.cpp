#include <iostream>
#include <string>

using namespace std;

int func(int i, int j) throw(int, char)
{
    if( (0 < j) && (j < 10) )
    {
        return (i + j);
    }
    else
    {
        throw '0';
    }
}

void test(int i) try
{
    cout << "func(i, i) = " << func(i, i) << endl;
}
catch(int i)
{
    cout << "Exception: " << i << endl;
}
catch(...)
{
    cout << "Exception..." << endl;
}


int main(int argc, char *argv[])
{
    test(5);
    
    test(10);
    
    return 0;
}