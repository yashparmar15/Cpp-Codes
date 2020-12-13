/*Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

 

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation: 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
Example 2:

Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
 

Constraints:

n == stones.length
2 <= n <= 1000
1 <= stones[i] <= 1000*/


class Solution {
public:
    int dp[1001][1001][2];
    int dfs(vector<int> &s,int low,int high,int turn){
        if(low >= high) return 0;
        if(dp[low][high][turn] != -1) return dp[low][high][turn];
        int ans;
        if(turn == 0){
            int temp1 = s[high + 1] - s[low + 1] + dfs(s,low + 1,high,1);
            int temp2 = s[high] - s[low] + dfs(s,low,high - 1,1);
            ans = max(temp1,temp2);
        } else {
            int temp1 = - s[high + 1] + s[low + 1] + dfs(s,low + 1,high,0);
            int temp2 = - s[high] + s[low] + dfs(s,low,high - 1,0);
            ans = min(temp1,temp2);
        }
        return dp[low][high][turn] = ans;
    }
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        vector<int> s(stones.size() + 1,0);
        for(int i = 1 ; i <= stones.size() ; i++)
            s[i] = s[i - 1] + stones[i - 1];
        return dfs(s,0,stones.size() - 1,0);
    }
};
