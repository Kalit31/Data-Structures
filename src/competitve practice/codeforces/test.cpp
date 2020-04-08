#include <iostream>
// #include <stdafx.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A = {1, 3, 2, 4};

    sort(A.begin(), A.end()); //O(NlogN)

    bool present = binary_search(A.begin(), A.end(), 5);
    cout << present << endl;

    A.push_back(5);

    //lower_bound  &&  upper_bound
    // count of number = itr(upper_bound)-itr(lower_bound)

    return 0;
}

void setDemo(){
    set<int> S;
    S.insert(1);
    S.insert(1);
    S.insert(1);
    S.insert(1);
}