/*Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].*/



class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& words) {
        vector<vector<int>> v(26);
        for(int i = 0 ; i < s.size() ; i++)
            v[s[i] - 'a'].push_back(i);
        int ans = 0;
        int index = 0;
        for(int i = 0 ; i < words.size() ; i++){
            int index = 0;
            bool flag = true;
            for(int j = 0 ; j < words[i].size() ; j++){
                int ch = words[i][j] - 'a';
                if(v[ch].size() == 0){
                    flag = false;
                    break;
                }
                if(v[ch][v[ch].size() - 1] < index){
                    flag = false;
                    break;
                }   
                int prev = index;
                int num = lower_bound(v[ch].begin(),v[ch].end(),index) - v[ch].begin();
                index = v[ch][num];
                if(index == prev and index != 0){
                    if(num + 1 >= v[ch].size()){
                        flag = false;
                        break;
                    }
                    index = v[ch][num + 1];
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};
