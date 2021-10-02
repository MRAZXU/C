#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test
{
    int m_value;
public:
    Test()
    {
        m_value = 0;
    }
    
    ~Test()
    {
    }
    
    void* operator new (unsigned int size)
    {
        cout << "operator new: " << size << endl;
        
        return malloc(size);
    }
    
    void operator delete (void* p)
    {
        cout << "operator delete: " << p << endl;
        
        free(p);
    }
    
    void* operator new[] (unsigned int size)
    {
        cout << "operator new[]: " << size << endl;
        
        return malloc(size);
    }
    
    void operator delete[] (void* p)
    {
        cout << "operator delete[]: " << p << endl;
        
        free(p);
    }
};

int main(int argc, char *argv[])
{
    Test* pt = NULL;
    pt = new Test;
    delete pt;
    pt = new Test[5];
    delete[] pt;
    return 0;
}
