#include <iostream>

using namespace std;

class base
{
	public:
		base()
		{
			cout<<"base constructor "<<endl;
		}
	
		~base()
		{
			cout<<"base destructor"<<endl;
		}
	
		void print() const
		{
			cout<<"Print function in base"<<endl;
		}
		void disp() const
		{
			cout<<"disp method in base"<<endl;
		}
};



class der : public base
{
	public:
		der()
		{
			cout<<"der constructor "<<endl;
		}
	
		~der()
		{
			cout<<"der destructor"<<endl;
		}

		void print() const
		{
			cout<<"Print function in der"<<endl;
		}

		void disp() const
		{
//			base::disp();
			cout<<"disp method in der"<<endl;
		}
};

int main(int argc, char **argv)
{

	base b,*bptr;
	der d,*dptr;
	
	cout<<"Direct calls"<<endl;	
	b.print();
	d.print();
	
	cout<<"cross direct pointer calls"<<endl;
	bptr = &d;
	bptr->print();
	dptr = (der*) &b;
	dptr->print();
	

	return 0;
}
