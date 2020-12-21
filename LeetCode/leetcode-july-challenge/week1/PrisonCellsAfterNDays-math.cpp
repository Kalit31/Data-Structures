#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        cells = findNextDay(cells);
        vector<vector<int>> diffCells;
        int period = 0;
        bool isRepeating = false;
        int i = 2;
        for (; i <= N; i++)
        {
            cells = findNextDay(cells);
            if (find(diffCells.begin(), diffCells.end(), cells) == diffCells.end())
            {
                diffCells.push_back(cells);
                period++;
            }
            else
            {
                isRepeating = true;
                break;
            }
        }

        if (isRepeating)
        {
            cells = diffCells[(N - i) % period];
        }
        return cells;
    }

    vector<int> findNextDay(vector<int> &cells)
    {
        vector<int> nextDay(8, 0);
        for (int i = 1; i <= 6; i++)
        {
            if (cells[i - 1] == cells[i + 1])
            {
                nextDay[i] = 1;
            }
        }
        return nextDay;
    }
};

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {

        N = N % 14 == 0 ? 14 : N % 14;
        vector<int> cells2(8, 0);
        while (N > 0)
        {
            for (int i = 1; i < cells.size() - 1; i++)
            {
                cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            cells = cells2;
            N--;
        }

        return cells;
    }
};