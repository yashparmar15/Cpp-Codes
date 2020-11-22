/*Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
Note: The value of n won't exceed 100,000.*/


class Solution {
public:
    long long dp[100001][3][2];
    const long long mod=1e9+7;
    long long recur(int in,int l,int a,int n)
    {
        if(l>2||a>1)
            return 0;
        if(in==n)
            return 1;
        if(dp[in][l][a]==-1)
        {
    return dp[in][l][a]=(recur(in+1,0,a,n)%mod+recur(in+1,l+1,a,n)%mod+recur(in+1,0,a+1,n)%mod)%mod;
        }
        else
            return dp[in][l][a];
        
    }
    int checkRecord(int n) {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                dp[i][j][0]=dp[i][j][1]=-1;
            }
        }
        int ans=recur(0,0,0,n);
        return ans;
    }
};
