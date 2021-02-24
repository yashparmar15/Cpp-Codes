/*Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50*/


class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stack;
        int cur = 0;
        for (char i : S)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
};


////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<pair<char,int>> stk;
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] == '('){
                stk.push(make_pair(S[i],1));
            } else {
                int count = 0;
                while(!stk.empty() and stk.top().first != '('){
                    count += stk.top().second;
                    stk.pop();
                }
                if(!stk.empty()){
                    stk.pop();
                    stk.push(make_pair('-',max(1,2 * count)));
                }
            }
        }
        int ans = 0;
        while(!stk.empty()){
            ans += stk.top().second;
            stk.pop();
        }
        return ans;
    }
};
