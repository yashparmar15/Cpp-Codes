/*Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> H;
        for(int i = 0 ; i < A.size() ; i++){
            vector<int> h(26,0);
            for(int j = 0 ; j < A[i].size() ; j++){
                h[int(A[i][j]) - 97]++;
            }
            H.push_back(h);
        }
        vector<string> ans;
        for(int i = 0 ; i < 26 ; i++){
            int mini = INT_MAX;
            for(int j = 0 ; j < A.size() ; j++){
                mini = min(mini,H[j][i]);
            }
            for(int k = 0 ; k < mini ; k++){
                ans.push_back(string(1,i + 'a'));
            }
        }
        return ans;
    }
};
