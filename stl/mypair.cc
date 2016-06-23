#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> MyintVec;

#if 1
class MyPair{
    private:
        pair<int, int> p;
    public:
        MyPair(int first, int second)
        {
            p = make_pair(first, second);
        }

        friend ostream& operator<<(ostream &op, MyPair &mp)
        {
            op<<mp.p.first<<" "<<mp.p.second<<endl;
            return op;
        }
};
#else
typedef pair<int, int> MyPair;
#endif

int main(int argc, char **argv)
{
    MyintVec vec1, vec2;

    for(int i=0; i<6; ++i){
        vec1.push_back(i+12); vec2.push_back(i+23); 
    }
    vec2.pop_back();

    cout<<vec2[5]<<endl;

    MyPair mp(vec1[5], vec2[5]);
//    cout<<mp.first<<" "<<mp.second<<endl;;
    cout<<mp;;

    return 0;
}
