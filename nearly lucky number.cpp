#include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	long long int n;
	cin>>n;

	int count=0;
	while(n>0){
		int rem = n%10;
		if(rem==4 || rem==7){
			count++;
		}
		n/=10;
	}

	if(count==4 || count==7){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

}