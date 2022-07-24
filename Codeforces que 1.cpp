#include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;cin>>t;

	while(t--){
		long long int a;long long int b;
		cin>>a>>b;

		b = (b*2)%mod;

		int s = (a+b)%mod;

		if(a==0){
			cout<<1<<endl;
		}
		else{
			cout<<s+1<<endl;
		}

	}
	

	return 0;
}