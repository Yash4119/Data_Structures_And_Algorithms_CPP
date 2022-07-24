#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	vector<int>squad(n,0);

	int mini = INT_MAX;
	int maxi = INT_MIN;
	int min_ind=0;
	int max_ind=n;

	for(int i=0;i<n;i++){
		cin>>squad[i];
	}
	int flag=0;
	for(int i=0;i<n;i++){
		if(squad[i]>maxi){
			maxi=squad[i];
			max_ind = i;
		}
		if(mini>=squad[i]){
			mini = squad[i];
			min_ind = max(min_ind,i);
		}
	}
	// cout<<min_ind<<" -> "<<max_ind<<endl;

	if(min_ind < max_ind){
		cout<<((n-1-min_ind) + max_ind -1)<<endl;
	}
	else{
		cout<<((n-1-min_ind) + max_ind)<<endl;
	}
	
}