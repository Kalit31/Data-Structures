#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(){
   long int n;
   cin >> n;
 
   for (long int i=1;i<=n;i++){
        /*
            Total possible ways - [(2*3) + (3*2) rectangles]*2
        */
        long int ans = (((i*i)*(i*i-1))/2) - 4*(i-1)*(i-2);
        cout << ans << endl; 
   }
}