#include<bits/stdc++.h>

using namespace std;

void DFS_Graph(int node, vector<int>&visited, vector<int>&storeDFS, vector<int>adj[]){
        storeDFS.push_back(node);
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                
                DFS_Graph(it,visited,storeDFS,adj);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>storeDFS;
        vector<int>visited(V+1,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS_Graph(i,visited,storeDFS,adj);
            }
        }
        return storeDFS;
    }

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
}