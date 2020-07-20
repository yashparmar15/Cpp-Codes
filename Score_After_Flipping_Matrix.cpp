/*We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

Note:

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.*/



class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for(int i = 0 ; i < A.size() ; i++){
            if(A[i][0] == 0){
                for(int j = 0 ; j < A[i].size() ; j++){
                    A[i][j] = abs(A[i][j] - 1);
                }
            }
        }
        for(int i = 0 ; i < A[0].size() ; i++){
            int one = 0 , zero = 0;
            for(int j = 0 ; j < A.size() ; j++){
                if(A[j][i] == 1)
                    one++;
                else
                    zero++;
            }
            if(zero > one){
                for(int j = 0 ; j < A.size() ; j++){
                    A[j][i] = abs(A[j][i] - 1);
                }
            }
        }
        long long int ans = 0;
        for(int i = 0 ; i < A.size() ; i++){
            int power = 1;
            for(int j = 0 ; j < A[0].size() ; j++){
                ans = ans + A[i][A[0].size() - j - 1]*power;
                power = power * 2;
            }
        }
        return ans;
    }
};
