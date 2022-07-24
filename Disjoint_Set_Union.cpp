#include<bits/stdc++.h>

using namespace std;

class DSU{
	vector<int>parent,rank;
	int n;
public:
	DSU(int n){
		this->n = n;
		parent.resize(n);
		rank.resize(n);
		make_set();
	}

	void make_set(){
		for(int i=0;i<n;i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find_par(int node){
		if(parent[node] != node){
			parent[node] = find_par(parent[node]);
		}

		return parent[node];
	}

	void Union_set(int u, int v){
		int pu = find_par(u);
		int pv = find_par(v);

		if(pu==pv)return;

		if(rank[pu] < rank[pv]){
			parent[pu] = pv;
		}
		else if(rank[pu] > rank[pv]){
			parent[pv] = pu;
		}
		else{
			parent[pv] = pu;
			rank[pu] += 1;
		}

	}
};

int main(){

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	
	int n;
	cin>>n;
	DSU obj(n);
    
	int m;
	cin>>m;

	while(m>0){
		int u,v;
		cin>>u>>v;

		obj.Union_set(u,v);
		m--;
	}

	bool flag = true;

	for(int i=0;i<n;i++){
		cout<<"parent of "<<i<<" is :- "<<obj.find_par(i)<<endl;
		if(obj.find_par(0) != obj.find_par(i)){
			flag = false;
		}
	}

	if(flag){
		cout<<"Graph is a Connected Graph"<<endl;
	}
	else{
		cout<<"Graph is a disconnected Graph"<<endl;
	}
 
    return 0;
}