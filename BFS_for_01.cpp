#include<bits/stdc++.h>

using namespace std;

void BFS_for_01(int src_node){

	deque<pair<int,int>>dq;
	vector<int>dis(n,0);

	for(int i=0;i<n;i++){
		dis[i] = INT_MAX;
	}

	dq.push_front({src_node,0});
	dis[source] = 0;

	while(!dq.empty()){
		int node = dq.front().first;
		int dist = dq.front().second;
		dq.pop();

		for(auto it:adj[node]){
			int adjNode = it.first;
			int wt = it.second;

			if(dist+wt < dis[adjNode]){
				dis[adjNode] = dist+wt;
				if(dist == 1){
					dq.push_back({adjNode , dist+wt});
				}
				else{
					dq.push_front({adjNode , dist+wt});
				}
			}

		}

	}


}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	
}