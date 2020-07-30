/*Given a sentence that consists of some words separated by a single space, and a searchWord.

You have to check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).

If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string S is any leading contiguous substring of S.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.*/


class Solution {
public:
    int isPrefixOfWord(string s1, string s2) {
        string word = "";
        vector<string> s;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] == ' '){
                s.push_back(word);
                word = "";
            } else {
                word = word + s1[i];
            }
        }
        if(word.size())
            s.push_back(word);
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i].size() >= s2.size()){
                if(s[i].substr(0,s2.size()) == s2)
                    return i+1;
            }
        }
        return -1;
    }
};
