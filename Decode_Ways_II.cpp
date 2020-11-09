/*A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.*/


class Solution {
public:
    vector<long long int> dp;
    int M = 1000000007;
    int dfs(string s,int index){
        if(s.size() == index) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] > 0) return dp[index]%M;
        int temp = 0;
        if(s[index] == '*'){
            for(int i = 1 ; i <= 9 ; i++){
                temp = (temp%M + dfs(s,index + 1))%M;
                int num = i;
                if(index + 1 < s.size()){
                    if(index + 1 < s.size() and s[index + 1] == '*'){
                        for(int j = 1 ; j <= 9 ; j++){
                            num = i * 10 + j;
                            if(num <= 26) temp = (temp%M + dfs(s,index + 2))%M;
                        }
                    } else {
                        num = i * 10 + int(s[index + 1]) - 48;
                        if(num <= 26) temp = (temp%M + dfs(s,index + 2))%M;
                    }
                }
            }
        } else {
            temp = (temp%M + dfs(s,index + 1))%M;
            int num = int(s[index]) - 48;
            if(index + 1 < s.size()){
                if(s[index + 1] == '*'){
                    for(int j = 1 ; j <= 9 ; j++){
                        int x = num * 10 + j;
                        if(x <= 26) temp = (temp%M + dfs(s,index + 2))%M;
                    }
                } else {
                    num = num * 10 + int(s[index + 1]) - 48;
                    if(num <= 26) temp = (temp%M + dfs(s,index + 2))%M;
                }
            }
        }
        return dp[index] = temp%M;
    }
    int numDecodings(string s) {
        dp.resize(s.size(),0);
        return dfs(s,0)%M;
    }
};
