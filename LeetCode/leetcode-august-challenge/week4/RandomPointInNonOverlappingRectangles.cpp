#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> points;
    vector<vector<int>> rects;
    Solution(vector<vector<int>> &rects)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        srand(time(0));
        this->rects = rects;
        int pts = 0;
        for (vector<int> r : rects)
        {
            pts += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            //cout<<"PTS:"<<pts<<endl;
            points.push_back(pts);
        }
    }

    vector<int> pick()
    {
        int numPts = points.back();
        int rectPts = rand() % numPts;
        // Can use a binary search instead of a linear search
        int i;
        for (i = 0; i < points.size(); i++)
        {
            if (points[i] > rectPts)
            {
                break;
            }
        }
        int x1 = rects[i][0];
        int y1 = rects[i][1];
        int x2 = rects[i][2];
        int y2 = rects[i][3];
        int addPts;
        if (i == 0)
        {
            addPts = rectPts;
        }
        else
        {
            addPts = rectPts - points[i - 1];
        }
        //cout<<"ADDPTS:"<<addPts<<endl;
        return {x1 + addPts % (x2 - x1 + 1), y1 + addPts / (x2 - x1 + 1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

class Solution
{
public:
    vector<int> points;
    vector<vector<int>> rects;
    Solution(vector<vector<int>> &rects)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        srand(time(0));
        this->rects = rects;
        int pts = 0;
        for (vector<int> r : rects)
        {
            pts += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            //cout<<"PTS:"<<pts<<endl;
            points.push_back(pts);
        }
    }

    vector<int> pick()
    {
        int numPts = points.back();
        int rectPts = 1 + rand() % numPts;
        // Can use a binary search instead of a linear search
        int i = lower_bound(points.begin(), points.end(), rectPts) - points.begin();
        // for(i=0;i<points.size();i++){
        //     if(points[i]>rectPts){
        //         break;
        //     }
        // }

        int x1 = rects[i][0];
        int y1 = rects[i][1];
        int x2 = rects[i][2];
        int y2 = rects[i][3];
        // int addPts;
        // if(i==0){
        //     addPts = rectPts;
        // }else{
        //     addPts = rectPts-points[i-1];
        // }
        //cout<<"ADDPTS:"<<addPts<<endl;
        return {x1 + rand() % (x2 - x1 + 1), y1 + rand() % (y2 - y1 + 1)};
    }
};
