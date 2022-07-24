#include<bits/stdc++.h>

using namespace std;

void build_SGT(int ind,int low,int high,int arr[],int seg[],int orr){
	if(low == high){
		seg[ind] = arr[low];
		return;
	}

	int mid = low + (high-low)/2;
	build_SGT(2*ind+1,low,mid,arr,seg,!orr);
	build_SGT(2*ind+2,mid+1,high,arr,seg,!orr);

	if(orr){
		seg[ind] = seg[2*ind+1] | seg[2*ind+2];
	}
	else{
		seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
	}
}

void update(int ind,int low,int high,int seg[],int orr,int i,int val){
	if(low == high){
		seg[ind] = val;
		return;
	}

	int mid = low+(high-low)/2;
	if(i<=mid){
		update(2*ind+1,low,mid,seg,!orr,i,val);
	}
	else{
		update(2*ind+2,mid+1,high,seg,!orr,i,val);
	}

	if(orr){
		seg[ind] = seg[2*ind+1] | seg[2*ind+2];
	}
	else{
		seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,q;
	cin>>n>>q;

	int el = 2<<(n-1);
	// cout<<el<<endl;
	int arr[el];
	int seg[4*el+1];

	for(int i=0;i<el;i++){
		cin>>arr[i];
	}

	if(n%2==0){
		build_SGT(0,0,el-1,arr,seg,0);
	}
	else{
		build_SGT(0,0,el-1,arr,seg,1);
	}

	while(q--){
		int i,val;
		cin>>i>>val;
		// in question , for queries we do have 1 based indexing so wen need to decrement i by 1
		i--;
		// cout<<i<<val<<endl;
		if(n%2==0){
			update(0,0,el-1,seg,0,i,val);
			// cout<<seg[i]<<endl;
		}
		else{
			update(0,0,el-1,seg,1,i,val);
			// cout<<seg[i]<<endl;
		}
		cout<<seg[0]<<endl;
	}

	return 0;
}