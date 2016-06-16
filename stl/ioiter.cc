#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    istream_iterator<int> it(cin);
    ostream_iterator<string> ot(cout);
    ostream_iterator<int> ot1(cout);

    int num = *it;

    *ot1 = num;

    //cout<<"Number is : "<<num<<endl;

    return 0;
}
