/*Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.*/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans(S.size(),INT_MAX);
        for(int i = 0 ; i < S.size() ; i++)
            if(S[i] == C) ans[i] = 0;
        for(int i = 0 ; i < ans.size() ; i++){
            int count = 1;
            if(ans[i] == 0){
                i++;
                while(i < ans.size() and ans[i] != 0){
                    ans[i] = min(ans[i],count);
                    count++;
                    i++;
                }
                i--;
            }
        }
        for(int i = ans.size() - 1 ; i >= 0 ; i--){
            int count = 1;
            if(ans[i] == 0){
                i--;
                while(i >= 0 and ans[i] != 0){
                    ans[i] = min(ans[i],count);
                    count++;
                    i--;
                }
                i++;
            }
        }
        return ans;
    }
};
