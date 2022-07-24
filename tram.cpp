#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;
	cin>>n;

	vector<pair<int,int>>tram(n,{0,0});

	for(int i=0;i<n;i++){
		cin>>tram[i].first;
		cin>>tram[i].second;
	}

	int maxi = -1e9;
	int cap=0;
	for(int i=0;i<n;i++){
		
		cap -= tram[i].first;
		cap += tram[i].second;

		maxi = max(maxi,cap);
	}
	cout<<maxi;
}