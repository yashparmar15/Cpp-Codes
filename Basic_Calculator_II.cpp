/*Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.*/


class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<string> stk;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' ')
                continue;
            if(s[i] == '*'  or s[i] == '/'){
                char op = s[i];
                string a = stk.top();
                stk.pop();
                int num = 0;
                for(int j = 0 ; j < a.size() ; j++){
                    num = num*10 + int(a[j]) - 48;
                }
                int j = i + 1;
                int b = 0;
                while(j < s.size() and s[j] == ' ')
                    j++;
                for(; j < s.size() and s[j] >= '0' and s[j] <= '9' ; j++){
                    if(s[j] == ' ')
                        continue;
                    b = b * 10 + int(s[j]) - 48;
                }
                if(op == '*')
                    stk.push(to_string(num * b));
                else
                    stk.push(to_string(num / b));
                i = j - 1;
            } else {
                if(s[i] == '+' or s[i] == '-'){
                    if(s[i] == '+')
                        stk.push("+");
                    else
                        stk.push("-");
                    continue;
                }
                long int n = 0;
                int j = i;
                while(j < s.size() and s[j] == ' ')
                    j++;
                for(; j < s.size() and s[j] >= '0' and s[j] <= '9' ; j++){
                    if(s[j] == ' ')
                        continue;
                    n = n * 10 + int(s[j]) - 48;
                }
                i = j - 1;
                stk.push(to_string(n));
            }
        }
        stack<string> temp;
        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }
        bool sign = true;
        while(!temp.empty()){
            string a = temp.top();
            if(a == "+" or a == "-"){
                if(a == "+")
                    sign = true;
                else
                    sign = false;
            } else {
                long int n = 0;
                for(int i = 0 ; i < a.size() ; i++){
                    n = n * 10 + int(a[i]) - 48;
                }
                if(sign)
                    ans = ans + n;
                else
                    ans = ans - n;
            }
            temp.pop();
        }
        return ans;
    }
};
