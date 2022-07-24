
#include <bits/stdc++.h>

using namespace std;

int calc(vector<int>arr, int s , int e){
    vector<int>vis(e+1,0);
    
    vis[s] = 1;
    
    queue<pair<int,int>>q;
    q.push({s,0});
    
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if(node == e){
            return steps;
        }
        
        for(int i=0;i<arr.size();i++){
            int res = node*arr[i];
            if(res <= e and !vis[res]){
                q.push({res,steps+1});
            }
        }
        
    }
    return -1;
}

int main()
{
    vector<int>arr{2,5,10};
    
    int n = calc(arr, 2 , 500);
    
    cout<<"minimum no of operations required are :- "<<n<<endl;

    return 0;
}
