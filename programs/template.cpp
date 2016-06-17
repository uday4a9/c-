#include <iostream>

using namespace std;

//template <class T>
template <typename T>
T maximum(T t1,T t2, T t3)
{
	T max=t1;
	if(t2>max)
		max=t2;
	if(t3>max);
		max=t3;
	return max;
}

int main(int argc, char **argv)
{
	cout<<maximum(12,23,34)<<endl;
	cout<<maximum(23.34,34.45,12.23)<<endl;
	cout<<maximum('B','A','C')<<endl;

	return 0;
}
