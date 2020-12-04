/*You are given a string s containing lowercase letters and an integer k. You need to :

First, change some characters of s to other lowercase English letters.
Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
Return the minimal number of characters that you need to change to divide the string.

 

Example 1:

Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
Example 2:

Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
Example 3:

Input: s = "leetcode", k = 8
Output: 0
 

Constraints:

1 <= k <= s.length <= 100.
s only contains lowercase English letters.*/


class Solution {
public:
    int dp[101][101];
    int count(string &s,int start,int end){
        int ans = 0;
        while(start < end){
            if(s[start] != s[end]) ans++;
            start++;
            end--;
        }
        return ans;
    }
    int dfs(string &s,int k,int index){
        if(index >= s.size()) return 100000;
        if(k == 1) return count(s,index,s.size() - 1);
        if(dp[index][k] != -1) return dp[index][k];
        int temp = INT_MAX;
        for(int i = index ; i < s.size() ; i++){
            temp = min(temp,dfs(s,k - 1,i + 1) + count(s,index,i));
        }
        return dp[index][k] = temp;
    }
    int palindromePartition(string &s, int &k) {
        if(s.size() == k) return 0;
        memset(dp,-1,sizeof(dp));
        return dfs(s,k,0);
    }
};
