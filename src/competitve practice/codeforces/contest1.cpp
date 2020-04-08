#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, s, k;
    vector<int> closed;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> s >> k;
        int floor;
        for (int j = 0; j < k; j++)
        {
            cin >> floor;
            closed.push_back(floor);
        }
        int steps = 0;
        int current = s;
        while (true)
        {
            if (std::find(closed.begin, closed.end, current))
            {
            }
        }
    }
    return 0;
}