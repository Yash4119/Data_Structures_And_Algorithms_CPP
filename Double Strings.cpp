#include<bits/stdc++.h>

using namespace std;

int calc(vector<long long int>arr,long long int i,long long int j){
	if(i>=j)return 0;
	if(arr[i] <= i and i<=arr[j] and arr[j]<=j)return 1;
	
	int take =0;
	take = calc(arr,i++,j);
	int not_take=0;
	not_take = calc(arr,i,j--);

	return take+not_take;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<long long int>arr(n,0);
		for(int i=0;i<n;i++)cin>>arr[i];

		long long int i=0;long long int j=arr.size()-1;
		int ans= calc(arr,i,j);
		

		cout<<ans<<endl;
	}
}