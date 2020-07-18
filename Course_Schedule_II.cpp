/*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.*/




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
    vector<int> findOrder(int n, vector<vector<int>>& p) {
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
            return {};
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
            return {};
        vector<int> res;
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }
};
