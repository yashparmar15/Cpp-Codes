// Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode"
// return 2.
 

// Note: You may assume the string contains only lowercase English letters.



class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        for(auto& ch : s){
            freq[ch]++;
        }
        for(int i = 0 ; i < s.length() ; i++){
            if(freq[s[i]] == 1)
                return i;
        }
        return -1;
    }
};