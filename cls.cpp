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
	m1.dis();

	return 0;
}
