/*Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].*/



class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, int col, vector<int>& color) {
        color[i] = col;
        for(auto x: graph[i]) {
            if(color[x] == color[i]) {
                return 0;
            }
            if(color[x] == 0 && !dfs(graph, x, -col, color)) {
                return 0;
            }
        }
        return 1;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        for(auto i: dislikes) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> color(N+1, 0); // 0 -> not visited, 1 -> group 1, -1 -> group 2
        for(int i=1;i<=N;i++) {
            if(color[i] == 0 && !dfs(graph, i, 1, color)) {
                return 0;
            }
        }
        return 1;
    }
};
