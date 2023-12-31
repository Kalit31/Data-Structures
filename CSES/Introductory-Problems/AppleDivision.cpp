#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
int pow(int base, int exponent){
   int ans = 1;
   while(exponent){
      if(exponent & 1){
         ans = ans*base;
      }
      base = (base*base);
      exponent /= 2;
   }
   return ans;
}
 
int main(){
   int n;
   cin >> n;
   vector<long int> wts(n);
   long int totSum = 0;
   for(int i=0;i<n;i++){
      cin>>wts[i];
      totSum += wts[i];
   }
   int possibilities=pow(2,n);
   long int ans=totSum;
   for(int i=0;i<possibilities;i++){
      long int sum1=0;
      long int sum2=totSum;
      int curr=i;
      int idx=0;
      while(curr){
         if(curr&1){
            sum1 += wts[idx];
            sum2 -= wts[idx];
         }
         curr /= 2;
         idx++;
      }
      ans = min(ans,abs(sum1-sum2));
   }
   cout<<ans<<endl;
}