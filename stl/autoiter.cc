#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> v;
    map<int, int> mymap;


    for(int i=0; i<5; ++i)
        v.push_back(i+23);

    for(int i=0; i<5; ++i)
        cout<<v[i]<<" ";
    cout<<endl;

    for(auto &i : v)
        cout<<i<<" ";
    cout<<endl;

    for(auto &i:string("hello"))
        mymap[i]++;

    for(auto &it:mymap)
        cout<<(char)it.first<<"=>"<<it.second<<endl;

    return 0;
}
