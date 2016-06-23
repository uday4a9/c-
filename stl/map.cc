#include <iostream>
#include <map>
#include <cassert> 
#include <string> 
#include <iterator> 


using namespace std;
/* find the oocureneces of each character
 * in a given string
 */

// typedef a new map contains both char and int as pair
typedef map<char, int> Mymap;

int main(int argc, char **argv)
{
    Mymap counter;
    string::iterator it;

    assert(argc == 2);
    string str = argv[1];

    for(string::iterator it=str.begin();
        it != str.end(); ++it) {
        counter[*it]++;
    }

    for(Mymap::iterator it = counter.begin();
                        it != counter.end();
                        ++it)
        cout<<it->first<<" => "<<it->second<<endl;
    
    char c = 'z';
    Mymap::iterator it1 = counter.find(c);
    if(it1 == counter.end())
        cout<<"Character not found"<<endl;

    for(Mymap::iterator it = counter.begin();
                        it != counter.end();
                        ++it)
        cout<<it->first<<" => "<<it->second<<endl;
    return 0;
}
