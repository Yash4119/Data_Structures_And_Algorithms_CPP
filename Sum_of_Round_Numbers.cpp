#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;cin>>t;
	vector<int>arr(t,0);
	for(int i=0;i<t;i++){
	    int numi;
		cin>>numi;
		arr[i] = numi;
	}
	int i1=0;
	while(i1<t){
		vector<int>ans;
        int j=0;
        int key = arr[i1];
		while(key>0){
			int rem = key%10;

			if(rem!=0){
				int num = pow(10,j)*rem;
				ans.push_back(num);
			}

            j++;
			key /= 10;
		}

			cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;

		i1++;

	}
	return 0;
}