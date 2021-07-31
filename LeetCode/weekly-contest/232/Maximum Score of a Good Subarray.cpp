#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = nums[k];
        int ptr1 = k - 1;
        int ptr2 = k + 1;
        int i = k;
        int j = k;
        int currMin = nums[k];

        while (ptr1 >= 0 && ptr2 < n)
        {
            if (nums[ptr1] >= nums[ptr2])
            {
                currMin = min(currMin, nums[ptr1]);
                i = ptr1;
                ans = max(ans, currMin * (j - i + 1));
                ptr1--;
            }
            else
            {
                currMin = min(currMin, nums[ptr2]);
                j = ptr2;
                ans = max(ans, currMin * (j - i + 1));
                ptr2++;
            }
        }

        while (ptr1 >= 0)
        {
            currMin = min(currMin, nums[ptr1]);
            i = ptr1;
            ans = max(ans, currMin * (j - i + 1));
            ptr1--;
        }

        while (ptr2 < n)
        {
            currMin = min(currMin, nums[ptr2]);
            j = ptr2;
            ans = max(ans, currMin * (j - i + 1));
            ptr2++;
        }
        return ans;
    }
};

//Monotonic Stack
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> left(n,-1);
        stack<int> st;
    
        for(int i=0;i<n;i++){
            if(st.empty()){
                left[i] = -1;
            }else if(nums[st.top()]<nums[i]){
                left[i] = st.top();
            }else{
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    left[i] = st.top();
                }
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> right(n,n);
    
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right[i] = n;
            }else if(nums[st.top()]<nums[i]){
                right[i] = st.top();
            }else{
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    right[i] = st.top();
                }
            }
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int l = left[i]+1;
            int r = right[i]-1;
            if(l<=k && k<=r){
                ans = max(ans,nums[i]*(r-l+1));
            }
        }
        
        return ans;
    }
};
