/* Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/


class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
        return s;
    }
};
