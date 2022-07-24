#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;cin>>n;

	vector<int>v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	vector<int>ans(n,0);
	for(int i=0;i<n;i++){
		ans[v[i]-1] = i+1;
	}

	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}

}