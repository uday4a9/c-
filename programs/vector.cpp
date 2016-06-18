#include <iostream>
#include <vector>

using namespace std;

void opvector(const vector< int > &);
void ipvector(vector< int > &);
void display(vector< int > &);

int main(int argc, char **argv)
{
	vector< int > a(10);
	vector< int > b(12);

	cout<<"SZ : "<<a.size()<<endl;
	opvector(a);
	cout<<"SZ : "<<b.size()<<endl;
	ipvector(a);
	display(a);

	return 0;
}

void opvector(const vector< int > &a)
{
//	cout<<"SZOF : "<<sizeof(a)<<endl;
	for(int i=0;i<a.size();i++) {
		cout<<a[i]<<" ";
	}	
	cout<<endl;
}

void ipvector(vector< int > &a)
{
	for(int i=0; i<a.size() && cin>>a[i];i++);
}

void display(vector< int > &a)
{
	for(int i=0; i<a.size() && cout<<a[i]<<" "; i++);
	cout<<endl;
//	cout<<a.at(11)<<endl;
}
