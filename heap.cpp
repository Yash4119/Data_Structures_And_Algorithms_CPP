#include<bits/stdc++.h>
using namespace std;
 
class heap{
    vector<int>hp;
public:
    heap(vector<int>arr){
        for(int i=0;i<arr.size();i++){
            hp.push_back(arr[i]);
        }
    }

    void heapify(int ind, int n){
        int largest = ind;
        int left = 2*ind+1;
        int right = 2*ind+2;

        if(left < n and arr[largest] <= arr[left]){
            largest = left;
        }
        if(right < n and arr[right] >= arr[largest]){
            largest = right;
        }

        if(largest != ind){
            swap(arr[largest],arr[ind]);
            heapify(largest,n);
        }
    }

    

}
 
int main()
{
    
 
    return 0;
}