#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager
{
public:
    map<string, int> mp;
    int timeLive;
    AuthenticationManager(int timeToLive)
    {
        timeLive = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        mp[tokenId] = currentTime + timeLive;
    }

    void renew(string tokenId, int currentTime)
    {
        if (mp.find(tokenId) == mp.end())
            return;
        if (mp[tokenId] <= currentTime)
        {
            mp.erase(tokenId);
            return;
        }
        mp[tokenId] = currentTime + timeLive;
    }

    int countUnexpiredTokens(int currentTime)
    {
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > currentTime)
                cnt++;
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */