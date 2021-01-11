/*Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 

Constraints:

1 <= n <= 20*/


class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> v(n + 1);
        vector<int> ans(2 * n - 1);
        backtrack(ans, v, n, 0);
        return ans;
    }
private:
    bool backtrack(vector<int> &ans, vector<int> &v, int n, int i){
        if (i == ans.size()) return true;
        if (ans[i] != 0)
            return backtrack(ans, v, n, i + 1);
        for(int j = n; j > 0; --j){
            if (v[j] == 1) continue;
            if (j == 1){
                v[j] = 1; ans[i] = j;
                if (backtrack(ans, v, n, i + 1)) return true;
                v[j] = 0; ans[i] = 0;
            }else if(i + j < ans.size() && ans[i + j] == 0){
                v[j] = 1; ans[i] = j; ans[i + j] = j;
                if (backtrack(ans, v, n, i + 1)) return true;
                v[j] = 0; ans[i] = 0; ans[i + j] = 0;
            }
        }
        return false;
    }
};
