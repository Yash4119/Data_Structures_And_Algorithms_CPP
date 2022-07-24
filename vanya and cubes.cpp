#include<bits/stdc++.h>

using namespace std;

int calc(int n){
	return (n*(n+1))/2;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n1;
	cin>>n1;

	int ct=0;
	int i=1;
	while((n1 - calc(i))>=0){
		ct++;
		n1 -= calc(i++);
	}

	cout<<ct<<endl;
	
}