#include<bits/stdc++.h>
using namespace std;
 


int main()
{
    vector<int>arr{2,3,1,3,3,4,5};

    if(equal_partition(7,arr)){
        cout<<"Is Possible"<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }
 
    return 0;
}