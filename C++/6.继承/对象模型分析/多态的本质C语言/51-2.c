#include "51-2.h"
#include "malloc.h"

static int Demo_Virtual_Add(Demo* pThis, int value);//具体的虚函数命名
static int Derived_Virtual_Add(Demo* pThis, int value);

struct VTable     // 2. 定义虚函数表数据结构
{
    int (*pAdd)(void*, int);   // 3. 虚函数表里面存储什么？？？----虚函数地址
};

struct ClassDemo
{
    struct VTable* vptr;     // 1. 定义虚函数表指针  ==》 虚函数表指针类型？？？函数指针
    int mi;
    int mj;
};

struct ClassDerived
{
    struct ClassDemo d;
    int mk;
};

static struct VTable g_Demo_vtbl = 
{
    Demo_Virtual_Add
};

static struct VTable g_Derived_vtbl = 
{
    Derived_Virtual_Add
};//通过static隐藏虚函数表成员

Demo* Demo_Create(int i, int j)
{
    struct ClassDemo* ret = (struct ClassDemo*)malloc(sizeof(struct ClassDemo)); 

    if( ret != NULL )
    {
        ret->vptr = &g_Demo_vtbl;   // 4. 关联对象和虚函数表
        ret->mi = i;
        ret->mj = j;
    }
    
    return ret;
}

int Demo_GetI(Demo* pThis)
{
     struct ClassDemo* obj = (struct ClassDemo*)pThis;    
     return obj->mi;
}

int Demo_GetJ(Demo* pThis)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;
    return obj->mj;
}

// 6. 定义虚函数表中指针所指向的具体函数
static int Demo_Virtual_Add(Demo* pThis, int value)
{
    struct ClassDemo* obj = (struct ClassDemo*)pThis;
    return obj->mi + obj->mj + value;
}


// 5. 分析具体的虚函数！！！！
int Demo_Add(Demo* pThis, int value)
{

    struct ClassDemo* obj = (struct ClassDemo*)pThis;
    //通过对象找到虚函数指针，在虚函数表表找到对应的虚函数
    return obj->vptr->pAdd(pThis, value);
}
void Demo_Free(Demo* pThis)
{
    free(pThis);
}

Derived* Derived_Create(int i, int j, int k)
{
    struct ClassDerived* ret = (struct ClassDerived*)malloc(sizeof(struct ClassDerived));
    if( ret != NULL )
    {
        ret->d.vptr = &g_Derived_vtbl;
        ret->d.mi = i;
        ret->d.mj = j;
        ret->mk = k;
    }
    
    return ret;
}

int Derived_GetK(Derived* pThis)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis;
    return obj->mk;
}
//子类的虚函数
static int Derived_Virtual_Add(Demo* pThis, int value)
{
    struct ClassDerived* obj = (struct ClassDerived*)pThis; 
    return obj->mk + value;
}

int Derived_Add(Derived* pThis, int value)
{   
    struct ClassDerived* obj = (struct ClassDerived*)pThis;
    return obj->d.vptr->pAdd(pThis, value);
}