#include<bits/stdc++.h>

using namespace std;

int count_bits(int n){
	int c=0;

	while(n>0){
		c++;
		n/=10;
	}

	return c;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;cin>>t;

	while(t--){

		int x;cin>>x;


		int digits = count_bits(x);
		int temp = digits;

		int tot = 0;
		while(digits>0){
			tot += digits;
			digits--;
		}

		int digit = x / pow(10,temp-1);
		// cout<<digit<<endl;

		tot += ((10 * (digit-1)));

		cout<<tot<<endl;











		// int a=1;
		// int b=a;
		// int ct=0;
		// int i=1;

		// while(b!=x){

		// 	if(b>=9999){
		// 		a+=1;
		// 		b = a;
		// 		i=1;
		// 	}
		// 	ct += i;
		// 	b += (pow(10,i) * a);
		// 	i++;
			
		// }
		// ct += i;
		// cout<<ct<<endl;
	}
	
}