#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &nums, int l, int mid, int r)
    {
        int nl = mid - l + 1;
        int nr = r - mid;
        vector<int> left(nl);
        vector<int> right(nr);

        for (int i = 0; i < nl; i++)
        {
            left[i] = nums[l + i];
        }
        for (int i = 0; i < nr; i++)
        {
            right[i] = nums[mid + 1 + i];
        }

        int ans = 0;
        int i = 0;
        int j = 0;

        for (i = 0; i < nl; i++)
        {
            while (j < nr && (long long)left[i] > 2LL * right[j])
            {
                j++;
            }
            ans += (j);
        }
        i = 0;
        j = 0;

        int k = l;
        while (i < nl && j < nr)
        {
            if (left[i] <= right[j])
            {
                nums[k] = left[i];
                k++;
                i++;
            }
            else
            {
                nums[k] = right[j];
                k++;
                j++;
            }
        }

        while (i < nl)
        {
            nums[k] = left[i];
            k++;
            i++;
        }
        while (j < nr)
        {
            nums[k] = right[j];
            k++;
            j++;
        }
        return ans;
    }

    int merge_sort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int ans = 0;
        ans += merge_sort(nums, l, mid);
        ans += merge_sort(nums, mid + 1, r);
        ans += merge(nums, l, mid, r);
        return ans;
    }

    int reversePairs(vector<int> &nums)
    {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};