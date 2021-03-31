#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
public:
    map<pair<string, string>, int> totTime;
    map<pair<string, string>, int> cnt;
    map<int, pair<string, int>> startStation;

    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        startStation[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        pair<string, int> curr = startStation[id];
        totTime[{curr.first, stationName}] += t - curr.second;
        cnt[{curr.first, stationName}]++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        int time = totTime[{startStation, endStation}];
        int num = cnt[{startStation, endStation}];
        return (1.0 * time) / num;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */