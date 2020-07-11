// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().




class Solution {
public:
    bool check(vector<int> x , vector<int> y){
        for(int i = 0 ; i < 26 ; i++){
            if(x[i] != y[i])
                return 0;
        }
        return 1;
    }
    bool check2(string a , string b , int index){
        for(int i = index ; i < index + a.size() ; i++){
            if(a[i - index] != b[i])
                return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(needle.size() > haystack.size())
            return -1;
        vector<int> H(26,0);
        vector<int> N(26,0);
        for(int i = 0 ; i < needle.size() ; i++){
            N[int(needle[i]) - 97]++;
            H[int(haystack[i]) - 97]++;
        }
        if(check(N,H) and check2(needle,haystack,0))
            return 0;
        for(int i = needle.size() ; i < haystack.size() ; i++){
            H[int(haystack[i - needle.size()]) - 97]--;
            H[int(haystack[i]) - 97]++;
            if(check(N,H) and check2(needle,haystack,i - needle.size() + 1))
                return i - needle.size() + 1;
        }
        return -1;
    }
};