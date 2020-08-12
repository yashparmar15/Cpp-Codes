/*Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.*/



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> M;
        for(int i = 0 ; i < strs.size() ; i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            M[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto m : M){
            ans.push_back(m.second);
        }
        return ans;
    }
};
