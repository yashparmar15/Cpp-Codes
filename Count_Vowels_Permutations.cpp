/*Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4
*/


class Solution {
public:
    int M = 1000000007;
    int dp[20001][5];
    long long int dfs(int n,int prev){
        if(n == 0) return 1;
        if(dp[n][prev]) return dp[n][prev];
        long long int sum = 0;
        if(prev == 0)
            sum += dfs(n - 1,1);
        if(prev == 1)
            sum += dfs(n - 1,0) + dfs(n - 1,2);
        if(prev == 2)
            sum += dfs(n - 1,0) + dfs(n - 1,1) + dfs(n - 1,3) + dfs(n - 1,4);
        if(prev == 3)
            sum += dfs(n - 1,2) + dfs(n - 1,4);
        if(prev == 4)
            sum += dfs(n - 1,0);
        return dp[n][prev] = sum % M;
    }
    int countVowelPermutation(int n) {
        return (dfs(n - 1,0) + dfs(n - 1,1) + dfs(n - 1,2) + dfs(n - 1,3) + dfs(n - 1,4)) % M;
    }
};
