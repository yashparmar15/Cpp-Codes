// Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

// Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

 

// Example 1:

// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
// Example 2:

// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.



class Solution {
public:
    bool canConstruct(string s, int k) {
        int cnt[26];
        int n=s.length();
        memset(cnt,0,sizeof(cnt));
        for(auto it:s)cnt[it-'a']++;
        int odd=0;
        for(int i=0;i<26;i++)
            if(cnt[i]&1)odd++;
        return k>=odd and k<=n;
    }
};