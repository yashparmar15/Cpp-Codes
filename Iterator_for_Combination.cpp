/*Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.*/



class CombinationIterator {
public:
    vector<string> v;
    string s;
    int len;
    int cur = 0;
    CombinationIterator(string characters, int combinationLength) {
        this->s = characters;
        this->len = combinationLength;
        string temp = "";
        recur(v,s,len,temp,0);
        sort(v.begin(),v.end());
    }
    
    string next() {
        return v[cur++];
    }
    
    bool hasNext() {
        if(cur + 1 <= v.size())
            return 1;
        return 0;
    }
    void recur(vector<string> &v , string s , int len, string temp,int index){
        if(temp.size() == len){
            v.push_back(temp);
            return;
        }        
        for(int i = index ; i < s.size() ; i++){
            recur(v,s,len,temp + s[i],i+1);
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
