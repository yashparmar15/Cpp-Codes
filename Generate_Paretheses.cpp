// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
public:
    void recur(int c1 , int c2 , vector<string> &ans , string s , int n){
        if(s.size() == 2 * n){
            ans.push_back(s);
        }
        if(c1 < n){
            s = s + "(";
            recur(c1 + 1,c2,ans,s,n);
            s.pop_back();
        }
        if(c2 < n and c2 < c1){
            s = s + ")";
            recur(c1,c2 + 1,ans,s,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        if(n == 1)
            return {"()"};
        vector<string> ans;
        string s = "(";
        int c1 = 1;
        int c2 = 0;
        recur(c1,c2,ans,s,n);
        return ans;
    }
};