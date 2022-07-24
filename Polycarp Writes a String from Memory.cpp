#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;cin>>t;
	while(t--){

		string s;
		cin>>s;

		int sz=0;
		unordered_map<char,int>mp;

		int n = s.size();
		int i=0;
		int ans=0;
		while(i<n){
			
			// cout<<s[i]<<" "<<st.size()<<endl;
			if(mp.find(s[i])==mp.end())sz++;
			mp[s[i]]++;
			while(i+1<n and mp.find(s[i+1])!=mp.end())i++;
			i++;
			if(sz==3){
				ans++;
				sz=0;
				mp.clear();
			}
		}
		if(sz>0){
			// cout<<"entered ";
			ans++;
		}
		cout<<ans<<endl;

	}

}