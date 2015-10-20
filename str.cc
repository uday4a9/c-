#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv)
{
	string s1="Hello";
	string s2="WOrld";

	cout<<s1<<endl;

	cout<<s1+" "+s2<<endl;
	cout<<"4th character in s1 : "<<s1.at(4)<<endl;

	
	s1+=s2;
	cout<<"8th character in s1 : "<<s1.at(s1.size()-1)<<endl;

// Beyond access
	try 
	{
		cout<<"8th character in s1 : "<<s1.at(s1.size())<<endl;
	}
	catch ( out_of_range &ex )
	{
		cout<<"Accessing beyond the size : Reason : "<<ex.what()<<endl;
	}
	

	return 0;
}
