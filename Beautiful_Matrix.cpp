#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
	
	vector<vector<int>>grid;
	int x=0;
	int y=0;
	for(int i=0;i<5;i++){
		vector<int>v(5,0);
		for(int j=0;j<5;j++){
			int n;
			cin>>n;
			if(n==1){
				x=i+1;y+=j+1;
			}
			v[j] = n;
		}
		grid.push_back(v);
	}

	int ct=0;
	bool flag = true;
	while(flag){
		if(x<3){
			x+=1;ct++;
		}
		if(x>3){
			x-=1;ct++;
		}
		if(y<3){
			y+=1;ct++;
		}
		if(y>3){
			y-=1;ct++;
		}
		if(x==3 and y==3)flag=false;
	}

	cout<<ct<<endl;
	
}