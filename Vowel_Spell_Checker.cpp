/*Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 

Note:

1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
All strings in wordlist and queries consist only of english letters.*/


class Solution {
public:
    unordered_map<string,int> M1;
    unordered_map<string,string> M2,M3;
    string tolower(string a){
        transform(a.begin(),a.end(),a.begin(),::tolower);
        return a;
    }
    bool isVowel(char ch){
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') return true;
        if(ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') return true;
        return false;
    }
    vector<string> spellchecker(vector<string>& w, vector<string>& q) {
        for(int i = 0 ; i < w.size() ; i++)
            M1[w[i]] = 1;
        for(int i = 0 ; i < w.size() ; i++){
            string s = tolower(w[i]);
            if(M2.find(s) == M2.end())
                M2[s] = w[i];
            for(int i = 0 ; i < s.size() ; i++){
                if(isVowel(s[i])) s[i] = '*';
            }
            if(M3.find(s) == M3.end())
                M3[s] = w[i];
        }
        vector<string> ans;
        for(int i = 0 ; i < q.size() ; i++){
            if(M1.find(q[i]) != M1.end())
                ans.push_back(q[i]);
            else{
                string s = tolower(q[i]);
                if(M2.find(s) != M2.end())
                    ans.push_back(M2[s]);
                else{
                    for(int j = 0 ; j < s.size() ; j++)
                        if(isVowel(s[j])) s[j] = '*';
                    if(M3.find(s) != M3.end())
                        ans.push_back(M3[s]);
                    else
                        ans.push_back("");
                }
            }
        }
        return ans;
    }
};
