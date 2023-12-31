#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(){
    /*
        5
        3 2 5 1 7
    */
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int curr_max = a[0];
    long int ans = 0;
    for (int i=1;i<n;i++){
        if (a[i]<curr_max){
            ans += (curr_max - a[i]);
        }else{
            curr_max = a[i];
        }
    }
    cout << ans << endl;
}