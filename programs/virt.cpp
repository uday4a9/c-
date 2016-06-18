#include <iostream>

using namespace std;

class Base {
    public:
        virtual void func1()
        {
            cout<<"In base function"<<endl;
        }

};

class Der1 : public Base
{
    public:
        virtual void func1()
        {
            cout<<"In der1 func1"<<endl;
        }

        virtual void func2()
        {
            cout<<"In der1 func2"<<endl;
        }
};

int main(int argc, char **argv)
{
    Base *bptr;
    Der1 dobj;

    bptr = &dobj;
    bptr->func1();

    return 0;
}
