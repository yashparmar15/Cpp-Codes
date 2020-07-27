/*A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.*/



class Solution {
public:
    bool check(vector<int> a , vector<int> b){
        for(int i = 0 ; i < 26 ; i++){
            if(a[i]){
                if(a[i] != b[i])
                    return 0;
            }
        }
        return 1;
    }
    int length(vector<int> a){
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(a[i])
                ans = ans + a[i];
        }
        return ans;
    }
    vector<int> partitionLabels(string S) {
        vector<int> H(26,0);
        for(char ch : S){
            H[int(ch) - 97]++;
        }
        vector<int> H1(26,0);
        vector<int> ans;
        for(int i = 0 ; i < S.size() ; i++){
            H1[int(S[i]) - 97]++;
            if(check(H1,H)){
                ans.push_back(length(H1));
                for(int i = 0 ; i < 26 ; i++){
                    H1[i] = 0;
                }
            }
        }
        return ans;
    }
};
