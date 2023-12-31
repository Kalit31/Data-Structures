#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(){
    string dna;
    cin >> dna;
    
    int len = dna.length();
    /*
    ATTCGGGA
    */
    int max_len = 1;
    char last_char = dna[0];
    int curr_len = 1;
 
    for(int i=1;i<len;i++){
        if (dna[i] == last_char){
            curr_len++;
            max_len = max(max_len, curr_len);
        }else{
            curr_len = 1;
        }
        last_char = dna[i];
    }
 
    cout << max_len << endl;
}
 
/*
    2147483647  
*/