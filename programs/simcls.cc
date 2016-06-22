#include <iostream>

using namespace std;

class Main {
    private:
        int &t;
    public:
        Main(int val=10): t(val)
        {
            cout<<this<<" : Constructor object created"<<endl;
        }

        ~Main() {
            cout<<this<<" : Destructor object created"<<endl;
        }

        void display() {
            cout<<"Display val : "<<this->t<<endl;
        }
};

int main()
{
    Main m(100);

    m.display();
            
    return 0;
}
