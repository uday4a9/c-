#include <iostream>

using namespace std;

void fun(int val)
{
    cout<<"In global function"<<val<<endl;
}
typedef void (*funp) (int);

void* infun(int newval, funp func)
{
    cout<<"Inside infunction"<<endl;
    func(newval);
}
typedef void* (*infunp)(int, funp);

class A {
    int id;

public:
    A(int id)
    {
//        cout<<"constructor invoked"<<endl;
        this->id =id;
    }

    A(A &ref)
    {
//        cout<<"Copy constructor invoked"<<endl;
        this->id = ref.id;
    }

    A& operator=(A &ref)
    {
//        cout<<"Assignment operator overloaded"<<endl;
        if(this == &ref)
            return *this;
        this->id = ref.id;
        return *this;
    }

    int getval(void)
    {
        return id;
    }
};
typedef int (A::*valp) (void);

int main(int argc, char **argv)
{
    A aobj(12);
    cout<<"aobj value is : "<<aobj.getval()<<endl;

    A bobj(23);
    cout<<"bobj value is : "<<bobj.getval()<<endl;

    funp foo = fun;
//    fun(123);

    infunp goo = infun;
    goo(321, foo);

    valp v = &A::getval;
    cout<<"Vlaue using function pointer : "<<(aobj.*v)()<<endl;

    return 0;
}
