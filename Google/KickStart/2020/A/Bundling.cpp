#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

struct TrieNode
{
    char val;
    int count;
    int endsHere;
    TrieNode *child[26];
};
TrieNode *root;

TrieNode *getNode(int index)
{
    TrieNode *newNode = new TrieNode;
    newNode->val = 'A' + index;
    newNode->count = newNode->endsHere = 0;
    for (int i = 0; i < 26; i++)
    {
        newNode->child[i] = NULL;
    }
    return newNode;
}

void insert(string word)
{
    TrieNode *curr = root;
    int index;
    for (int i = 0; i < word.length(); i++)
    {
        index = word[i] - 'A';
        if (curr->child[index] == NULL)
        {
            curr->child[index] = getNode(index);
        }
        curr = curr->child[index];
    }
    curr->count++;
    curr->endsHere += 1;
}

int ans = 0;
int k;
void dfs(TrieNode *curr, int level)
{
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i])
        {
            dfs(curr->child[i], level + 1);
            curr->count += curr->child[i]->count;
        }
    }
    while (curr->count >= k)
    {
        curr->count -= k;
        ans += level;
    }
}

void solve(int t)
{
    int n;
    cin >> n >> k;
    root = getNode('/' - 'A');
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s);
    }
    ans = 0;
    dfs(root, 0);
    cout << "Case #" << t << ": " << ans << endl;
}

int main()
{
    //     fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}