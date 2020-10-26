/*Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        //      s   e   a
        //  e   0   1   1
        //  a   0   0   2
        //  t   0   0   2
        vector<vector<int>> dp(word1.size() + 1,vector<int>(word2.size() + 1,0));
        for(int i = 1 ; i <= word1.size() ; i++){
            for(int j = 1 ; j <= word2.size() ; j++){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};
