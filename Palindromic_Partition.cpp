/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]*/


class Solution {
public:
    void backtrack(vector<vector<string>> &ans,vector<string> &temp,string &s,int index){
        int n = s.size();
        if(index == n)
            ans.push_back(temp);
        else{
            for(int i = index ; i < n ; i++){
                if(palindrome(s,index,i)){
                    temp.push_back(s.substr(index,i - index + 1));
                    backtrack(ans,temp,s,i + 1);
                    temp.pop_back();
                }
            }
        }
    }
    bool palindrome(string &s,int l,int r){
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(ans,temp,s,0);
        return ans;
    }
};
