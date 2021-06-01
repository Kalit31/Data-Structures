#include <bits/stdc++.h>
using namespace std;

//Type: Graphs, Cycle detection in Directed Graph
//Approach: It will be only possible to complete all the courses, if
//          there is no loop dependency within the courses.
//          The problem reduces to finding a cycle in graph
//Complexity: O(List of Courses)

class Solution {
public:
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited, int curr){
        //0->not visited
        //1-> visited
        //2 -> processing
        
        if(visited[curr]==2){
            return true;
        }
        visited[curr] = 2;
        for(int n: adj[curr]){
            if(visited[n]!=1){
                if(isCyclic(adj,visited,n)){
                    return true;
                }
            }
        }
        visited[curr] = 1;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0){
                if(isCyclic(adj,visited,i)){
                    return false;
                }
            }
        }
       return true;
    }
};
