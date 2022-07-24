#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;

		vector<int>routes(n,0);
		for(int i=0;i<n;i++){
			cin>>routes[i];
		}
		// for(int i=0;i<n;i++)cout<<routes[i]<<" ";
			// cout<<endl;
		int k=0;
		while(k<q){
			int u,v;
			cin>>u>>v;
			
			int ind1=0,ind2=0;
			for(int i=0;i<n;i++){
				if(routes[i]==u and ind1==0)ind1=i+1;
				else if(routes[i]==v){
					ind2 = i+1;
					// break;
				}
			}

			if(ind1==0 or ind2==0){
				cout<<"NO"<<endl;
			}
			else if(ind1>ind2){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}

			k++;
		}

	}

}