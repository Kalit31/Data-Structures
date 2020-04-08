#include <iostream>

using namespace std;

int main()
{

    int n;
    string str;

    cin >> n >> str;

    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}