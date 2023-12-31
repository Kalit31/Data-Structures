#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(){
    int n;
    cin >> n;
    int xor_sum = 0;
    for (int i=1;i<n;i++){
        int x;
        cin >> x;
        xor_sum = xor_sum^x;
    }
    int total_xor_sum = 0;
    for (int i=1;i<=n;i++){
        total_xor_sum = total_xor_sum^i;
    }
    cout << (xor_sum^total_xor_sum) << endl;
}
 
 
/*
 
  1  001
  2  010
  3  011
  4  100
 
     100 
 
  1  001
  2  010
  3  011
     000   
*/