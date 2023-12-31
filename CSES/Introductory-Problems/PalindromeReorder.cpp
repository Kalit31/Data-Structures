#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
int main(){
   string s;
   cin >> s;
   int len = s.size();
   vector<int> freq(26,0);
   for (int i=0;i<len;i++){
      freq[s[i]-'A']++;
   }
   int oddChar = -1;   
   if(len&1){
      // 1 char with odd freq, rest even
      for(int i=0;i<26;i++){
         if(freq[i]&1){
            if(oddChar != -1){
               cout << "NO SOLUTION" << endl;
               return 0;
            }
            oddChar = i;
         }
      }
      if (oddChar == -1){
         cout << "NO SOLUTION" << endl;
         return 0;
      }
   }else{
      // all char with even freq
      for(int i=0;i<26;i++){
         if(freq[i]&1){
            cout << "NO SOLUTION" << endl;
            return 0;
         }
      }
   }
   for(int i=0;i<26;i++){
      for (int j=0;j<freq[i]/2;j++){
         cout << char('A'+i);
      }
   }
   if(len&1){
      cout << char('A'+oddChar);
   }
   for(int i=25;i>=0;i--){
      for (int j=0;j<freq[i]/2;j++){
         cout << char('A'+i);
      }
   }
   cout << endl;
}