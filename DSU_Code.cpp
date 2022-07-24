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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	DSU dsu(n+1);

	int m;
	while(m--)

	if(dsu.find_parent(3) == dsu.find_parent(2)){
		cout<<"Success"<<endl;
	}
	
}