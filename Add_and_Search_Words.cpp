/*Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.*/



class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int,vector<string>> M;
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        M[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(auto m : M[word.size()]){
            bool check = true;
            for(int i = 0 ; i < m.size() ; i++){
                if(word[i] == '.') continue;
                if(m[i] != word[i]){
                    check = false;
                    break;
                }
            }
            if(check)
                return 1;
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
