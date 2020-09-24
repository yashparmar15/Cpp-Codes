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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Trie {
    struct TrieNode{
        map<char,TrieNode*> child;
        int end;
        TrieNode () : end(0){}
    };
        
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;
        for(int i = 0 ; i < s.size() ; i++){
            if(cur->child.count(s[i]) == 0)
                cur->child[s[i]] = new TrieNode();
            cur = cur->child[s[i]];
        }
        cur->end = 1;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return find(key, 1);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }

private:
    TrieNode* root;
    bool find(string s, int exact_match)
    {
        TrieNode* cur = root;
        for(int i = 0 ; i < s.size() ; i++){
            if(cur->child.count(s[i]) == 0)
                return false;
            cur = cur->child[s[i]];
        }
        if(exact_match)
            return cur->end ? true : false;
        return true;
    }
};
