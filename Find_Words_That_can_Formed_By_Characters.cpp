/*You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.*/



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> H(26,0);
        int ans = 0;
        for(int i = 0 ; i < chars.size() ; i++){
            H[int(chars[i]) - 97]++;
        }
        for(int i = 0 ; i < words.size() ; i++){
            vector<int> h(26,0);
            for(int j = 0 ; j < words[i].size() ; j++){
                h[int(words[i][j]) - 97]++;
            }
            bool flag = true;
            for(int k = 0 ; k < 26 ; k++){
                if(h[k] > H[k]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans = ans + words[i].size();
        }
        return ans;
    }
};
