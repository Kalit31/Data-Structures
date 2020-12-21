#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        long long int result = 0;
        for (int i = 0; i < len; i++) {
            result = result * 26 + s[i] - 'A' + 1;
        }
        return result;
    }
};