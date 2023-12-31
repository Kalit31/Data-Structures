#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(){
   long int n;
   cin >> n;
 
   long int sum = (n*(n+1))/2;
   if (sum%2 != 0){
        cout << "NO" << endl;
        return 0;
   }
   cout << "YES" << endl;
   
   vector<int> s1;
   vector<int> s2;
   if(n%4 == 0){
      for(int i=n;i>0;i-=4){
         s1.push_back(i);
         s1.push_back(i-3);
         s2.push_back(i-1);
         s2.push_back(i-2);
      }
   }else{
      for(int i=n;i>3;i-=4){
         s1.push_back(i);
         s1.push_back(i-3);
         s2.push_back(i-1);
         s2.push_back(i-2);
      }
      s1.push_back(1);
      s1.push_back(2);
      s2.push_back(3);
   }
   cout << s1.size() << endl;
   for(int i: s1){
      cout << i << " ";
   }
   cout << endl;
   cout << s2.size() << endl;
   for(int i: s2){
      cout << i << " ";
   }
   cout << endl;   
}