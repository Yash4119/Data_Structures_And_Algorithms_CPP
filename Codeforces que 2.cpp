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
		int n;
		cin>>n;
 
		vector<long long int>temp(n,0);
 	long long int sum=0;
		for(int i=0;i<n;i++){
			cin>>temp[i];
			sum = (sum+temp[i])%mod;
		}
 
		if(n==1 and temp[0] > 1){
			cout<<"NO"<<endl;
		}
		else if((n==1 and temp[0] == 1) or sum&1){
			cout<<"YES"<<endl;
		}
		// else{		
		// 		sort(temp.begin(), temp.end());
		// 		long long int ans;
		
		// 		for(int i=n-2 ; i>=0;i--){
		// 			if(i==n-2){
		// 				ans = temp[i+1] - temp[i];
		// 			}
		// 			else{
		// 				ans = abs(temp[i] - ans);
		// 			}
		
		// 		}
		
		// 		if(ans==0 or ans==1){
		// 			cout<<"YES"<<endl;
		// 		}
		// 		else{
		// 			cout<<"NO"<<endl;
		// 		}
		// 	}
		else{
 
			sort(temp.begin(), temp.end());
 
			int diff = 0;
			int flag = 0;
			for(int i=n-1;i>=1;i--){
 
				if((abs(temp[i]-temp[i-1]) > 1) and temp[i-1] > 1){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
 
	}


	return 0;
	
}