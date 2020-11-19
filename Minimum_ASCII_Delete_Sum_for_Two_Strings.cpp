/*Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].*/


class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string &s1,string &s2,int i1,int i2){
        if(i1 == s1.size()){
            int count = 0;
            for(int i = i2 ; i < s2.size() ; i++)
                count += int(s2[i]);
            return count;
        }
        if(i2 == s2.size()){
            int count = 0;
            for(int i = i1 ; i < s1.size() ; i++)
                count += int(s1[i]);
            return count;
        }
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]) return dfs(s1,s2,i1 + 1,i2 + 1);
        int temp = min(dfs(s1,s2,i1 + 1,i2) + int(s1[i1]),dfs(s1,s2,i1,i2 + 1) + int(s2[i2]));
        return dp[i1][i2] = temp;
    }
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size(),vector<int>(s2.size(),-1));
        return dfs(s1,s2,0,0);
    }
};
