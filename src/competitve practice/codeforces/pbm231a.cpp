#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p, v, t;
    int no_sol = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> p >> v >> t;
        if ((p == 1 && v == 1) || (v == 1 && t == 1) || (t == 1 && p == 1))
            no_sol++;
    }
    cout << no_sol << endl;
    return 0;
}