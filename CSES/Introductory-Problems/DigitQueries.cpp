#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
long long int pow(int exp){
   long int ans = 1;
   long int base = 10;
   while(exp){
      if(exp&1){
         ans = ans*base;
      }
      base = base*base;
      exp/=2;
   }
   return ans;
}
 
int findDigit(long long int k){
   long long int base=9;
   int numDigit=1;
   long long int currNums = 0;
   while(k>(base*numDigit)){
      k -= base*numDigit;
      currNums += base;
      base *= 10;
      numDigit++;
   }
   long long int toAdd = k/numDigit;
   if(k%numDigit != 0){
      toAdd++;
   }
   long long int finalNum = currNums + toAdd;
   int digitIndex = (k-1)%numDigit;
   long long int div = pow(numDigit-digitIndex-1);
   finalNum = finalNum/div;
   return finalNum%10;
}
 
 
int main(){
   int q;
   cin >> q;
   long long int k;
   while(q--){
      cin >> k;
      cout << findDigit(k) << endl;
   }
}