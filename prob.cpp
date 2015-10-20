#include <iostream>

using namespace std;

class A
{
	private:
		int x;
		int &y;
		int *z;
		const int k;

	public:
		A(int xx, int yy, int *zz,int kk=0):k(kk),y(yy)	// Constructor
		{
			cout<<"Constructor invoked"<<endl;
			cout<<xx<<" "<<yy<<" "<<zz<<" "<<kk<<endl;
		}
		
		A(const A &ref):k(ref.k),y(ref.y)
		{
			cout<<"copy constructor"<<endl;
			x = ref.x;
			z = ref.z;
		}

		A& operator= (const A &ref)
		{
			cout<<"overloaded assignment operator"<<endl;
			if (this == &ref)
				return *this;
			this->x = ref.x;
			this->y = ref.y;
			//this->k = ref.k;
			this->z = ref.z;
			return *this;
		}
};

int main(int argc, char **argv)
{
	int xx=10, yy=20, zz=35;
	A obj(xx, yy, &zz, 45);
	A obj1(xx, yy, &zz);
	A obj2(obj1);
	A obj3(xx, yy, &zz);
	obj3 = obj1;

	return 0;
}
