#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'o' || ch == 'y' || ch == 'e' || ch == 'u' || ch == 'i')
        {
            continue;
        }
        else
        {
            cout << '.' << ch;
        }
    }
    cout << endl;
    return 0;
}