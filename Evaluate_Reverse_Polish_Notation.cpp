/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(tokens[i] == "+")
                    s.push(num1 + num2);
                if(tokens[i] == "-")
                    s.push(num2 - num1);
                if(tokens[i] == "*")
                    s.push(num2 * num1);
                if(tokens[i] == "/")
                    s.push(num2 / num1);
            } else {
                int num = 0;
                bool flag = true;
                int j = 0;
                if(tokens[i][0] == '-') flag = false;
                if(!flag) j = 1;
                for( ; j < tokens[i].size() ; j++)
                    num = num * 10 + int(tokens[i][j]) - 48;
                if(!flag) num = -num;
                s.push(num);
            }
        }
        return s.top();
    }
};
