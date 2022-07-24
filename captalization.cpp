#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string name;
	cin>>name;

	if(name[0] > 90){
		name[0] = name[0]-32;
	}

	cout<<name<<endl;
	
}