#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,m;
	cin>>n>>m;

	vector<vector<char>>snake(n,vector<char>(m,'#'));

	int flag=0;

	for(int row=0;row<n;row++){
		if(row%2 and flag==0){
			for(int i=0;i<m-1;i++){
				snake[row][i] = '.';
			}
			flag=1;
		}
		else if(row%2 and flag==1){
			for(int i=1;i<m;i++){
				snake[row][i] = '.';
			}
			flag=0;
		}
		else{
			continue;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<snake[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}