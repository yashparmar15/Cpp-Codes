/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]*/


class Solution {
public:
    void recur(vector<string> v , string temp,vector<string> &ans , int index,string s){
        if(index == s.size()){
            string t = "";
            for(int i = 0 ; i < temp.size() ; i++){
                if(temp[i] != ' ')
                    t = t + temp[i];
            }
            if(t == s){
                temp.pop_back();
                ans.push_back(temp);
            }
            return;
        }
        for(int i = 0 ; i < v.size() ; i++){
            bool check = true;
            if(v[i][0] == s[index]){
                for(int j = 0 ; j < v[i].size() ; j++){
                    if(j + index >= s.size())
                    {check = false;break;}
                    if(v[i][j] != s[j + index]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    recur(v,temp + v[i] + " ",ans,index + v[i].size(),s);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp = "";
        vector<int> H(26,0);
        for(int i = 0 ; i < s.size() ; i++){
            H[int(s[i]) - 97]++;
        }
        vector<int> h(26,0);
        for(int i = 0 ; i < wordDict.size() ; i++){
            for(int j = 0 ; j < wordDict[i].size() ; j++){
                h[int(wordDict[i][j]) - 97]++;
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            if(H[i] > 0 and h[i] == 0)
                return ans;
        }
        for(int i = 0 ; i < s.size() ; i++){
            recur(wordDict,temp,ans,i,s);
        }
        return ans;
    }
};
