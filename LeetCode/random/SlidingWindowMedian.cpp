#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> result;
        Ordered_set s;
        int n = nums.size();
        for (int i = 0; i < k; i++)
            s.insert(nums[i]);

        if (k & 1)
        {

            // Value at index k/2
            // in sorted list.
            double ans = *s.find_by_order(k / 2);
            result.push_back(ans);

            for (int i = 0; i < n - k; i++)
            {

                // Erasing Element out of window.
                s.erase(s.find_by_order(
                    s.order_of_key(
                        nums[i])));

                // Inserting newer element
                // to the window
                s.insert(nums[i + k]);

                // Value at index k/2 in
                // sorted list.
                ans = *s.find_by_order(k / 2);
                result.push_back(ans);
            }
        }
        else
        {

            // Getting the two middle
            // median of sorted list.
            double ans = ((double)*s.find_by_order(
                              (k + 1) / 2 - 1) +
                          (double)*s.find_by_order(k / 2)) /
                         2;
            result.push_back(ans);

            for (int i = 0; i < n - k; i++)
            {
                s.erase(s.find_by_order(
                    s.order_of_key(nums[i])));

                s.insert(nums[i + k]);

                ans = ((double)*s.find_by_order(
                           (k + 1) / 2 - 1) +
                       (double)*s.find_by_order(k / 2)) /
                      2;
                result.push_back(ans);
            }
        }
        return result;
    }
};