#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    long long m, n, a;

    cin >> m >> n >> a;

    long long x = ceil((1.0 * m) / a);
    long long y = ceil((1.0 * n) / a);

    cout << x * y << endl;

    return 0;
}