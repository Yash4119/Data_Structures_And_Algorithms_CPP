#include<bits/stdc++.h>

using namespace std;

class ST{
	vector<int>seg,lazy;
public:
	ST(int n){
		seg.resize(n*4);
		lazy.resize(4*n);
	}

public:
	void build(int ind, int low, int high, int arr[]){
		if(low == high){
			seg[ind] = arr[low];
			return;
		}

		int mid = low + (high-low)/2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);
		seg[ind] = min(seg[2*ind+1] , seg[2*ind+2]);
	}

	void update(int ind, int low, int high, int l , int r, int val){
		if(lazy[ind] != 0){
			seg[ind] += lazy[ind];

			if(low!=high){
			lazy[2*ind+1] += lazy[ind];
			lazy[2*ind+2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		// case for no overlap
		if(high < l or low > r){
			return;
		}

		// case for complete overlap
		if(low>=l and high<=r){
			seg[ind] += (high-low+1)*val;

			if(low!=high){
				lazy[2*ind+1] += val;
				lazy[2*ind+2] += val;
			}
			return;
		}

		// case for partial overlap
		int mid = (high+low)/2;
		update(2*ind+1, low,mid,l,r,val);
		update(2*ind+2, mid+1, high,l,r,val);
		seg[ind] = min(seg[2*ind+1] , seg[2*ind+2]);
	}

	int query(int ind, int low,int high, int l , int r){
		// check if any prev updates and propagate downwards
		if(lazy[ind] != 0){
			seg[ind] = lazy[ind];

			if(low!=high){
				lazy[2*ind+1] += lazy[ind];
				lazy[2*ind+2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		// case for no overlap
		if(high < l or low > r){
			return INT_MAX;
		}

		// case for complete overlap
		if(high <= r and low >= l){
			return seg[ind];
		}

		// case for partial overlap
		int mid = (high+low)/2;
		int left = query(2*ind+1 ,low,mid, l , r);
		int right = query(2*ind+2, mid+1, high, l ,r);
		return min(left , right);
	}
};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	// lazy propagation on Segment Trees
	//  --> Update the node when you visit it.
	// --> once you update, propagate the update downwords.

	// in lazy propagation for every node there will be a corresponding lazy node.
	// all lazy node will have initial values ==> 0

	// If complete overlap then update and propagate
	// If partial overlap then go to both directions that is left and right
	// If no overlap then return as it is.

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int q;
	cin>>q;

	ST st(n+1);
	st.build(0,0,n-1,arr);

	while(q--){
		int type;
		cin>>type;

		if(type == 1){
			int l,r;
			cin>>l>>r;
			cout<<"Range query sum is :- "<<st.query(0,0,n-1,l,r)<<endl;
			// cout<<"done"<<endl;
		}
		else{
			int l,r,val;
			cin>>l>>r>>val;
			st.update(0,0,n-1,l,r,val);
			// cout<<"ok"<<endl;
		}
	}
	cout<<"successfully done"<<endl;
	return 0;
}