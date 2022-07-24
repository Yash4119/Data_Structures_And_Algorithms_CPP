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
		long long int a,b,n;
		cin>>a>>b>>n;

		int count=0;

		while(a<=n and b<=n){
			if(a<b){
				a+=b %mod;
				// cout<<b<<" ";
				count++;
			}
			else{
				b+=a %mod;
				// cout<<b<<" ";
				count++;
			}
		}

		cout<<count<<endl;

	}
	
}