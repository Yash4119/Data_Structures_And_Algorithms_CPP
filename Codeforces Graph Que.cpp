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

void roads_in_berland(){
	int n,m;
	cin>>n;

	m = n-1;
	DSU dsu(n+1);
	vector<pair<int,int>>extra_roads;

// Step 1:- Storage of old roads is been done in this step
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		if(dsu.find_parent(u) == dsu.find_parent(v)){
			extra_roads.push_back({u,v});
		}
		else{
			dsu.union_01(u,v);
		}
	}

// Step 2:- calculate the number of components 
	set<int>st;
	for(int i=1;i<=n;i++){
		st.insert(dsu.find_parent(i));
	}

	if(st.size() == 1){
		cout<<"0"<<endl;
		return;
	}

	int x = st.size();
	vector<int>ans(st.begin(),st.end());
	int j = 0;

	cout<<extra_roads.size()<<endl;
	for(int i=1;i<x;i++){
		cout<<extra_roads[j].first<<" "<<extra_roads[j].second<<" "<<ans[i]<<" "<<ans[i-1]<<endl;
		j++;
	}



}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	roads_in_berland();



	return 0;
}