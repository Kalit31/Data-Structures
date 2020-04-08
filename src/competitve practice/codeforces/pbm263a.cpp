#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    int input;
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            cin >> input;
            if (input == 1)
                break;
        }
        if (input == 1)
            break;
    }
    cout << abs(i - 3) + abs(j - 3) << endl;

    return 0;
}