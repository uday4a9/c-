/* Which returns always one object,
   the subsequent calls always returns the unique address
   only*/

#include <iostream>

using namespace std;

class Singleton{
    private:
        Singleton(){
            cout<<"In constructor"<<endl;
        }
    public:
        static Singleton *instance;

        static Singleton* getinstance() {
            if(instance == NULL)
                instance = new Singleton();
            return instance;
        }

};

Singleton* Singleton::instance = NULL;

int main(int argc, char **argv)
{
    /* returns always the same object
       */
    Singleton *obj, *aobj;

    obj = Singleton::getinstance();
    cout<<obj<<endl;

    aobj = Singleton::getinstance();
    cout<<aobj<<endl;

    return 0;
}
