#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	cin>>s;

	vector<char>vec;

	for(int i=0;i<s.size();i++){
		if(s[i]=='+'){
			continue;
		}
		vec.push_back(s[i]);
	}	

	sort(vec.begin(),vec.end());
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+'){
			continue;
		}
		s[i] = vec[j++];
	}	

	cout<<s<<endl;
		
}