/*Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.*/


class Solution {
public:
    int longestPalindromeSubseq(string a) {
        //      b   b   b   a   b
        //  b   1   1   1   1   1    
        //  a   1   1   1   2   2
        //  b   1   2   2   2   3
        //  b   1   2   3   3   3
        //  b   1   2   3   3   4
        string b = a;
        reverse(b.begin(),b.end());
        vector<vector<int>> dp;
        for(int i = 0 ; i <= a.size() ; i++){
            vector<int> temp(a.size() + 1,0);
            dp.push_back(temp);
        }
        for(int i = 1 ; i <= a.size() ; i++){
            for(int j = 1 ; j <= a.size() ; j++){
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[a.size()][b.size()];
    }
};
