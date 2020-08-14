/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/




class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> M;
        for(int i = 0 ; i < s.size() ; i++){
            M[s[i]]++;
        }
        int ans = 0;
        int maxOdd = 0;
        for(auto m : M){
            if(m.second % 2 == 0)
                ans = ans + m.second;
            else
                maxOdd = max(m.second,maxOdd);
        }
        ans = ans + maxOdd;
        int countMaxOdd = 0;
        for(auto m : M){
            if(m.second == maxOdd)
                countMaxOdd++;
        }
        if(countMaxOdd and maxOdd)
            ans = ans + (countMaxOdd - 1)*(maxOdd - 1);
        for(auto m : M){
            if(m.second % 2 and maxOdd != m.second)
                ans = ans + (m.second - 1);
        }
        return ans;
    }
};
