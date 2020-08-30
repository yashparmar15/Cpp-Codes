/*Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000*/


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        unordered_map<int,vector<int>> M;
        for(int i = 0 ; i < A.size() ; i++){
            for(int j = 2 ; j <= sqrt(A[i]) ; j++){
                if(A[i] % j == 0){
                    M[j].push_back(A[i]);
                    if(j != A[i] / j)
                        M[A[i] / j].push_back(A[i]);
                }
            }
            M[A[i]].push_back(A[i]);
        }
        unordered_map<int,int> vis;
        int maxlen = 0;
        for(auto m : M){
            if(m.second.size() > maxlen)
                maxlen = m.second.size();
        }
        int ans = 0;
        for(auto m : M){
            if(m.second.size() != 1 and m.second.size() + 3 >= maxlen){
                vis.clear();
                for(auto x : m.second)
                    vis[x] = 1;
                int tc = 2;
                while(tc--)
                    for(auto m : M){
                        if(m.second.size() != 1){
                            bool check = false;
                            if(1){
                                for(auto x : m.second)
                                    if(vis.find(x) != vis.end()){
                                        check = true;
                                        break;
                                    }
                                if(check)
                                    for(auto x : m.second)
                                        if(vis.find(x) == vis.end())
                                            vis[x] = 1;
                            }
                        }
                    }
                if(vis.size() > ans)
                    ans = vis.size();
            }
            
        }
        return ans;
    }
};
