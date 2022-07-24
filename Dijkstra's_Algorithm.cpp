#include <bits/stdc++.h>

using namespace std;


void dijkstra(vector<vector<pair<int,int>>>vec, vector<int>&path, int k){
    queue<int>q;
    q.push(k);
    
    path[k] = 0;
    
    while(!q.empty()){
        int prev = q.front();
        q.pop();
        
        for(auto it : vec[prev]){
            int dist = it.second;
            int next = it.first;
            
            if(path[next] > path[prev] + dist){
                path[next] = path[prev] + dist;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj_list(n+1);
    
    // cout<<"hi"<<endl;
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj_list[u].push_back({v,wt});
        // adj_list[v].push_back({u,wt});
    }
    
    vector<int>path(n+1, INT_MAX);
    
    cout<<"Enter the source index where you start :- ";
    int src;
    cin>>src;
    cout<<endl;
    
    dijkstra(adj_list,path,src);
    
    int mini = *max_element(path.begin()+1,path.end());
    
    cout<<"Cost of the shortest path in the graph is :- "<<mini<<endl;
    
    return 0;
}
