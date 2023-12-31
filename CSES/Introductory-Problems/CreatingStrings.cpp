#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define mod 1000000007;
 
void build(int len, vector<char>& str, vector<int>& freq){
   if (str.size() == len){
      for(char c:str){
         cout << c;
      }
      cout << endl;
      return;
   }
   for(int i=0;i<26;i++){
      if(freq[i]>0){
         str.push_back(char('a'+i));
         freq[i]--;
         build(len, str, freq);
         freq[i]++;
         str.pop_back();
      }
   }
   
}
 
int factorial(int n){
   int ans=1;
   while(n){
      ans = ans*n;
      n--;
   }
   return ans;
}
 
int main(){
   string s;
   cin >> s;
   int len=s.size();
   vector<int> freq(26,0);
   for (int i=0;i<len;i++){
      freq[s[i]-'a']++;
   }
   int cnt = factorial(len);
   for (int i=0;i<26;i++){
      if(freq[i]>1){
         cnt = cnt/factorial(freq[i]);
      }
   }
   vector<char> currString;
   cout << cnt << endl;
   build(len, currString, freq);
   /*
   = 5!/3! = 120/6 = 20
   */
}