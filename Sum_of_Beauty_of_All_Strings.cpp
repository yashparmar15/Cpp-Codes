/*The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.*/


class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int H[26];
        memset(H,0,sizeof(H));
        for(int i = 0 ; i < s.size() ; i++){
            memset(H,0,sizeof(H));
            for(int j = i ; j < s.size() ; j++){
                H[s[j] - 'a']++;
                int minn = INT_MAX,maxx = INT_MIN;
                for(int k = 0 ; k < 26 ; k++){
                    if(H[k] != 0){
                        minn = min(H[k],minn);
                        maxx = max(H[k],maxx);
                    }
                }
                ans = ans + maxx - minn;
            }
        }
        return ans;
    }
};
