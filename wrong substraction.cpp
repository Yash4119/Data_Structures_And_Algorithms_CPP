#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,k;
	cin>>n>>k;

	while(k--){
		int rem = n%10;

		if(rem==0){
			n = n/10;
		}
		else{
			n -=1;
		}
	}

	cout<<n<<endl;

}