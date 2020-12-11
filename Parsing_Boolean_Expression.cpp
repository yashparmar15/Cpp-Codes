/*Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false
 

Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.*/


class Solution {
public:
    bool parseBoolExpr(string &s) {
        stack<char> exp;
        stack<int> val;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '&' or s[i] == '!' or s[i] == '|')
                exp.push(s[i]);
            else {
                if(s[i] == '(') val.push(-1);
                if(s[i] == ',') continue;
                if(s[i] == 't') val.push(1);
                if(s[i] == 'f') val.push(0);
                if(s[i] == ')'){
                    if(exp.top() == '!'){
                        int num = val.top();
                        val.pop();
                        num = num == 1 ? 0 : 1;
                        val.pop();
                        val.push(num);
                        exp.pop();
                        continue;
                    }
                    int num = -1;
                    while(val.top() != -1){
                        if(num == -1) num = val.top();
                        else {
                            if(exp.top() == '&') num = num * val.top();
                            else num = num + val.top();
                        }
                        val.pop();
                    }
                    val.pop();
                    val.push(num);
                    exp.pop();
                }
            }
        }
        return val.top();
    }
};
