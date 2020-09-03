/*Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].*/


class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int left = 0,right = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '*' or s[i] == '(') left++;
            else left--;
            if(s[n - i - 1] == ')' or s[n - i - 1] == '*') right++;
            else right--;
            if(left < 0 or right < 0) return false;
        }
        return true;
    }
};
