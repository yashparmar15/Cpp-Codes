/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> s;
        string word = "";
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == ' '){
                s.push_back(word);
                word = "";
            } else {
                word = word + str[i];
            }
        }
        s.push_back(word);
        if(s.size() != pattern.size())
            return 0;
        unordered_map<char,string> M1;
        unordered_map<string,char> M2;
        for(int i = 0 ; i < pattern.size() ; i++){
            if(!M1.count(pattern[i])){
                M1[pattern[i]] = s[i];
            } else {
                if(M1[pattern[i]] != s[i])
                    return 0;
            }
            if(!M2[s[i]]){
                M2[s[i]] = pattern[i];
            } else {
                if(M2[s[i]] != pattern[i])
                    return 0;
            }
        }
        return 1;
    }
};
