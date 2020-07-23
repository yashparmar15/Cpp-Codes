/*Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".

For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is 3 or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.  Also, we could do another extension like "ll" -> "lllll" to get "helllllooo".  If S = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 

 

Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
 

Constraints:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters*/


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        vector<int> H(26,0);
        for(int i = 0 ; i < S.size() ; i++){
            H[int(S[i]) - 97]++;
        }
        for(int i = 0 ; i < words.size() ; i++){
            bool flag = true;
            int k = 0;
            vector<int> h(26,0);
            for(int g = 0 ; g < words[i].size() ; g++){
                h[int(words[i][g]) - 97]++;
            }
            for(int g = 0 ; g < 26 ; g++){
                if(H[g] and !h[g])
                    flag = false;
            }
            for(int j = 0 ; j < words[i].size() ; j++,k++){
                if(words[i][j] != S[k]){
                    flag = false;
                    break;
                } else {
                    char t = words[i][j];
                    int count = 0;
                    int c = 0;
                    while(words[i][j] == S[k] and words[i][j] == t){
                        j++;
                        k++;
                        count++;
                        c++;
                    }
                    j--;
                    k--;
                    if(k + 1 < S.size() and S[k] == S[k + 1]){
                        while(k + 1 < S.size() and S[k] == S[k + 1]){
                            k++;
                            count++;
                        }
                    }
                    if(count > 0 and count < 3 and count != c)
                        flag = false;
                }
            }
            if(k < S.size())
                flag = false;
            if(flag)
                ans++;
        }
        return ans;
    }
};
