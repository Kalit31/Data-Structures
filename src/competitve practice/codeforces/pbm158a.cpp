#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int scores[n];
    int no_part = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        if (scores[i] > 0 && i < k)
        {
            no_part++;
        }
    }

    if (scores[0] == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    k--;
    while (k < n && scores[k] != 0)
    {
        if (scores[k] == scores[k + 1])
        {
            no_part++;
        }
        else
        {
            break;
        }
        k++;
    }
    cout << no_part << endl;
    return 0;
}
