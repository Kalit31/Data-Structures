#include <bits/stdc++.h>
using namespace std;

//Using merge sort(n lg n)
class Solution
{
public:
    void merge(vector<array<int, 2>> &nums, int l, int mid, int r, vector<int> &cnt)
    {
        int nl = mid - l + 1;
        int nr = r - mid;
        vector<array<int, 2>> left(nl);
        vector<array<int, 2>> right(nr);

        for (int i = 0; i < nl; i++)
        {
            left[i] = nums[l + i];
        }
        for (int i = 0; i < nr; i++)
        {
            right[i] = nums[mid + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = l;
        int eleCnt = 0;
        while (i < nl && j < nr)
        {
            if (left[i][0] <= right[j][0])
            {
                nums[k] = left[i];
                cnt[left[i][1]] += eleCnt;
                k++;
                i++;
            }
            else
            {
                nums[k] = right[j];
                eleCnt++;
                k++;
                j++;
            }
        }

        while (i < nl)
        {
            nums[k] = left[i];
            cnt[left[i][1]] += eleCnt;
            k++;
            i++;
        }
        while (j < nr)
        {
            nums[k] = right[j];
            k++;
            j++;
        }
    }

    void merge_sort(vector<array<int, 2>> &nums, int l, int r, vector<int> &cnt)
    {
        if (l >= r)
        {
            return;
        }
        int mid = l + (r - l) / 2;
        merge_sort(nums, l, mid, cnt);
        merge_sort(nums, mid + 1, r, cnt);
        merge(nums, l, mid, r, cnt);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<array<int, 2>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {nums[i], i};
        }
        vector<int> cnt(n, 0);
        merge_sort(arr, 0, n - 1, cnt);
        return cnt;
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cnt(n, 0);

        OrderedSet s;
        s.insert({nums[n - 1], n - 1});

        for (int i = n - 2; i >= 0; i--)
        {
            int idx = s.order_of_key({nums[i], i});
            cnt[i] = idx;
            s.insert({nums[i], i});
        }
        return cnt;
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cnt(n, 0);
        multiset<int> s;
        s.insert(nums[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            auto it = lower_bound(s.begin(), s.end(), nums[i]);
            if (it == s.begin())
            {
                s.insert(nums[i]);
                continue;
            }
            --it;
            //distance takes O(n)
            int dist = distance(s.begin(), it) + 1;
            cnt[i] = dist;
            s.insert(nums[i]);
        }
        return cnt;
    }
};