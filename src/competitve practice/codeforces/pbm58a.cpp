#include <iostream>
using namespace std;

int main()
{

    string hello = "hello";
    string str;
    int j = 0;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == hello[j])
        {
            j++;
            if (j == 5)
                break;
        }
    }

    j == 5 ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
