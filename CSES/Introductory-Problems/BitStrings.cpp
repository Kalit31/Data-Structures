#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
long int powMod(long int base, long int exp){
   long int ans = 1;
   while(exp){
      if(exp & 1){
         ans = (ans*base)%mod;
      }
      base = (base*base)%mod;
      exp /= 2;
   }
   return ans;
}
 
int main(){
   long int n;
   cin >> n;
   cout << powMod(2, n) << endl;
}