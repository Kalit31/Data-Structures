#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
int main(){
   long int n;
   cin >> n;
 
   long int ans = 0;
   while(n){
      ans += n/5;
      n /= 5;   
   }
   cout << ans << endl;
}