#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int a,b;
	cout<<"Enter Bishop's Coordinates :- ";
	cin>>a>>b;
	cout<<endl;

	int dx[] = {-1,-1,+1,+1};
	int dy[] = {-1,+1,+1,-1};

	int ct = 0;

	int x = a;
	int y = b;

	while(true){

		x += dx[0];
		y += dy[0];

		if(x>8 or x<1 or y>8 or y<1){
			break;
		}
		ct++;
	}

	x = a;
	y = b;

	while(true){

		x += dx[1];
		y += dy[1];

		if(x>8 or x<1 or y>8 or y<1){
			break;
		}
		ct++;
	}

	x = a;
	y = b;

	while(true){

		x += dx[2];
		y += dy[2];

		if(x>8 or x<1 or y>8 or y<1){
			break;
		}
		ct++;
	}

	x = a;
	y = b;

	while(true){

		x += dx[3];
		y += dy[3];

		if(x>8 or x<1 or y>8 or y<1){
			break;
		}
		ct++;
	}

	cout<<"Max :- "<<ct<<endl;
	
}