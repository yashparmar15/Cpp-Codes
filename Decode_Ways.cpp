/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).*/



class Solution {
public:
    int numDecodings(string s) {
        //  123243512
        //  1   2   3   2   4   3   5   1   2
        //  1   2   3   3   6   6   6   6   12
        if(s == "0")
            return 0;
        vector<int> dp(s.size(),0);
        for(int i = 0 ; i < s.size() ; i++){
            if(i == 0)
                if(s[i] == '0') return 0;
                else dp[i] = 1;
            else{
                if((s[i - 1] == '2' and s[i] <= '6') or s[i - 1] == '1'){
                    if(i == 1)
                        if(s[i] == '0') dp[i] = dp[i - 1];
                        else dp[i] = dp[i - 1] * 2;
                    else
                        if(s[i] == '0')
                            dp[i] = dp[i - 2];
                        else
                            dp[i] = dp[i - 1] + dp[i - 2];
                }
                else{
                    dp[i] = dp[i - 1];
                }
                if(s[i] == '0' and (s[i - 1] >= '3' or s[i - 1] == '0'))
                    return 0;
            }
            cout << dp[i] << " ";
        }
        return dp.back();
    }
};
