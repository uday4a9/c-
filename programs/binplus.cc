#include <iostream>

using namespace std;

class rat {
    private:
        int i, j;
        static int value;
    public:
        rat(int x=0, int y=0) {
            i = x;
            j = y;
        }

        friend ostream& operator<<(ostream &out, rat &ref) {
            out<<ref.i<<" "<<ref.j<<" ";
            return out;//<<endl;
        }
        
        int getx() {
            return i;
        }

        int gety() {
            return j;
        }

        static void val() {
            rat::value=0;
            cout<<"val invoked"<<endl;
        }
};

//int rat::val = 0;
int rat::value=2;
/*
   reat &ref1, rat &ref2 will not works for this.
*/
rat operator+(rat ref1, rat ref2)
{
    cout<<"global operator+ overloaded"<<endl;
    int i, j;
    i = ref1.getx() + ref2.getx();
    j = ref1.gety() + ref2.gety();
    rat ob(i, j);
    return ob;
}

int main(int argc, char **argv)
{
    rat r1(2, 3), r2(3, 4);
    rat r3 = r1 + r2;
    cout<<"r1 : "<<r1<<", r2 : "<<r2<<endl;
    cout<<"r3 : "<<r3<<endl;

    rat r4 = 1;    // implicit constructor, Which converts implicit method to
                // to this class object(By default it invokes defaultt constructor

    cout<<"r4 : "<<r4<<endl;
    r4.val();
    rat::val();

    cout<<"size : "<<sizeof(rat)<<endl;
    cout<<12 + 23<<endl;

    return 0;
}
