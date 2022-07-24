#include<bits/stdc++.h>

using namespace std;

int tin[1000005],low[1000005];
int vis[1000005];
int timer=0;

void Bridges(int node , int par){
	tin[node] = low[node] = timer++;
	vis[node] = 1;

	for(auto adjNode : adj[node]){
		if(adjNode == par){
			continue;
		}

		if(!vis[adjNode]){
			Bridges(adjNode, node);

			low[node] = mid(low[node] , low[adjNode]);
			if(low[adjNode] > tin[node]){
				cout<<adjNode<<" -> "<<node<<endl;
			}
		}
		else{
			low[node] = min(low[adjNode] , low[node]);
		}
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	




}