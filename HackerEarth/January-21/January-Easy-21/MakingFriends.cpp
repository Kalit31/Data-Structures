#include <bits/stdc++.h>
using namespace std;

/*
The idea is pretty simple, 
think of this problem in terms of bipartite graph
where children are number of nodes 
and friendship is number of edges between them
so we have to check whether a bipartite graph will be possible or not
So here if a bipartite graph is possible in this case then
1. the summation of degree of nodes of Team Red must be equal to summation of degree of nodes of Team Blue
  as they all need to have same number of friends
  
  let R be number of children from Team Red and B be number of children from Team Blue
  
  then number of friendships(sum of degrees) of Team Red = R*M
  similarly number of friendships(sum of degrees) of Team Blue = B*M
  
  if a solution is possible then
	R*M = B*M 
	R = B
	
	and we know that R + B = N
	
	R = N/2 and B = N/2;
	
	and also M <= R 
	
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;

        bool flag = 0;

        if (n % 2 == 0 && m <= n / 2 || m == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
