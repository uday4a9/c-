#include <iostream>

using namespace std;

class Functor {
    private:
        int id;
    public:
        Functor(int id)
        {
            cout<<"Default constructor"<<endl;
            this->id = id;
        }

        void operator()()
        {
            cout<<"(), operator ovaerloadedd"<<endl;
        }
};

int main(int argc, char **argv)
{
    Functor fobj(12);
    fobj();

    return 0;
}
