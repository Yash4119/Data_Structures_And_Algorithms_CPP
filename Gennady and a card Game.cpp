#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	cin>>s;

	vector<string>v(5);

	for(int i=0;i<5;i++){
		cin>>v[i];
	}

	int flag=0;

	for(int i=0;i<5;i++){
		if(s[0]==v[i].at(0))flag=1;
	}

	if(!flag){
		for(int i=0;i<5;i++){
		if(s[1]==v[i].at(1))flag=1;
		}
	}

	if(flag){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
}