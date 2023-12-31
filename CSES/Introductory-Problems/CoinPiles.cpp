#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
int main(){
   int t;
   cin >> t;
   long int a, b;
   while (t--){
      cin >> a >> b;
      long int check1 = (2*a-b);
      long int check2 = (2*b-a);
      if (check1>=0 && check2>=0 && check1%3==0 && check2%3==0){
         cout << "YES" << endl;
      }else{
         cout << "NO" << endl;
      }
   }
}