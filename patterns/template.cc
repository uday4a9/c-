/*
   Creates an template(Abstract base class), which can extends to further 
   and needs to be filled in derived class.
*/

#include <iostream>

using namespace std;

class Account{
    public:
        virtual void start() = 0;
        virtual void allow() = 0;
        virtual void end() = 0;
        virtual int maxlimit() = 0;
        void withdraw(int amount)
        {
            start();

            int limit = maxlimit();

            if(amount < limit)
                allow();
            else
                cout<<"limit nt allowed on your account"<<endl;
            end();
        }
};

class Normal : public Account {
    public:
        void start()
        {
            cout<<"START..."<<endl;
            
        }

        void allow()
        {
            cout<<"ALLOW..."<<endl;
        }

        void end()
        {
            cout<<"END..."<<endl;
        }

        int maxlimit()
        {
            return 15000;
        }
};


class Power : public Account {
    public:
        void start()
        {
            cout<<"START..."<<endl;
        }

        void allow()
        {
            cout<<"ALLOW..."<<endl;
        }

        void end()
        {
            cout<<"END..."<<endl;
        }

        int maxlimit()
        {
            return 50000;
        }
};

int main(int argc, char **argv)
{
    Power *p = new Power();
    Normal *n = new Normal();

    n->withdraw(20000);
    n->withdraw(2000);

    p->withdraw(200000);
    p->withdraw(20000);

    return 0;
}
