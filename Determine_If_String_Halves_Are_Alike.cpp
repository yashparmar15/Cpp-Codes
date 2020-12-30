/*You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
Example 3:

Input: s = "MerryChristmas"
Output: false
Example 4:

Input: s = "AbCdEfGh"
Output: true
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.*/


class Solution {
public:
    bool halvesAreAlike(string s) {
        int t=0;
        for(int i=0;i<s.size();i++)
        {   
             s[i]=tolower(s[i]);
            if(i<s.size()/2)
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                      t++;                  // counting for the first half of the string
            }
            else
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                     t--;            // reducing the count if occures in second half of the string 
            }
                
        }
        
        if(t==0)
            return 1;
        else
            return 0;
    }
};
