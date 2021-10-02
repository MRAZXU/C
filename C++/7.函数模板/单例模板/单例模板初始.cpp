#include <iostream>
#include <string>
//只有一个对象的模板
using namespace std;

class SObject
{
    static SObject* c_instance;//声明
    //外界无法创立对象
    SObject(const SObject&);
    SObject& operator= (const SObject&);
    SObject()
    {
    }
public:
    static SObject* GetInstance();//用该静态成员函数进行
    void print()
    {
        cout << "this = " << this << endl;
    }
    //单例模式不需要释放空间
};

SObject* SObject::c_instance = NULL;//定义

SObject* SObject::GetInstance()
{
    if( c_instance == NULL )
    {
        c_instance = new SObject();
    }
    return c_instance;
}

int main()
{
    SObject* s = SObject::GetInstance();
    SObject* s1 = SObject::GetInstance();
    SObject* s2 = SObject::GetInstance();
    //说明了指向同一个对象
    s->print();
    s1->print();
    s2->print();
    
    return 0;
}
