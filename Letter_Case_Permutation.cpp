// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]

class Solution {
public:
    void recur(string S , vector<string> &ans , int count){
        if(count == S.size()){
            ans.push_back(S);
            return;
        }
        recur(S,ans,count + 1);
        if(isalpha(S[count])){
            if (S[count]>='a' && S[count]<='z')  
            S[count] = S[count] - 32; 
        else
            S[count] = S[count] + 32; 
            recur(S,ans,count + 1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        recur(S,ans,0);
        return ans;
    }
};