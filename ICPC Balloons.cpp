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
		string s;
		cin>>s;

		unordered_map<char,int>mp;
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(mp.find(s[i])==mp.end()){
				ans+=2;
				mp[s[i]]++;
			}
			else{
				ans++;
			}
		}
		cout<<ans<<endl;
	}

}