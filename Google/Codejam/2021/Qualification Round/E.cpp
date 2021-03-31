#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()

int people = 100;
int ques = 10000;

void solve()
{
    vector<string> arr(people);
    vector<int> quesDiff(ques, 0);
    for (int i = 0; i < 100; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < ques; j++)
        {
            if (arr[i][j] == '1')
            {
                quesDiff[j]++;
            }
        }
    }
    vector<array<int, 2>> quesWithInd(ques);
    for (int i = 0; i < ques; i++)
    {
        quesWithInd[i] = {quesDiff[i], i};
    }

    // sort in increasing order of difficulty of questions
    sort(quesWithInd.begin(), quesWithInd.end());
    reverse(all(quesWithInd));

    //deal with how many questions a person solved
    vector<int> level(people);
    for (int q = 0; q < ques; q++)
    {
        int currQues = quesWithInd[q][1];
        for (int p = 0; p < people; p++)
        {
            if (arr[p][currQues] == '1')
            {
                level[p]++;
            }
        }
    }

    reverse(all(quesWithInd));
    //deal with how many difficult questions a person solved
    vector<double> difficult(people);
    for (int q = 0; q < ques / 10; q++)
    {
        int currQues = quesWithInd[q][1];
        for (int p = 0; p < people; p++)
        {
            if (arr[p][currQues] == '1')
            {
                difficult[p] += 1;
            }
        }
    }

    vector<array<int, 2>> a(people);
    for (int p = 0; p < people; p++)
    {
        a[p] = {level[p], p};
    }

    //make people of same level near to each other
    sort(a.begin(), a.end());

    double maxDiff = INT_MIN;
    int cheater = 0;

    for (int p = 0; p < people; p++)
    {
        int curr = a[p][1];
        int left = a[p == 0 ? 1 : p - 1][1];
        double diff;
        if (p != 0 && p != people - 1)
        {
            int right = a[p + 1][1];
            // calculate the difference considering the neighbours into account
            diff = difficult[curr] - (difficult[left] + difficult[right]) / 2;
        }
        else
        {
            diff = difficult[curr] - difficult[left];
        }
        if (diff > maxDiff)
        {
            maxDiff = diff;
            cheater = curr;
        }
    }
    cout << cheater + 1 << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    int P;
    cin >> T >> P;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}