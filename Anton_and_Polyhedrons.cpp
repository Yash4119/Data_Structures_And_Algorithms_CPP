#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;cin>>t;

	vector<string>v;

	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		v.push_back(s);
	}

	int te=4,oc=8,cu=6,dod=12,ico=20;
	int tot_face=0;

	for(int i=0;i<t;i++){
		if(v[i] == "Tetrahedron")tot_face+=te;
		else if(v[i] == "Octahedron")tot_face+=oc;
		else if(v[i] == "Cube")tot_face+=cu;
		else if(v[i] == "Dodecahedron")tot_face+=dod;
		else if(v[i] == "Icosahedron")tot_face+=ico;
	}

	cout<<tot_face<<endl;

}