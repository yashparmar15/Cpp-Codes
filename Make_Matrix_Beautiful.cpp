/*matrix[][] = {{1, 2, 3},
              {4, 2, 3},
              {3, 2, 1}}
Output: 6
Explanation:
Original matrix is as follows:
1 2 3
4 2 3
3 2 1
We need to make increment in such a way 
that each row and column has one time 2, 
one time 3 , one time 4. For that we 
need 6 operations.

Your Task: 
You don't need to read input or print anything. Complete the function findMinOpeartion() that takes matrix and n as input parameters and returns the minimum number of operations.

Expected Time Complexity: O(N * N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 100
1 <= matrix[i][j] <= 200*/

class Solution
{
public:
    int findMinOpeartion(vector<vector<int> > v, int n)
    {
        // code here 
        vector<int> row(n,0);
        vector<int> col(n,0);
        int req = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                row[i] += v[i][j];
                col[j] += v[i][j];
                req = max(req,max(row[i],col[j]));
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(row[i] != req){
                int temp = req - row[i];
                for(int j = 0 ; j < n ; j++){
                    if(col[j] == req) continue;
                    int x = req - col[j];
                    if(x <= temp){
                        ans += x;
                        col[j] += x;
                        temp -= x;
                        row[i] += x;
                    } else {
                        ans += temp;
                        col[j] += temp;
                        temp = 0;
                        row[i] += temp;
                        break;
                    }
                }
            }
        }
        return ans;
    } 
};
