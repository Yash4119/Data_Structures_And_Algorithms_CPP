#include<bits/stdc++.h>

using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,k,l,c,d,p,nl,np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;

	int tot_drink = k*l;
	int tot_slices = c*d;

	int t_d = nl*n;
	int ts = np*n;

	cout<<min((tot_drink/t_d),min((tot_slices/n),(p/ts)));

}