/* This patterns creates the multiple types of objects
   dynamically.
*/
#include <iostream>
#include <string>

using namespace std;

class Mobile{
    public:
        virtual string camera() = 0;
        virtual string keyboard() = 0;

        void specs()
        {
            cout<<camera()<<endl;
            cout<<keyboard()<<endl;
        }
};

class Lowend: public Mobile{
    public:
        string camera()
        {
            return "2 Megapixel";
        }
        
        string keyboard()
        {
            return "ITU-T";
        }
};

class Highend: public Mobile{
    public:
        string camera()
        {
            return "5 Megapixel";
        }
        
        string keyboard()
        {
            return "Qwerty";
        }
};

class MobileFactory{
    public:
        Mobile* GetMobile(string type)
        {
            if(type == "low") return new Lowend();
            if(type == "high") return new Highend();
        }
};

void breakline(string sep="*")
{
    char ar[10];

    for(auto i : ar)
        cout<<sep;
    cout<<endl;
}

int main(int argc, char **argv)
{
    MobileFactory *fact = new MobileFactory();
    int ar[10] = {0};

    Mobile *mob1 = fact->GetMobile("low");
    mob1->specs();

    breakline();

    Mobile *mob2 = fact->GetMobile("high");
    mob2->specs();

    breakline(":");

    return 0;
}
