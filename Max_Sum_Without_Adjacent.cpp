/*Given an array A of positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, size of array. The second line of each test case contains N elements.

Output:
Print the maximum sum of a subsequence.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ci ≤ 107

Example:
Input:
2
6
5 5 10 100 10 5
4
3 2 7 10

Output:
110
13

Explanation:
Testcase 2 : 3 and 10 forms a non-continuous subsequence with maximum sum.*/



#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(long long int i = a;i < b;i++)
#define ll long long 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> dp(n,0);
        int temp;
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            if(i == 0 or i == 1)
                dp[i] = temp;
            else{
                if(i == 2)
                    dp[i] = temp + dp[i - 2];
                else
                    dp[i] = max(dp[i - 2],dp[i - 3]) + temp;
            }
        }
        cout << max(dp[n - 2],dp[n - 1]) << endl;
    }
}
