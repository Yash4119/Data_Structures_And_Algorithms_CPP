#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int>rings(n,0);
		for(int i=0;i<n;i++)cin>>rings[i];

		for(int i=0;i<n;i++){
			int sz;cin>>sz;
			for(int j=0;j<sz;j++){
				char temp;
				cin>>temp;
				// cout<<rings[i]<<" "<<temp<<" ";
				if(temp=='D' and rings[i]==9){
					rings[i] = 0;
				}
				else if(temp == 'D'){
					rings[i] = 1+rings[i];
				}
				else if(temp=='U' and rings[i]==0){
					rings[i] = 9;
				}
				else{
					rings[i]--;
				}
				// cout<<rings[i]<<endl;
			}
		}
		for(int i=0;i<n;i++)cout<<rings[i]<<" ";
		cout<<endl;
	}
	
}