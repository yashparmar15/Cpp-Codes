/*Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".*/


class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            string temp1 = "" ; string temp2 = "";
            for(int j = i ; j < s.size() ; j++){
                temp1 = temp1 + s[j];
                temp2 = s[j] + temp2;
                if(temp1 == temp2)
                    ans++;
            }
        }
        return ans;
    }
};
