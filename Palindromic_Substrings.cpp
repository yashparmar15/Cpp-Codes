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










class Solution {
public:
   int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
        }
        return res;
    }
};
