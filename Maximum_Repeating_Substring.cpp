/*For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.

Given strings sequence and word, return the maximum k-repeating value of word in sequence.

 

Example 1:

Input: sequence = "ababc", word = "ab"
Output: 2
Explanation: "abab" is a substring in "ababc".
Example 2:

Input: sequence = "ababc", word = "ba"
Output: 1
Explanation: "ba" is a substring in "ababc". "baba" is not a substring in "ababc".
Example 3:

Input: sequence = "ababc", word = "ac"
Output: 0
Explanation: "ac" is not a substring in "ababc". 
 

Constraints:

1 <= sequence.length <= 100
1 <= word.length <= 100
sequence and word contains only lowercase English letters.*/


class Solution {
public:
    int maxRepeating(string s, string w) {
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == w[0]){
                int count = 0;
                bool flag = true;
                if(s.size() - i < w.size())
                    continue;
                for(int j = 0 ; j < w.size() ; j++){
                    if(w[j] != s[i + j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    count++;
                    int j = i + w.size();
                    while(true){
                        if(s.size() - j < w.size()) break;
                        bool temp = true;
                        for(int k = 0 ; k < w.size() ; k++){
                            if(w[k] != s[j + k]){
                                temp = false;
                                break;
                            }
                        }
                        if(temp){
                            j += w.size();
                            count++;
                        } else {
                            break;
                        }
                    }
                }
                // cout << count << " " << i << endl;
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
