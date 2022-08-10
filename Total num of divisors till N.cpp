#include<bits/stdc++.h>
using namespace std;

int main(){

   #ifndef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
  #endif

       //Your Code
       int n;
       cin>>n;

       int ans=0;

       vector<int>primes = {2,3,5,7,11,13,17,19,23,29};
       int m = primes.size();

       for(int i=1;i<(1<<m);i++){

       		int num = i;
       		int ct = 0;
       		int lcm = 1;
       		while(num>0){
       			if(num & 1){
       				lcm *= primes[ct];
       				// cout<<primes[ct]<<" ";
       			}
       			ct++;
       			num >>= 1;
       		}

       		if(__builtin_popcount(i) % 2 ==0){
       			ans -= (n/lcm);
       		}
       		else{
       			ans += (n/lcm);
       		}

       }
       cout<<"Total no of integers divisible by 1st "<<m<<" prime numbers in the range 0 -> "<<n<<" are = "<<ans<<endl;

  #ifndef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif

   return 0;
}