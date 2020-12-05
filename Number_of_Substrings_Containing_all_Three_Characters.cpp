/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.*/



class Solution {
public:
    int numberOfSubstrings(string s) {
        int ch[3];
        memset(ch,0,sizeof(ch));
        int prev = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            ch[s[i] - 'a']++;
            if(ch[0] and ch[1] and ch[2]){
                while(prev < i and ch[0] and ch[1] and ch[2]){
                    ch[s[prev] - 'a']--;
                    ans += s.size() - i;
                    prev++;
                }
            }
        }
        return ans;
    }
};
