/*In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].*/



class Solution {
public:
    vector<vector<int>> dp;
    double avg;
    bool dfs(vector<int> &A,int sum,int len,int index){
        double a = (sum * 1.0) / (len * 1.0);
        if(len and len != A.size() and a == avg) return true;
        if(index >= A.size()) return false;
        if(dp[index][sum] != -1) return dp[index][sum] == 1;
        bool flag = dfs(A,sum + A[index],len + 1,index + 1) or dfs(A,sum,len,index + 1);
        dp[index][sum] = flag ? 1 : 0;
        return flag;
    }
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0;
        for(auto a : A) sum += a;
        avg = (sum * 1.0) / (A.size() * 1.0);
        int sum1 = 0,len1 = 0;
        dp.resize(A.size() + 1,vector<int> (sum + 1,-1));
        return dfs(A,0,0,0);
    }
};
