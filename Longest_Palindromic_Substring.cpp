/*Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),*/


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        string ans = "";
        ans += s[0];
        for(int i = 0 ; i < s.size() ; i++){
            int prev = i - 1,next = i + 1;
            while(prev >= 0 and next < s.size() and s[prev] == s[next]){
                prev--;
                next++;
            }
            // cout << prev << " " << next << endl;
            if(next - prev - 1 > ans.size())
                ans = s.substr(prev + 1,next - prev - 1);
            if(i + 1 < s.size() and s[i] == s[i + 1]){
                prev = i - 1;
                next = i + 2;
                while(prev >= 0 and next < s.size() and s[prev] == s[next]){
                    prev--;
                    next++;
                }
                if(next - prev - 1 > ans.size())
                    ans = s.substr(prev + 1,next - prev - 1);
            }
        }
        return ans;
    }
};
