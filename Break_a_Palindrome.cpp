/*Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.

 

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Example 2:

Input: palindrome = "a"
Output: ""
 

Constraints:

1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters.*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n <= 1) return "";
        string t1 = "",t2 = "";
        for(int i = 0 ; i < n ; i++){
            t1 = t1 + palindrome[i];
            t2 = t2 + palindrome[n - i - 1];
            if(palindrome[i] != 'a' and (i != n / 2 or t1 != t2)){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
