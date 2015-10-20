#include <iostream>
#include <vector>
#include <string>

using namespace std;

void strinput(vector< string > &);
void stroutput(vector< string >);


int main(int argc, char **argv)
{
	vector< string > sip(5);
	string s;
	
	cout<<"Size : "<<sizeof(s)<<endl;
	cout<<"SZ : "<<s.size()<<endl;
	
//	strinput(sip);
	stroutput(sip);

	return 0;
}

void strinput(vector< string > &sip)
{
	for(int i=0; i<sip.size() && cout<<"Enter "<<i+1<<" String : " && getline(cin,sip[i]) ;i++);
}

void stroutput(vector< string > sip)
{
	for(int i=0; i<sip.size() && cout<<"string "<<i+1<<" is : "<<sip[i]<<endl; i++);
}
