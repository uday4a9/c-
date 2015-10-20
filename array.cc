#include <iostream>
#include <stdexcept>

using namespace std;


class Array
{
	public:
		Array(int sz=5)
		{
			if(sz<0)
				throw invalid_argument("Array size should be greter than zero");
			else
				size = sz;
			ptr = new int[size];
			for(int i=0;i<size;i++)
				ptr[i]=0;
		}

		~Array()
		{
			delete []ptr;
		}

		friend ostream& operator<<(ostream &op, const Array &ar)
		{
			for(int i=0;i<ar.size;i++)
				op<<ar.ptr[i]<<" ";
			return op;
		}

		friend istream& operator>>(istream &ip, Array &ar)
		{
			cout<<"Enter "<<ar.size<<" Elements : ";
			for(int i=0;i<ar.size;i++)
				ip>>ar.ptr[i];
		}

		Array(const Array &ar) : size(ar.size)
		{
			cout<<"Copy constructor"<<endl;
			ptr = new int[size];
			// copy constructor
			for(int i=0;i<ar.size;i++)
				ptr[i]=ar.ptr[i];
		}

		const Array& operator=(const Array &right)
		{
			cout<<"overloaded addignement operator"<<endl;
			if(&right != this)
			{
				if(size != right.size)
				{
					delete []ptr;
					size = right.size;
					ptr = new int[right.size];
				}
				for(int i=0;i<right.size;i++)
					ptr[i]=right.ptr[i];	
			}
			return *this;
		}

		bool operator==(const Array &right)
		{
			if(size != right.size)
				return false;
			for(int i=0;i<size;i++)
				if(ptr[i] != right.ptr[i])
					return false;
			return true;
		}

		int operator[](int pos)
		{	
			if(pos<0 || pos>=size)
				throw out_of_range("Index Out Of Range");
			return ptr[pos];
		}

	private:
		int size;
		int *ptr;
};



int main(int argc, char **argv)
{
	Array a;
	cin>>a;
	cout<<"The array a elements are : "<<a<<endl;
	const Array b;
	b = a;
	cout<<"The array b elements are : "<<b<<endl;
//	(a==b)?cout<<"TRUE\n":cout<<"FALSE"<<endl;

	cout<<"a[3] : "<<a[3]<<endl;
	
	return 0;
}
