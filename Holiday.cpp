#include<bits/stdc++.h>
#define ll long long
using namespace std;

// function return int which represents the size of the tree/subtree and not the ans
int dfs(int u, int parent, vector<pair<int,int>> adj[], ll& ans, int n){

	ll current_tree_size =1;

	for(auto it : adj[u]){

		int v = it.first;
		int wt = it.second;

		if(v == parent){
			continue;
		}

		ll tree_size = dfs(v,u,adj,ans,n);

		ll edge_contribution = 2 * min(tree_size, n-tree_size) * wt;
		ans += edge_contribution;

		current_tree_size += tree_size;
	}

	return current_tree_size;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	int u,v,wt;
	
	int tc = 1;
	while(tc<=t){

		int n;
		cin>>n;
		vector<pair<int,int>> adj [n+1];

		for(int i=1;i<n;i++){
			cin>>u>>v>>wt;

			adj[u].push_back({v,wt});
			adj[v].push_back({u,wt});
		}

		ll ans = 0;
		dfs(1, -1, adj, ans, n);

		cout<<"Case #"<<tc<<": "<<ans<<endl;

		tc+=1;
	}
	// cout<<"done with the problem"<<endl;
}