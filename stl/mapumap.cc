#include <iostream>
#include <map>  
#include <vector>
#include <string>

using namespace std;

typedef map<string, vector<int> > Mapv;

template <typename T>
void printvector(vector <T> &ref)
{
    typename vector<T>::iterator it;
    int i = 0;
    cout<<"["; 
    for(it=ref.begin(); it != ref.end(); ++it, ++i)
        (i) ? (cout<<" "<<*it<<",") : (cout<<*it<<",");
    (i) ? (cout<<"\b]"<<endl) : (cout<<"]"<<endl);
}

//template <typename T>
//void printmap(map<T> &ref)
//{
//    typename vector<T>::iterator it;
//    int i = 0;
//    cout<<"["; 
//    for(it=ref.begin(); it != ref.end(); ++it, ++i)
//        (i) ? (cout<<" "<<*it<<",") : (cout<<*it<<",");
//    (i) ? (cout<<"\b]"<<endl) : (cout<<"]"<<endl);
//}

int main(int argc, char **argv)
{
    Mapv m1;
    vector<int> v1;
    vector<string> sv;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    printvector(v1);

    sv.push_back("Hello");
    sv.push_back("hi");
    sv.push_back("how");
    printvector(sv);

    m1["Hello"].push_back(20); 
    m1["Hello"].push_back(30); 
    m1["Hello"].push_back(40); 
    m1["Hi"].push_back(20); 
    m1["asd"];
    m1["ad"] = v1;
    m1["sd"];

    for(Mapv::iterator it = m1.begin();
                       it != m1.end();
                       ++it) {
        cout<<it->first<<" => ";
        printvector(it->second); 
    }

    return 0;
}
