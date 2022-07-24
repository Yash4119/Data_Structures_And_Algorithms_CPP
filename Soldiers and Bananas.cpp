#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int k,n,w;
	cin>>k>>n>>w;

	int tot=0;
	for(int i=1;i<=w;i++){
		tot += (i*k);
	}

	if(tot<=n){
		cout<<"0"<<endl;
	}
	else{cout<<abs(tot-n)<<endl;}

}