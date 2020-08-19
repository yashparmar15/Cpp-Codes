/*Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly one element from each row of arr, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.

 

Example 1:

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
 

Constraints:

1 <= arr.length == arr[i].length <= 200
-99 <= arr[i][j] <= 99*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>> dp;
        for(int i = 0 ; i < arr.size() ; i++){
            vector<int> temp(arr[0].size(),0);
            dp.push_back(temp);
        }
        int Max = INT_MAX , sMax = INT_MAX;
        vector<int> index1,index2;
        for(int i = 0 ; i < arr[0].size() ; i++){
            dp[0][i] = arr[0][i];
            if(arr[0][i] < Max){
                if(Max != INT_MAX){
                    sMax = min(sMax,Max);
                }
                Max = min(Max,arr[0][i]);
                index1.clear();
                index1.push_back(i);
            } else{
                if(arr[0][i] == Max)
                    index1.push_back(i);       
            }
            if(arr[0][i] != Max)
                sMax = min(sMax,arr[0][i]);
        }
        cout << Max << " " << sMax << endl;
        for(int i = 1 ; i <  arr.size() ; i++){
            cout << Max << " " << sMax << endl;
            int v1 = Max,v2 = sMax;
            vector<int> i1 = index1,i2 = index2;
            Max = INT_MAX,sMax = INT_MAX;
            index1.clear();
            index2.clear();
            for(int j = 0 ; j < arr[0].size() ; j++){
                bool check = false;
                for(int k = 0 ; k < i1.size() ; k++){
                    if(i1[k] != j)
                        check = true;
                }
                if(check)
                    dp[i][j] = arr[i][j] + v1;
                else
                    dp[i][j] = arr[i][j] + v2;
                if(dp[i][j] < Max){
                    if(Max != INT_MAX){
                        sMax = min(sMax,Max);
                    }
                    Max = min(Max,dp[i][j]);
                    index1.clear();
                    index1.push_back(j);
                } else {
                    if(Max == dp[i][j])
                        index1.push_back(j);
                }
                if(dp[i][j] != Max)
                    sMax = min(sMax,dp[i][j]);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < dp[0].size() ; i++){
            ans = min(ans,dp[dp.size() - 1][i]);
        }
        return ans;
    }
};
