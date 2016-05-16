#include <iostream>
#include <vector>
#include <cstring> 
#include <stdexcept> 

using namespace std;

namespace mine{
    template <typename T>
    class Array {
        public:
            Array();
            ~Array();
            void append(T element);

            //get the item from the particular index
            T operator[](int index) const; //reader
            T& operator[](int index); //writer


            //overload the = operator
            T& operator=(T& element);

            typename vector<T>::iterator getbegin();
            typename vector<T>::iterator getend();

            friend ostream& operator<<(ostream &out, Array<T> &arr)
            {
                typename vector<T>::iterator it;
                for(it = arr.getbegin(); it != arr.getend(); ++it)
                    cout<<*it<<" ";
                return out;
            }

        private:
            vector<T> v;
    };
}
using namespace mine;

template <typename T>
Array<T>::Array()
{
    cout<<this<<" : Array object created"<<endl;
}

template <typename T>
Array<T>::~Array()
{
    cout<<this<<" : Array object destructed"<<endl;
}

template <typename T>
void Array<T>::append(T element)
{
    v.push_back(element);
}

template <typename T>
typename vector<T>::iterator Array<T>::getbegin()
{
    return v.begin();
}

template <typename T>
typename vector<T>::iterator Array<T>::getend()
{
    return v.end();
}

// for reading purpose
template <typename T>
T Array<T>::operator[](int index) const
{
    if (index >= v.size())
        throw out_of_range("Beyond the size of array");
    return v[index];
}

// for writing purpose
template <typename T>
T& Array<T>::operator[](int index)
{
    #if 0
    if(index + 1 == v.size())
        v.push_back("");
    else if (index >= v.size())
        throw out_of_range("Beyond the size of array");
    #endif
    if (index >= v.size())
        throw out_of_range("Beyond the size of array");
    return v[index];
}


template <typename T>
T& Array<T>::operator=(T &element)
{
    cout<<"Assignment operator overloaded"<<endl;
}

int main()
{
//    cout<<"Enter to my new program"<<endl;
    mine::Array<int> arr;
    arr.append(12);
    arr.append(13);
    cout<<arr<<endl;

    mine::Array<string> sarr;
    sarr.append("Hello");
    sarr.append("Hi");
    cout<<sarr<<endl;

    try {
        cout<<"item : "<<sarr[1]<<endl;
    }catch(out_of_range &oor) {
        cout<<"Out of range : "<<oor.what()<<endl;
    }
    sarr[1] = "Helllllo";
    sarr[2] = "Helllllo";
    cout<<sarr<<endl;

    return 0;
}
