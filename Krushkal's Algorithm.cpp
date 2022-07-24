#include<bits/stdc++.h>

using namespace std;

class DSU{
private:
	vector<int>parent,size;

public:
	DSU(int n){
		for(int i=0;i<=n;i++){
			parent.push_back(i);
			size.push_back(1);
		}
	}
	
	int find_parent(int node){
		if(parent[node] == node){
			return node;
		}

		return parent[node] = find_parent(parent[node]);
	}

	void union_01(int x, int y){
		int px = find_parent(x);
		int py = find_parent(y);

		if(px == py){
			return;
		}

		if(size[px] < size[py]){
			parent[px] = py;
			size[py] += size[px];
		}
		else{
			parent[py] = px;
			size[px] += size[py];
		}
	}
};

struct Node1{
public:
	int u,v,wt;

	Node1(int _u , int _v, int _wt){
		u = _u;
		v = _v;
		wt = _wt;
	}
};

bool comp(Node1 first , Node1 second){
	if(first.wt < second.wt)return true;

	return false;
}

void Krushkals(int n, vector<Node1>&edges){
	sort(edges.begin(),edges.end(), comp);

	DSU dsu(n);
	int cost = 0;

	for(auto it:edges){
		int u = it.u;
		int v = it.v;
		int wt = it.wt;

		if(dsu.find_parent(u) != dsu.find_parent(v)){
			dsu.union_01(u,v);
			cost += wt;
		}
	}
	cout<<"cost of the minimum spanning tree is :- "<<cost<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	// This is the code for Krushkal's Algorithm for finding the Minimum Spanning Tree
	int n;
	cin>>n;
	cout<<n;
	// vector<Node1>edges(n);

	// for(int i=0;i<n;i++){
	// 	int u,v,wt;
	// 	cin>>u>>v>>wt;

	// 	edges[i].(u,v,wt);
	// }

	// Krushkals(n,edges);	

	return 0;
}