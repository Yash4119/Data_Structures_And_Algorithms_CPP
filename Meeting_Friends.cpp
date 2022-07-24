#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int x1,x2,x3;

    cin>>x1>>x2>>x3;

    int mini = min(x1,min(x2,x3));
    int maxi = max(x2,max(x2,x3));

    while(mini!=maxi){
        mini++;
        maxi--;
        count+=2;
    }
    cout<<count<<endl;
 
    return 0;
}