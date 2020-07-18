/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
Accepted*/



class Solution {
public:
    void dfs(vector<int> &visited , stack<int> &ans , vector<vector<int>> &v,int index,bool &t,int prev,unordered_map<int,int> M){
        if(!visited[index]){
            visited[index] = 1;
            for(int i = 0 ; i < v[index].size() ; i++){
                if(v[index][i] == prev)
                    t = true;
                if(M[v[index][i]])
                    t=true;
                M[v[index][i]] = 1;
                if(!visited[v[index][i]])
                dfs(visited,ans,v,v[index][i],t,index,M);
                M[v[index][i]] = 0;
            }
            ans.push(index);
        }
            
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> v;
        for(int i = 0 ; i < n ; i++){
            vector<int> temp;
            v.push_back(temp);
        }
        for(int i = 0 ; i < p.size() ; i++){
            v[p[i][1]].push_back(p[i][0]);
        }
        vector<int> visited(n,0);
        stack<int> ans;
        bool flag = true;
        for(int i = 0 ; i < n ; i++){
            if(v[i].size() == 0)
                flag = false;
        }
        if(flag)
            return false;
        bool t = false;
        unordered_map<int,int> M;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                M[i] = 1;
                dfs(visited,ans,v,i,t,i,M);
                M[i] = 0;
            }
        }
        if(t)
            return false;
        return 1;
    }
};
