#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem
{
public:
    map<int, multiset<pair<int, int>>> moviesUnrented;
    set<array<int, 3>> moviesRented;
    map<int, map<int, int>> mp;

    int N;
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        N = n;
        for (int i = 0; i < entries.size(); i++)
        {
            moviesUnrented[entries[i][1]].insert({entries[i][2], entries[i][0]});
            mp[entries[i][0]][entries[i][1]] = entries[i][2];
        }
    }

    vector<int> search(int movie)
    {
        vector<int> result;
        int cnt = 0;
        for (auto it = moviesUnrented[movie].begin(); it != moviesUnrented[movie].end() && cnt < 5; it++)
        {
            result.push_back((*it).second);
            cnt++;
        }
        return result;
    }

    void rent(int shop, int movie)
    {
        auto it = moviesUnrented[movie].find({mp[shop][movie], shop});
        moviesRented.insert({mp[shop][movie], shop, movie});
        moviesUnrented[movie].erase(it);
    }

    void drop(int shop, int movie)
    {
        auto it = moviesRented.find({mp[shop][movie], shop, movie});
        moviesUnrented[movie].insert({mp[shop][movie], shop});
        moviesRented.erase(it);
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> result;
        int cnt = 0;
        for (auto it = moviesRented.begin(); it != moviesRented.end() && cnt < 5; it++)
        {
            result.push_back({(*it)[1], (*it)[2]});
            cnt++;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */