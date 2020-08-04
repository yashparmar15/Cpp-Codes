/*mplement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.*/


class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<string,bool> M;
    unordered_map<string,bool> M1;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        string s = "";
        for(int i = 0 ; i < word.size() ; i++){
            s = s + word[i];
            M1[s] = 1;
        }
        M[word] = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return M[word];   
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return M1[prefix];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
