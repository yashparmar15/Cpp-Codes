/*Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
 

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 0)
            return 0;
        int ans = 1, count = 1;
        for(int i = 0 ; i < s.size() - 1 ; i++){
            if(s[i] == s[i + 1]){
                count++;
            } else {
                count = 1;
            }
            ans = max(ans,count);
        }
        if(k == 0)
            return ans;
        for(int i = 0 ; i < 26 ; i++){
            int left = 0 , right = 0;
            int sum = 0;
            int t = k;
            while(right < s.size() and left < s.size()){
                int a = int(s[right]) - 65;
                int b = int(s[left]) - 65;
                if(a == i){
                    right++;
                    sum++;
                } else {
                    if(t > 0 and a != i){
                        t--;
                        sum++;
                        right++;
                    } else {
                        if(b != i and t + 1 <= k)
                            t++;
                        left++;
                        sum--;
                    }
                }
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};
