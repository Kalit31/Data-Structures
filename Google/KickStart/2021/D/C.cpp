#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 2>> ps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i][0] >> ps[i][1];
    }
    vector<ll> s(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }

    set<array<ll, 2>> start;
    set<array<ll, 2>> end;

    for (int i = 0; i < n; i++)
    {
        start.insert({ps[i][0], ps[i][1]});
        end.insert({ps[i][1], ps[i][0]});
    }

    vector<ll> result;

    for (int i = 0; i < m; i++)
    {
        ll skill = s[i];
        //if skill is the start of some interval
        auto startIt = start.find({skill, skill});
        if (startIt != start.end())
        {
            result.push_back((*startIt)[0]);
            array<ll, 2> curr = *startIt;

            //find the same interval in 'end' set
            auto endIt = end.find({curr[1], curr[0]});

            start.erase(startIt);
            end.erase(endIt);

            curr[0] = curr[0] + 1;
            if (curr[0] <= curr[1])
            {
                start.insert(curr);
                end.insert({curr[1], curr[0]});
            }
            continue;
        }

        //if skill is the end of some interval
        auto endIt = end.find({skill, skill});
        if (endIt != end.end())
        {
            result.push_back((*endIt)[0]);
            array<ll, 2> curr = *endIt;

            //find the same interval in 'start' set
            auto startIt = start.find({curr[1], curr[0]});

            start.erase(startIt);
            end.erase(endIt);

            curr[0] = curr[0] - 1;
            if (curr[0] >= curr[1])
            {
                end.insert(curr);
                start.insert({curr[1], curr[0]});
            }
            continue;
        }

        //if skill lies within some interval
        auto it0 = start.lower_bound({skill, skill});
        if (it0 != start.begin())
        {
            --it0;
            array<ll, 2> curr = *it0;
            if (curr[0] < skill && skill < curr[1])
            {
                //found the skill
                result.push_back(skill);

                //split the interval
                auto itE = end.find({curr[1], curr[0]});

                start.erase(it0);
                end.erase(itE);

                if (curr[0] <= (skill - 1))
                {
                    start.insert({curr[0], skill - 1});
                    end.insert({skill - 1, curr[0]});
                }
                if (skill + 1 <= curr[1])
                {
                    start.insert({skill + 1, curr[1]});
                    end.insert({curr[1], skill + 1});
                }

                continue;
            }
        }

        auto it1 = end.lower_bound({skill, skill});
        auto it2 = start.upper_bound({skill, skill});

        ll diff1 = LONG_LONG_MAX;
        if (it1 != end.begin())
        {
            --it1;
            array<ll, 2> curr1 = *it1;
            diff1 = skill - curr1[0];
        }

        ll diff2 = LONG_LONG_MAX;
        if (it2 != start.end())
        {
            array<ll, 2> curr2 = *it2;
            diff2 = curr2[0] - skill;
        }

        if (diff1 <= diff2)
        {
            array<ll, 2> curr1 = *it1;
            result.push_back(curr1[0]);

            //find the same interval in 'start'
            auto startIt = start.find({curr1[1], curr1[0]});
            //deb(skill);

            //cout << (*startIt)[0] << " - " << (*startIt)[1] << endl;
            start.erase(startIt);
            end.erase(it1);

            curr1[0] = curr1[0] - 1;
            //cout << curr1[0] << " - " << curr1[1] << endl;
            if (curr1[0] >= curr1[1])
            {
                end.insert(curr1);
                start.insert({curr1[1], curr1[0]});
            }
        }
        else
        {
            array<ll, 2> curr2 = *it2;
            result.push_back(curr2[0]);
            //find the same interval in 'end' set

            auto endIt = end.find({curr2[1], curr2[0]});

            start.erase(it2);
            end.erase(endIt);

            curr2[0] = curr2[0] + 1;
            if (curr2[0] <= curr2[1])
            {
                start.insert(curr2);
                end.insert({curr2[1], curr2[0]});
            }
        }
    }

    for (ll x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}