#include <iostream>

using namespace std;

int i=-1;

class man
{
	public:
		static int cnt;
		int& ret()
		{
			return i;
		}

		void print(int i=0)
		{
			cout<<"IN Print : val of i : "<<i<<"and ::i :"<<::i<<"and member i:"<<this->i<<endl;
		}

		man()
		{
			i=14;
			cout<<"COnstructor invoked"<<endl;
		}

		~man()
		{
			cout<<"Destructor"<<endl;
		}

/*		void dis() constant
		{
			cout <<"constant dis function"<<endl;
		}
*/
		void dis() 
		{
			cout <<"non-constant dis function"<<endl;
		}

    man(int val)
    {
        i = val;
    }

    man(man &ref)
    {
        cout<<"copy constructor invoked"<<endl;
        i = ref.i;
    }

    friend ostream& operator<<(ostream &op, man &dat)
    {
        op<<"i : "<<dat.i<<endl;
        return op;
    }

    man& operator=(man &right)
    {
        cout<<"Assignement operator overloaded"<<endl;
        if(this == &right) {
            cout<<"self assignment"<<endl;
            return *this;
        }
        this->i = right.i;
        return *this;

    }


	private:
		int i;
};

int main(int argc, char **argv)
{
/*	man m = man();
	m.print(32);
	m.ret()=567;
	m.print();
*/
	const man m1;
	//man m1;
	//m1.dis();

  man m3(20);
//  m3.print();
  cout<<m3;
  man m4=m3;
  //m4.print();
  cout<<m4;

  m3 = m4;
  cout<<m4;

	return 0;
}
