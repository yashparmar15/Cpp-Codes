/*Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.*/



class Solution {
public:
    int calculate(string s) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // string s = "";
        // for(int i = 0 ; i < s1.size() ; i++){
        //     if(s1[i] != ' ')
        //         s = s + s1[i];
        // }
        // stack<pair<string,int>> stk;
        // int ans = 0;
        // for(int i = 0 ; i < s.size() ; i++){
        //     if(s[i] != ')'){
        //         if(s[i] == '(')
        //             stk.push(make_pair("(",-1));
        //         else if(s[i] == '+')
        //             stk.push(make_pair("+",-1));
        //         else if(s[i] == '-')
        //             stk.push(make_pair("-",-1));
        //         else {
        //             long int num = 0;
        //             while(i < s.size() and s[i] >= '0' and s[i] <= '9'){
        //                 num = num * 10 + int(s[i]) - 48;
        //                 i++;
        //             }
        //             i--;
        //             stk.push(make_pair("",num));
        //         }
        //     } else {
        //         bool sign = true;
        //         stack<pair<string,int>> temp;
        //         while(stk.top().first != "("){
        //             temp.push(stk.top());
        //             stk.pop();
        //         }
        //         stk.pop();
        //         ans = 0;
        //         while(!temp.empty()){
        //             if(temp.top().first == "+"){
        //                 sign = true;
        //             } else {
        //                 if(temp.top().first == "-"){
        //                     sign = false;
        //                 } else {
        //                     // cout <<ans << " "<< temp.top().second << endl;
        //                     if(sign)
        //                         ans = ans + temp.top().second;
        //                     else
        //                         ans = ans - temp.top().second;
        //                 }
        //             }
        //             temp.pop();
        //         }
        //         stk.push(make_pair("",ans));
        //     }
        // }
        // bool sign = true;
        // stack<pair<string,int>> temp;
        // while(!stk.empty() and stk.top().first != "("){
        //     temp.push(stk.top());
        //     stk.pop();
        // }
        // if(!stk.empty())
        // stk.pop();
        // ans = 0;
        // while(!temp.empty()){
        //     if(temp.top().first == "+"){
        //        sign = true;
        //     } else {
        //         if(temp.top().first == "-"){
        //             sign = false;
        //         } else {
        //             if(sign)
        //                 ans = ans + temp.top().second;
        //             else
        //                 ans = ans - temp.top().second;
        //             }
        //         }
        //         temp.pop();
        // }
        // stk.push(make_pair("",ans));
        // return stk.top().second;
        
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        stack<int> signs;
        int sign = 1;
        long int num = 0;
        int ans = 0;
        
        // always transform s into ( s )
        signs.push(1);
        
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }
        
        if (num) {
            ans = ans + signs.top() * sign * num;
        }
        
        return ans;
    }
};
