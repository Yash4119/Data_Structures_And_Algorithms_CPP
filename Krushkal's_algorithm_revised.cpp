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

struct Node{
public:
    int u;
    int v;
    int wt;
    Node(int _u, int _v, int _wt){
        u = _u;
    v = _v;
    wt = _wt;
    }
    
};

bool comp(Node n1, Node n2){
    return n1.wt < n2.wt;
}

int main(){
    
// 	Now we will code for the krushkal's algorithm

    int N,m;
    cin>>N>>m;
    
    vector<Node>edges;
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        
        edges.push_back(Node(u,v,wt));
    }
    
    sort(edges.begin(),edges.end(),comp);
    
    DSU dsu(N+1);
    
    int tot_cost = 0;
    
    vector<pair<int,int>>mst;
    for(auto it : edges){
        if(dsu.find_par(it.u) != dsu.find_par(it.v)){
            tot_cost += it.wt;
            mst.push_back({it.u,it.v});
            dsu.Union_set(it.u,it.v);
        }
    }
    
    cout<<"Total cost of the mst is :- "<<tot_cost<<endl;
 
    return 0;
}