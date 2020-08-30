/*Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.*/


class Solution {
public:
    bool check(string a,string b){
        int count = 0;
        int index = 0;
        for(int i = 0 ; i < a.size() and index < b.size(); i++,index++){
            if(a[i] != b[index]){
                count++;
                i--;
            }
            if(count > 1) return false;
        }
        return count <= 1;
    }
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),comp);
        for(int i = 0 ; i < words.size() ; i++)
            for(int j = i - 1 ; j >= 0 and words[j].size() + 1 >= words[i].size() ; j--)
                if(words[j].size() == words[i].size() - 1)
                    if(check(words[j],words[i]))
                        dp[i] = max(dp[j] + 1,dp[i]);
        for(int i = 0 ; i < words.size() ; i++)
            ans = max(ans,dp[i]);
        return ans;
    }
};
