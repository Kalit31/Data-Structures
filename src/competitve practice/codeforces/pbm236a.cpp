#include <iostream>

using namespace std;

int main()
{

    string str;
    cin >> str;
    char letters[26] = {0};
    int cnt = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (letters[str[i] - 97] == 0)
        {
            letters[str[i] - 97] = 1;
            cnt++;
        }
    }
    cnt % 2 == 0 ? cout << "CHAT WITH HER!" << endl : cout << "IGNORE HIM!" << endl;

    return 0;
}