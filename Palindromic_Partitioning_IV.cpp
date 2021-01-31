/*Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
 

Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.*/


class Solution {
public:
    int dp[2001][3];
    int check[2001][2001];
    bool ispalindrome(string &s,int start,int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    bool dfs(string &s,int index,int count){
        if(count == 3 and index == s.size()) return 1;
        if(count == 3 or index == s.size()) return 0;
        if(dp[index][count] != -1) return dp[index][count];
        bool flag = false;
        for(int i = s.size() - 1 ; i >= index ; i--){
            if(check[index][i]){
                flag = flag or dfs(s,i + 1,count + 1);
                if(flag) return true;
            }
        }
        if(flag) dp[index][count] = 1;
        else dp[index][count] = 0;
        return flag;
    }
    bool checkPartitioning(string &s) {
        memset(check,0,sizeof(check));
        for(int i = 0 ; i < s.size() ; i++){
            int start = i;
            int end = i;
            while(start >= 0 and end < s.size()){
                if(s[start] == s[end])
                    check[start][end] = 1;
                else
                    break;
                start--;
                end++;
            }
            start = i,end = i + 1;
            while(start >= 0 and end < s.size()){
                if(s[start] == s[end])
                    check[start][end] = 1;
                else
                    break;
                start--;
                end++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,0);
    }
};
