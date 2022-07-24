#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<long long int>v(n,0);

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int c=1;
	int maxi = INT_MIN;
	for(int i=0;i<n-1;i++){
		if(v[i]<v[i+1])c++;
		else if(v[i]>=v[i+1]){
			maxi = max(maxi,c);
			c=1;
		}
	}
	maxi = max(c,maxi);
	cout<<maxi<<endl;
	
}