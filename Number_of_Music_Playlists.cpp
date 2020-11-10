/*Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:

Every song is played at least once
A song can only be played again only if K other songs have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 

Note:

0 <= K < N <= L <= 100*/


class Solution {
public:
    int M = 1000000007;
    vector<vector<long long int>> dp;
    int dfs(int &N,int &L,int &K,vector<int> last,int count,int diff){
        if(count == L and diff == N) return 1;
        if(count > L or diff > N) return 0;
        if(dp[count][diff] != -1) return dp[count][diff];
        long long int sum = 0;
        for(int i = 1 ; i <= N ; i++){
            if(last[i] == -1){
                last[i] = count;
                sum = (sum%M + dfs(N,L,K,last,count + 1,diff + 1)%M)%M;
                last[i] = -1;
            } else {
                if(count - last[i] > K) {
                    int temp = last[i];
                    last[i] = count;
                    sum = (sum%M + dfs(N,L,K,last,count + 1,diff)%M)%M;
                    last[i] = temp;
                }
            }
        }
        return dp[count][diff] = sum%M;
    }
    int numMusicPlaylists(int N, int L, int K) {
        vector<int> last;
        dp.resize(L + 1,vector<long long int>(N + 1,-1));
        last.resize(N + 1,-1);
        return dfs(N,L,K,last,0,0)%M;
    }
};
