/*You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
 

Constraints:

0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.*/



class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        for(int i = 0 ; i < s.size() ; i++){
            if(isalpha(s[i])){
                string temp = "";
                while(i < s.size() and isalpha(s[i])){
                    temp = temp + s[i];
                    i++;
                }
                i--;
                stk.push(temp);
            } else {
                if(s[i] == '(')
                    stk.push("(");
                else{
                    string temp = "";
                    while(stk.top() != "("){
                        temp = stk.top() + temp;
                        stk.pop();
                    }   
                    reverse(temp.begin(),temp.end());
                    stk.pop();
                    stk.push(temp);
                }
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
