#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        int d = 0;
        long long temp = b;
        while (temp > 0)
        {
            temp = temp / 10;
            d++;
        }
        if (pow(10, d) - 1 == b)
            cout << a * (d) << endl;
        else
            cout << a * (d - 1) << endl;
    }
    return 0;
}