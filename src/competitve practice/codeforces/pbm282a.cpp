#include <iostream>
using namespace std;

int main()
{
    int n;
    int x = 0;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str.find("++") != string::npos)
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x << endl;
    return 0;
}