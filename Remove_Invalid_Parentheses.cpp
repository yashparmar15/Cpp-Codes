/*Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]*/


class Solution {
public:
    vector<string> ans;
    int req;
    unordered_map<string,int> M;
    void dfs(string &s,int i,int open,int close,string temp){
        if(i > s.size()) return;
        if(open == close and open == req and !M[temp]){
            for(int k = i ; k < s.size() ; k++){
                if(s[k] != '(' and s[k] != ')')
                    temp += s[k];
            }
            if(!M[temp])
            ans.push_back(temp);
            M[temp]++;
            return;
        }
        for(int index = i ; index < s.size() ; index++){
            if(open == 0) {
                if(s[index] == '(')
                    dfs(s,index + 1,open + 1,close,temp + s[index]);
                else {
                    if(s[index] != ')'){
                        dfs(s,index + 1,open,close,temp + s[index]);
                        return;
                    }
                }
            } else {
                if(s[index] != '(' and s[index] != ')'){
                    dfs(s,index + 1,open,close,temp + s[index]);
                    return;
                }
                else{
                    if(s[index] == '(')
                        dfs(s,index + 1,open + 1,close,temp + s[index]);
                    else{
                        if(close + 1 <= open)
                            dfs(s,index + 1,open,close + 1,temp + s[index]);
                    }
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int open = 0,close = 0,total = 0;
        stack<char> S;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(')
                S.push(s[i]),total++;
            if(s[i] == ')'){
                if(S.empty()) close++;
                else S.pop();
                total++;
            }
        }
        while(!S.empty()){
            open++;
            S.pop();
        }
        req = (total - open - close) / 2;
        string temp = "";
        if(req == 0){
            for(int i = 0 ; i < s.size() ; i++){
                if(s[i] != '(' and s[i] != ')') temp += s[i];
            }
            ans.push_back(temp);
            return ans;
        }
        dfs(s,0,0,0,temp);
        return ans;
    }
};
