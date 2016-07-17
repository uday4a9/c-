#include <iostream>

using namespace std;

#define PRINTSTAR(X) {for(int _i=0; _i<X && cout<<"*"; _i++); cout<<endl;}

class Base {
    private:
        int i;
        int j;
    public:
        Base(int i=12, int j=13) {
            this->i = i;
            this->j = j;
        }

        friend ostream& operator<<(ostream &out, Base &ref) {
            out<<"***********"<<endl;
            out<< &ref << endl;
            out<<&(ref.i)<<" : "<<ref.i<<"; "<<&(ref.j)<<" : "<<ref.j;
            out<<endl<<"***********";
            return out;
        }
        
#if 1
/*
if the machine is 64bit, it occupies the 8-bytes as pointer size.
                  32bit, it occupies the 4-bytes as pointer size.
   case 1:   If we enable the below code output:
        0x7ffeca2708c0
        ***********
        0x7ffeca2708c0
        0x7ffeca2708c8 : 12; 0x7ffeca2708cc : 13
        ***********
        Meaning: Here *__vptr will added here, so output will changes with offset diff of pointer size.

    case 2:If we disable the below code output:
        0x7ffd423256d0
        ***********
        0x7ffd423256d0
        0x7ffd423256d0 : 12; 0x7ffd423256d4 : 13
        ***********
    Meaning : Here objectbase address and first element address wil be the same.
*/
        virtual void fun() {
            cout<<"In fun"<<endl;
        }
#endif
};

typedef void (*funp) ();

int main(int argc, char **argv)
{
    Base bobj;
    int *ptr;

    ptr = (int*) &bobj;

    cout<<ptr<<endl;
    cout<<bobj<<endl;
    
    // Function pointer
    void (Base::*ptrfun) () = &Base::fun;
    cout<<(void*)&ptrfun<<endl;

# if 0
/*
    If we enable this block of code, *__vptr address will corrupt and causes for segmentaion fault.
*/
    *(ptr+0) = -12;
#endif

    (*(Base*)ptr).fun();    // typecast the same back to, Base*

    PRINTSTAR(20);
    cout<<"Object address : " <<&bobj<<endl;
    cout<<"vptr address is : "<<(&bobj+0)<<" in base obj : "<<&bobj<<endl;
    // If we are not converting the below one to (int*), Then it invokes overloaded operator<< in base class
    cout<<"vtable address is : "<<*(int*)(&bobj+0)<<" in base obj : "<<&bobj<<endl;
    cout<<"vtable entries  are : "<<*(long int *)*(long int *)*(long int*)(&bobj+0)<<" in base obj : "<<&bobj<<endl;

    funp func = (funp)*(long int *)*(long int*)(&bobj+0);
    func();

    PRINTSTAR(20);

    return 0;
}
