/*Given a string s, partition s such that every substring of the partition is a palindrome

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.*/


class Solution {
public:
    int minCut(string s) {
         int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};



/////////////////////////////////////////////////////////////////////////InterviewBit AC Solution //////////////////////////////////
int Solution::minCut(string s) {
    vector<int> dp(s.size(),0);
        for(int i = 0 ; i < s.size() ; i++){
            string t1 = "",t2 = "";
            int count = 0;
            for(int j = i ; j >= 0 ; j--){
                t1 = t1 + s[j];
                t2 = s[j] + t2;
                if(t1 == t2)
                    count = j;
            }
            if(count == 0)
                dp[i] = 0;
            else
                dp[i] = min(dp[count - 1] + 1,dp[i - 1] + 1);
        }
        return dp[s.size() - 1];
}

