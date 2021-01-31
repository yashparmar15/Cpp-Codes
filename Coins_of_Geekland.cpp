/*In Geekland there is a grid of coins of size N x N. You have to find the maximum sum of coins in any sub-grid of size K x K.
Note: Coins of the negative denomination are also possible at Geekland.

Example 1:

Input: N = 5, K = 3 
mat[[]] = {1, 1, 1, 1, 1} 
          {2, 2, 2, 2, 2} 
          {3, 8, 6, 7, 3} 
          {4, 4, 4, 4, 4} 
          {5, 5, 5, 5, 5}
Output: 48
Explanation: {8, 6, 7}
             {4, 4, 4}
             {5, 5, 5}
has the maximum sum

Example 2:

Input: N = 1, K = 1
mat[[]] = {{4}} 
Output: 4
Your Task:  
You don't need to read input or print anything. Complete the function Maximum_Sum() which takes the matrix mat[], size of Matrix N, and value K as input parameters and returns the maximum sum.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ K ≤ N ≤ 103
-5*105 ≤ mat[i][j] ≤ 5*105*/


class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        int ans = INT_MIN;
        vector<vector<int>> temp(mat.size(),vector<int> (mat[0].size(),0));
        for(int i = 0 ; i < mat[0].size() ; i++)
            for(int j = 0 ; j < K ; j++)
                temp[0][i] += mat[j][i];
        for(int i = 1 ; i < mat.size() - K + 1 ; i++)
            for(int j = 0 ; j < mat[0].size() ; j++)
                temp[i][j] = temp[i - 1][j] - mat[i - 1][j] + mat[i + K - 1][j];
        vector<vector<int>> v(mat.size(),vector<int>(mat[0].size(),0));
        for(int i = 0 ; i < mat.size() - K + 1 ; i++)
            for(int j = 0 ; j < K ; j++)
                v[i][0] += temp[i][j];
        for(int i = 0 ; i < mat.size() - K + 1 ; i++)
            for(int j = 1 ; j < mat[0].size() - K + 1 ; j++)
                v[i][j] = v[i][j - 1] - temp[i][j - 1] + temp[i][j + K - 1];
        for(int i = 0 ; i < v.size() ; i++)
            for(int j = 0 ; j < v[0].size() ; j++)
                ans = max(ans,v[i][j]);
        return ans;
    }  
};
