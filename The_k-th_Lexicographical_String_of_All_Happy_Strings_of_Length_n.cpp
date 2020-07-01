// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

// Example 1:

// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
// Example 2:

// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.
// Example 3:

// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
// Example 4:

// Input: n = 2, k = 7
// Output: ""
// Example 5:

// Input: n = 10, k = 100
// Output: "abacbabacb"



class Solution {
public:
    void recur(string s,int n , vector<string> &ans , int len){
        if(len == n){
            ans.push_back(s);
            return;
        }
        if(s == ""){
            recur(s + "a",n,ans,len + 1);
            recur(s + "b",n,ans,len + 1);
            recur(s + "c",n,ans,len + 1);
        } else {
            if(s[len - 1] == 'a'){
                recur(s + "b",n,ans,len + 1);
                recur(s + "c",n,ans,len + 1);
            } 
            if(s[len - 1] == 'b'){
                recur(s + "a",n,ans,len + 1);
                recur(s + "c",n,ans,len + 1);
            }
            if(s[len - 1] == 'c'){
                recur(s + "a",n,ans,len + 1);
                recur(s + "b",n,ans,len + 1);
            }
        }
        
    }
    string getHappyString(int n, int k) {
        if(n == 0)
            return "";
        vector<string> ans;
        int len = 0;
        string s = "";
        recur(s,n,ans,len);
        if(k > ans.size())
            return "";
        return ans[k - 1];
    }
};