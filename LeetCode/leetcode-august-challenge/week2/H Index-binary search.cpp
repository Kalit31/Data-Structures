#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size()==0) {
            return 0;
        }
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int low = 0;
        int high = n-1;
        while (low<=high) {
            int mid = low+(high-low)/2;
            if (citations[mid]==(n-mid)) {
                return citations[mid];
            }
            else if (citations[mid]>(n-mid)) {
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        return n-low;
    }
};