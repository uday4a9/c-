/*
Here mainly two classes starts working. 
1. Observable Class 2. Observer class

1. Observable class is where the actual data change is occuring.
   it has info about all interested objects that needs to be notified.
2. Observer is a typically an abstract class providing the interfaces
   to which concrete classes interested in the events need to be compliant
   to.
*/

#include <iostream>
#include <set>

using namespace std;

// First need to define an interface for observer
class MyObserver{
    public:
        virtual void notify() = 0;
};

// Observable Object
class Observable{
    private:
        static Observable *instance;
        set<MyObserver*> observers;
        Observable();
    public:
        static Observable* getinstance();
        void regitser(MyObserver &o);
        void deregister(MyObserver &o);
        void notifyall();
        void trigger();
};

Observable* Observable::instance = NULL;

Observable::Observable()
{
    cout<<"Observer object created"<<endl;
}

Observable* Observable::getinstance()
{
    if (instance == NULL)
        instance = new Observable();
    return instance;
}

void Observable::regitser(MyObserver &o)
{
    observers.insert(&o);
}

void Observable::deregister(MyObserver &o)
{
    observers.erase(&o);
}

void Observable::notifyall()
{
    for(auto i : observers)
        i->notify();
}

void Observable::trigger()
{
    notifyall();
}

//My class, to be notified
class MyClass : public MyObserver {
    private:
        Observable *observable;
    public:
        MyClass()
        {
            cout<<"Created a new object "<<this<<endl;
            observable = Observable::getinstance();
            observable->regitser(*this);
        }

        ~MyClass()
        {
            observable->deregister(*this);
        }

        void notify()
        {
            cout<<"rceived change event for "<<this<<endl;
        }
};


int main(int argc, char **argv)
{
    Observable *observable = Observable::getinstance();
    MyClass *obj1 = new MyClass();
    MyClass *obj2 = new MyClass();

    observable->trigger();

    return 0;
}
