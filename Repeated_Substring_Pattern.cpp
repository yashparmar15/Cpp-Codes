/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> factors;
        int n = s.size();
        for(int i = 1 ; i < n ; i++){
            if(n % i == 0)
                factors.push_back(i);
        }
        for(int i = 0 ; i < factors.size() ; i++){
            bool check = true;
            for(int j = factors[i] ; j < n ; j++){
                if(s[j] != s[j - factors[i]]){
                    check = false;
                    break;
                }
            }
            if(check) return true;
        }
        return false;
    }
};
