#include<bits/stdc++.h>

using namespace std;

class heap{
public:
	int arr[100];
	int size;

	heap(){
		arr[0] = -1;
		size = 0;
	}

	void insert(int val){
		size += 1;
		int index = size;
		arr[index] = val;

		while(index > 1){
			int parent = index/2;

			// This a function for insertion in the Max Heap
			if(arr[parent] < arr[index]){
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else{
				return;
			}
		}
	}

	void display_heap(){
		for(int i = 1 ; i<=size ; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	void heapify(int i){
		int largest = i;
		int lh = 2*i;
		int rh = 2*i+1;

		if(lh<=size and arr[lh] > arr[largest]){
			largest = lh;
		}
		if(rh<=size and arr[rh] > arr[largest]){
			largest = rh;
		}

		if(largest!=i){
			swap(arr[i] , arr[largest]);

			heapify(largest);
		}
	}

	void pop(){
		if(size == 0){
			cout<<"Heap empty"<<endl;
			return;
		}

		swap(arr[1],arr[size]);
		size--;

		for(int i=(size/2)-1 ; i>=1 ; i--){
			heapify(i);
		}

	}
	

};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	heap h1;

	h1.insert(40);
	h1.insert(30);
	h1.insert(60);
	h1.insert(20);
	h1.insert(50);

	h1.display_heap();

	h1.pop();

	h1.display_heap();

	



}