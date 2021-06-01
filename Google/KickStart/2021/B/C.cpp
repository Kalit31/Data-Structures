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
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

const int N = 1e8 + 5;

vector<int> primes;
vector<ll> vals;

void SieveOfEratosthenes()
{
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
    ll last = 2;
    for (int i = 3; i < N; i++)
    {
        if (is_prime[i])
        {
            vals.push_back((ll)i * last);
            last = i;
        }
    }
}

bool isPrime(ll x)
{
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll z;
    cin >> z;
    ll rootZ = sqrt(z);

    ll maxGap = 300;

    //find two numbers smaller than rootZ
    vector<ll> smallPrimes;
    for (ll i = rootZ; i >= rootZ - 2 * maxGap && i >= 2; i--)
    {
        if (isPrime(i))
        {
            smallPrimes.push_back(i);
        }
        if (smallPrimes.size() == 2)
        {
            break;
        }
    }

    //find one prime larger than rootZ
    ll largerPrime;
    for (ll i = rootZ;; i++)
    {
        if (isPrime(i) && i != smallPrimes[0])
        {
            largerPrime = i;
            break;
        }
    }

    ll opt1 = smallPrimes[0] * smallPrimes[1];
    ll opt2 = smallPrimes[0] * largerPrime;

    ll ans;

    if (opt2 <= z)
    {
        ans = opt2;
    }
    else
    {
        ans = opt1;
    }

    cout << ans << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    //SieveOfEratosthenes();
    // deb(primes.size());
    // deb(primes.back());
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout << "Done in " << clock() / CLOCKS_PER_SEC << "sec" << endl;
    return 0;
}