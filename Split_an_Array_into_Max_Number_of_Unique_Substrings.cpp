/*https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/submissions/*/











class Solution {
public:
    int ans = 0;
    unordered_map<string,int> M;
    void backtrack(string &s,int index,int count){
        ans = max(ans,count);
        string temp = "";
        for(int i = index ; i < s.size() ; i++){
            temp += s[i];
            if(!M[temp]){
                M[temp] = 1;
                backtrack(s,i+1,count + 1);
                M[temp] = 0;
            }
        }
    }
    int maxUniqueSplit(string s) {
        backtrack(s,0,0);
        return ans;
    }
};
