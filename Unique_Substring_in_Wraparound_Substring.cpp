/*Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.*/


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int H[26] = {0};
        for(int i = 0 ; i < p.size() ; i++){
            if(i + 1 < p.size() and ((int(p[i]) - 97 == (int(p[i + 1]) - 98) or (int(p[i]) == 122 and int(p[i + 1]) == 97)))){
                int start = i,count = 1;
                while(i + 1 < p.size() and ((int(p[i]) - 97 == (int(p[i + 1]) - 98) or (int(p[i]) == 122 and int(p[i + 1]) == 97)))){
                    i++;
                    count++;
                }
                int upto = i;
                if(start + 26 < upto)
                    upto = start + 26;
                for(int j = start ; j <= upto ; j++,count--)
                    H[p[j] - 'a'] = max(H[p[j] - 'a'],count);
            } else {
                H[p[i] - 'a'] = max(H[p[i] - 'a'],1);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            ans += H[i];
        }
        return ans;
    }
};
