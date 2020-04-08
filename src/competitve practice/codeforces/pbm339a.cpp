#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> v;

    string delimiter = "+";

    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        v.push_back(stoi(token));
        str.erase(0, pos + delimiter.length());
    }
    v.push_back(stoi(str));
    sort(v.begin(), v.end());

    vector<int>::iterator itr;

    for (itr = v.begin(); itr < v.end() - 1; itr++)
    {
        cout << *itr << "+";
    }
    cout << *itr << endl;
    return 0;
}