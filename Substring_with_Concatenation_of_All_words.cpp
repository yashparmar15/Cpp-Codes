/*You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

 

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []*/



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.size() == 0 or words.size() == 0)
            return {};
        vector<int> ans;
        int size = words.size() * words[0].size();
        unordered_map<string,int> M,t;
        unordered_map<char,int> starting,ending;
        for(int i = 0 ; i < words.size() ; i++){
            M[words[i]]++;
            t[words[i]]++;
            starting[words[i][0]]++;
            ending[words[i][words[i].size() - 1]]++;
        }
        for(int i = 0 ; i < s.size() - size + 1 ; i++){
            if(starting.find(s[i]) != starting.end() and ending.find(s[i + size - 1]) != ending.end()){
                int count = 0;
                for(int j = i ; j < i + size ; j += words[0].size()){
                    string temp = s.substr(j,words[0].size());
                    if(M.find(temp) == M.end())
                        break;
                    else{
                        M[temp]--;
                        if(M[temp] >= 0)
                            count++;
                        else 
                            break;
                    }
                }
                if(count == words.size()){
                    ans.push_back(i);
                }
                for(auto x : t)
                    M[x.first] = x.second;
            }
        }
        return ans;
    }
};
