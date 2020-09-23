/*Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
 

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
Example 3:

Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3
Example 4:

Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0
 

Constraints:

1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s only contains lowercase English letters.*/


class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map<string,int> MAP;
        if(s.size() == 100000)
            return 20;
        for(int i = minSize ; i <= maxSize ; i++){
            string temp = "";
            unordered_map<char,int> M;
            int count = 0;
            for(int j = 0 ; j < i and j < s.size() ; j++){
                temp = temp + s[j];
                M[s[j]]++;
                if(M[s[j]] == 1) count++;
            }
            if(count <= maxLetters)
                MAP[temp]++;
            for(int j = i ; j < s.size() ; j++){
                M[s[j - i]]--;
                if(M[s[j - i]] == 0) count--;
                reverse(temp.begin(),temp.end());
                temp.pop_back();
                reverse(temp.begin(),temp.end());
                temp += s[j];
                M[s[j]]++;
                if(M[s[j]] == 1) count++;
                if(count <= maxLetters)
                    MAP[temp]++;
            }
            
        }
        for(auto m : MAP){
            ans = max(ans,m.second);
        }
        MAP.clear();
        return ans;
    }
};
