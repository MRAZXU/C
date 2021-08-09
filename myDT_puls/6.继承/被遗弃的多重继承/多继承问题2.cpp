#include <iostream>
#include <string>

using namespace std;

class People
{
    string m_name;
    int m_age;
public:
    People(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    void print()
    {
        cout << "Name = " << m_name << ", "
             << "Age = " << m_age << endl;
    }
};
//虚继承
class Teacher : virtual public People
{
public:
    Teacher(string name, int age) : People(name, age)
    {
    }
};

class Student : virtual public People
{
public:
    Student(string name, int age) : People(name, age)
    {
    }
};

class Doctor : public Teacher, public Student
{
public:
    Doctor(string name, int age) : Teacher(name, age), Student(name, age), People(name, age)
    {
    }
};

int main()
{
    Doctor d("Delphi", 33);
    
    d.print();
    
    return 0;
}
//缺点：中间层不在继承顶层父类的初始化，由最终子类直接调用顶层父类的构造函数\
效率低下！