/*You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.*/


class Solution {
public:
    string temp = "";
    vector<int> indices;
    string st;
    void dfs(vector<bool> &vis,vector<vector<int>> &adj,int index){
        if(vis[index] or adj[index].size() == 0) return;
        vis[index] = 1;
        indices.push_back(index);
        temp += st[index];
        for(int i = 0 ; i < adj[index].size() ; i++)
            dfs(vis,adj,adj[index][i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.size() == 0) return s;
        st = s;
        vector<vector<int>> adj(s.size());
        vector<bool> vis(pairs.size(),false);
        for(int i = 0 ; i < pairs.size() ; i++)
            adj[pairs[i][0]].push_back(pairs[i][1]),adj[pairs[i][1]].push_back(pairs[i][0]);
        for(int i = 0 ; i < adj.size() ; i++){
            if(!vis[i] and adj[i].size()){
                indices.clear();
                temp = "";
                dfs(vis,adj,i);
                sort(temp.begin(),temp.end());
                sort(indices.begin(),indices.end());
                int flag = 0;
                for(int j = 0 ; j < indices.size() ; j++)
                    s[indices[j]] = temp[flag++];
                indices.clear();
            }
        }
        return s;
    }
};
