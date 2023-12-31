#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(){
    int t;
    cin>>t;
    while(t){
        long int r,c;
        cin >> r >> c;
        long int max_num = max(r, c);
        long int ans = (max_num-1)*(max_num-1);
        if (r>=c){
            if(r%2==0){
                ans += r+r-c;
            }else{
                ans += c;
            }
        }else{
            if(c%2==0){
                ans += r;
            }else{
                ans += c+c-r;
            }
        }
        cout << ans << endl;
        t--;
    }
}