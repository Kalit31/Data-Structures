#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
int main(){
   int n;
   cin >> n;
   vector<string> result;
   result.push_back("0");
   result.push_back("1");
 
   for(int i=2;i<=n;i++){
      vector<string> update_result;
      for (int j=0;j<result.size();j++){
         update_result.push_back("0"+result[j]);
      }
      for (int j=result.size()-1;j>=0;j--){
         update_result.push_back("1"+result[j]);
      }
      result = update_result;
   }
 
   for(string s:result){
      cout << s << endl;
   }
}