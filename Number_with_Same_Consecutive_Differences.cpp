/*Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9*/


class Solution {
public:
    
    void backtrack(int N, int k, vector<int> &ans,string temp){
        if(temp.size() == N){
            int num = 0;
            for(int i = 0 ; i < temp.size() ; i++){
                num = num * 10 + int(temp[i]) - 48;
            }
            ans.push_back(num);
            return;
        }
        for(int i = 0 ; i <= 9 ; i++){
            if(temp.size()){
                if(abs(i - int(temp[temp.size() - 1]) + 48) == k)
                    backtrack(N,k,ans,temp + to_string(i));
            } else {
                if(i)
                    backtrack(N,k,ans,temp + to_string(i));
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int k) {
        vector<int> ans;
        string temp = "";
        if(N == 1)
            ans.push_back(0);
        backtrack(N,k,ans,temp);
        return ans;
    }
};
