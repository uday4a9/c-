#include <iostream>

using namespace std;

class abs_cls
{
	public:
		virtual void foo() = 0;
		void fun()
		{
			cout<<"You called fun function"<<endl;
		}
};

int main(int argc, char **argv)
{
	cout<<"Size is : "<<sizeof(abs_cls)<<endl;

	return 0;
}
