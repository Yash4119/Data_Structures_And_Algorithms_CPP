#include<bits/stdc++.h>

using namespace std;


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;cin>>n;
	int flag=0;
	vector<int>v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]==1)flag=1;
	}

	if(flag==1){
		cout<<"HARD"<<endl;
	}
	else{
		cout<<"EASY"<<endl;
	}
	
}