#include <iostream>
#include <vector>
#include <string> 

/* This program simply takes the arguments from 
 * commandline and save it into a vector string
 */

using namespace std;

int main(int argc, char **argv)
{
    vector <string> inputs;

    cout<<"length of command line args is : "<<argc<<endl;

    for(int i=1; i < argc; ++i) {
        inputs.push_back(argv[i]);
    }

    cout<<"Contents are : ";
    for(int i=0; i < argc-1; ++i) {
        cout<<inputs[i]<<" ";
    }
    cout<<endl;

    return 0;
}
