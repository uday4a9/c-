#include <iostream>

using namespace std;

class sample
{
    public:
	    void show()
		{
		    cout<<"IN SHOW OF SAMPLE"<<endl;
	    }
};

int main(int argc, char **argv)
{
    sample *sp, *sp1;

	sp->show();
	sp1->show();

    return 0;
}
