#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		long long int n;cin>>n;

		int k=0;

		while(pow(10,k) <= n){
			k++;
		}
		k--;
		long long int ans = n - pow(10,k);
		cout<<ans<<endl;

	}
}