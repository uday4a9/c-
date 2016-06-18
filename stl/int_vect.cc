#include <iostream>
#include <vector>

using namespace std;

template < typename T >
void printVector(const vector < T > &vect)
{
	typename vector < T >::const_iterator ConstIter;
	for(ConstIter = vect.begin();
	    ConstIter != vect.end();
		++ConstIter)
		cout<<*ConstIter<<"\t";
	cout<<endl;
}

template < typename T>
void printrevVector(const vector < T > &vect)
{
	typename vector < T >::const_reverse_iterator ConstIter;
	for(ConstIter = vect.rbegin();
	    ConstIter != vect.rend();
		++ConstIter)
		cout<<*ConstIter<<"\t";
	cout<<endl;
}


int main(int argc, char **argv)
{
	int i;
	vector < int > v;

	v.push_back(12);
	v.push_back(23);
	v.push_back(34);
	v.push_back(45);
	v.push_back(56);

	printVector(v);
	printrevVector(v);
	return 0;
}
