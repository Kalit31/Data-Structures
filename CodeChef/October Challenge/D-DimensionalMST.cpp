#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

struct node
{
    int parent;
    int rank;
};

struct Edge
{
    int src;
    int dst;
    int wt;
};

vector<node> dsuf;
vector<Edge> mst;

//FIND operation
int find(int v)
{
    if (dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = find(dsuf[v].parent); //Path Compression
}

void union_op(int fromP, int toP)
{
    if (dsuf[fromP].rank > dsuf[toP].rank) //fromP has higher rank
        dsuf[toP].parent = fromP;
    else if (dsuf[fromP].rank < dsuf[toP].rank) //toP has higher rank
        dsuf[fromP].parent = toP;
    else
    {
        //Both have same rank and so anyone can be made as parent
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1; //Increase rank of parent
    }
}

bool comparator(Edge a, Edge b)
{
    return a.wt < b.wt;
}

void Kruskals(vector<Edge> &edge_List, int V, int E)
{
    sort(edge_List.begin(), edge_List.end(), comparator);

    int i = 0, j = 0;
    while (i < V - 1 && j < E)
    {
        int fromP = find(edge_List[j].src); //FIND absolute parent of subset
        int toP = find(edge_List[j].dst);

        if (fromP == toP)
        {
            ++j;
            continue;
        }

        //UNION operation
        union_op(fromP, toP); //UNION of 2 sets
        mst.push_back(edge_List[j]);
        ++i;
    }
}

ll calculateWeight(vector<vector<ll>> &arr, int i, int j)
{
    int D = arr[0].size();
    ll wt = 0;
    for (int d = 0; d < D; d++)
    {
        wt += abs(arr[i][d] - arr[j][d]);
    }
    return wt;
}

int main()
{
    fast;

#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    ll N, D;
    cin >> N >> D;

    dsuf.resize(N);
    for (int i = 0; i < N; ++i)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<vector<ll>> arr(N, vector<ll>(D));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<Edge> edge_List; //Adjacency list
    Edge temp;
    ll E = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            temp.src = i;
            temp.dst = j;
            temp.wt = -calculateWeight(arr, i, j);
            edge_List.push_back(temp);
            E++;
        }
    }

    Kruskals(edge_List, N, E);

    ll weight = 0;

    for (int i = 0; i < mst.size(); i++)
    {
        weight += -mst[i].wt;
    }
    cout << weight << endl;
    return 0;
}