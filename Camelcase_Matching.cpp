/*A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.*/


class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string p) {
        vector<bool> ans;
        for(int i = 0 ; i < q.size() ; i++){
            vector<vector<int>> dp;
            vector<int> t(q[i].size() + 1,0);
            for(int j = 0 ; j < p.size() + 1 ; j++)
                dp.push_back(t);
            for(int j = 1 ; j <= p.size() ; j++){
                for(int k = 1 ; k <= q[i].size() ; k++){
                    if(p[j - 1] == q[i][k - 1])
                        dp[j][k] = dp[j - 1][k - 1] + 1;
                    else
                        dp[j][k] = max(dp[j - 1][k],dp[j][k - 1]);
                }
            }
            bool flag = dp[p.size()][q[i].size()] == p.size();
            unordered_map<char,int> M;
            for(int j = 0 ; j < q[i].size() ; j++)
                M[q[i][j]]++;
            for(int j = 0 ; j < p.size() ; j++){
                M[p[j]]--;
            }
            for(auto m : M){
                if(m.second < 0)
                    flag = false;
                if(m.second > 0 and int(m.first) >= 'A' and int(m.first) <= 'Z')
                    flag = false;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};
