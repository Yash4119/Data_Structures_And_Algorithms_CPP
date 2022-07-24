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

		int ct=0;
		int temp=0;
		int i=0;
		while(i<s.size()-1){

			if(s[i]!=s[i+1]){
				ct++;
				temp=0;
				// i+=1;
			}
			i++;
		}

		 cout<<ct<<endl;

	}

	return 0;
	
}