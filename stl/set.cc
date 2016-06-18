#include <iostream>
#include <set>
#include <algorithm> 
#include <iterator> 

using namespace std;
/* Create an integer set and copy those elements
 * to stdout using copy algorithm
 */


int main()
{
    set<int> myset;

    myset.insert(20);
    myset.insert(30);
    myset.insert(40);

    copy(myset.begin(), myset.end(),
            ostream_iterator<int> (cout, "\n"));

    pair<int, int> mypair1(10, 12);
    pair<int, int> mypair2(20, 22);
    pair<int, int> mypair3(30, 32);

    cout<<"PAIR : " << mypair1.first <<" : "<<mypair1.second<<endl;
    return 0;
}
