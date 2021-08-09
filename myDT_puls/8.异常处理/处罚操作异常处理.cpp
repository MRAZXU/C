#include <iostream>
#include <string>

using namespace std;

double divide(double a, double b, int* valid)
{
    const double delta = 0.000000000000001;
    double ret = 0;
    if( !((-delta < b) && (b < delta)) )
    {//正常逻辑
        ret = a / b;
        *valid = 1;
    }
    else
    {//异常逻辑
        *valid = 0;
    }
    
    return ret;
}
int main(int argc, char *argv[])
{   
    int valid = 0;
    double r = divide(1, 0, &valid);
    
    if( valid )
    {
        cout << "r = " << r << endl;
    }
    else
    {
        cout << "Divided by zero..." << endl;
    }
    return 0;
}