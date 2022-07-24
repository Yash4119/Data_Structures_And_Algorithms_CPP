#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	// Representation of Graph using an adjacency Matrix
	int n,m;
	cin>>n>>m;

	vector<vector<int>>adjacency_matrix(n+1,vector<int>(n+1,0));
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adjacency_matrix[u][v] = 1;
		adjacency_matrix[v][u] = 1;
	}
	// Display Graph
	cout<<"****** Adjecency Matrix Form ******"<<endl;
	for(int i=1;i<n+1;i++){
		cout<<"{ ";
		for(int j=0;j<n+1;j++){
			cout<<adjacency_matrix[i][j]<<" ";
		}
		cout<<"}"<<endl;
	}
	cout<<endl<<endl;

	// Display Graph
	cout<<"****** Edge Connect to Node Form ******"<<endl;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(adjacency_matrix[i][j]==1){
				cout<<"{"<<i<<" "<<j<<" }"<<endl;
			}
		}
	}
	cout<<endl<<endl;

	// Representation of Graph using an adjacency List
	int n1,m1;
	cin>>n1>>m1;

	vector<vector<int>>adjacency_list(n1+1);
	for(int i=0;i<m1;i++){
		int u,v;
		cin>>u>>v;

		adjacency_list[u].push_back(v);
		adjacency_list[v].push_back(u);
	}

	// Display Graph
	cout<<"****** Adjecency List Form ******"<<endl;
	for(int i=1;i<n1+1;i++){
		cout<<"{ ";
		for(int j=0;j<adjacency_list[i].size();j++){
			cout<<adjacency_list[i][j]<<" ";
		}
		cout<<"}"<<endl;
	}

}