#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

typedef std::map<char, int> MyMap;
typedef std::pair<string, double> Pair;
typedef std::vector<Pair> MyVec;

int main()
{
    MyMap map;
    string str;
    MyVec vecpair;

    Pair p1("Uday", 67.33);
    Pair p2("Ram", 68.00);

    vecpair.push_back(p1);
    vecpair.push_back(p2);

    cin>>str;

    for(string::iterator it=str.begin();
            it != str.end();
            ++it)
        map[*it]++;

    for(MyMap::iterator it=map.begin();
            it != map.end();
            ++it)
        cout<<it->first<<" => "<<it->second<<endl;

    for(MyVec::iterator it=vecpair.begin();
            it != vecpair.end();
            ++it)
        cout<<(*it).first<<" <=> "<<(*it).second<<endl;

    cout<<"Pair p1 : "<<p1.first<<" and "<<p1.second<<endl;
    
    return 0;
}
