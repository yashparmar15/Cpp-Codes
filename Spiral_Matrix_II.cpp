/*Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        vector<int> temp(n,0);
        for(int i = 0 ; i < n ; i++)
            ans.push_back(temp);
        int leftup = 0,rightup = n - 1,rightdown = n - 1,leftdown = 0;
        int num = 1;
        while(num <= n * n){
            for(int i = leftup ; i <= rightup ; i++)
                ans[leftup][i] = num++;
            if(num > n * n) break;
            for(int i = n - rightdown ; i <= rightdown ; i++)
                ans[i][rightup] = num++;
            for(int i = rightdown - 1 ; i >= leftdown ; i--)
                ans[rightdown][i] = num++;
            for(int i = rightdown - 1 ; i >= leftup + 1 ; i--)
                ans[i][n - rightdown - 1] = num++;
            leftup++,rightup--,rightdown--,leftdown++;
        }
        return ans;
    }
};
