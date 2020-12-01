/*You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000*/


class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int k,int n){
        if(n <= 1) return n;
        if(k == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        int temp = INT_MAX;
        int l = 1,h = n;
        while(l <= h){
            int mid = (l + h) / 2;
            int left = dfs(k - 1,mid - 1);
            int right = dfs(k,n - mid);
            if(left < right)
                l = mid + 1;
            else
                h = mid - 1;
            temp = min(temp,max(left,right) + 1);
        }
        return dp[k][n] = temp;
    }
    int superEggDrop(int K, int N) {
        dp.resize(K + 1,vector<int> (N + 1,-1));
        if(K == 1) return N;
        return dfs(K,N);
    }
};
