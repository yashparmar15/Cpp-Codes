/*Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.*/



class Solution {
public:
    unordered_set<string> s;
    bool dfs(string word,int count){
        if(count >= 1 and s.count(word)) return true;
        for(int i = 1 ; i < word.size() ; i++){
            string temp = word.substr(i);
            if(s.count(temp)){
                if(dfs(word.substr(0,i),count + 1))
                    return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(auto &word : words)
            if(!s.count(word)) s.insert(word);
        for(auto word : words){
            if(dfs(word,0))
                ans.push_back(word);
        }
        return ans;
    }
};
