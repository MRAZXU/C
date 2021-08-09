#include <iostream>
#include <string>

using namespace std;

class Demo
{
    int mi;
    int mj;
public:
    Demo(int i, int j)
    {
        mi = i;
        mj = j;
    }
    
    int getI()
    {
        return mi;
    }
    
    int getJ()
    {
        return mj;
    }
    
    int add(int value)
    {
        return mi + mj + value;
    }
};

int main()
{
    Demo d(1, 2);
    
    cout << "sizeof(d) = " << sizeof(d) << endl;//8
    cout << "d.getI() = " << d.getI() << endl;//1
    cout << "d.getJ() = " << d.getJ() << endl;//2
    cout << "d.add(3) = " << d.add(3) << endl;//6
    
    return 0;
}