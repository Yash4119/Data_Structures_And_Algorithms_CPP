#include<bits/stdc++.h>

using namespace std;

int main(){

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	
	// Codeforces Round #804(Div 2)
	// Problem No One
	// Title :- The Third Three Number Problem

	int t;cin>>t;

	while(t--){
		long long int n;cin>>n;
		int flag = true;
		if(n<3){
			cout<<"-1"<<endl;
		}
		else{
			for(long long int a=0;a<=n;a++){
				for(long long int b=0;b<=n;b++){
					for(long long int c=0;c<=n;c++){
						if((a^b)+(a^c)+(b^c)==n){
							cout<<a<<" "<<b<<" "<<c<<endl;
							flag=false;
						}
						if(!flag)break;
					}
					if(!flag)break;
				}
				if(!flag)break;
			}
			if(flag){
			cout<<"-1"<<endl;
			}
		}

	}

}