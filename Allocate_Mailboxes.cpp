/*Given the array houses and an integer k. where houses[i] is the location of the ith house along a street, your task is to allocate k mailboxes in the street.

Return the minimum total distance between each house and its nearest mailbox.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:



Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
Example 2:



Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
Example 3:

Input: houses = [7,4,6,1], k = 1
Output: 8
Example 4:

Input: houses = [3,6,14,10], k = 4
Output: 0
 

Constraints:

n == houses.length
1 <= n <= 100
1 <= houses[i] <= 10^4
1 <= k <= n
Array houses contain unique integers.*/


class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        if(k >= houses.size())
            return 0;
        sort(houses.begin(),houses.end());
        vector<vector<int>> dp;
        for(int i = 0 ; i < houses.size() ; i++){
            vector<int> temp(k,0);
            dp.push_back(temp);
        }
        for(int i = 0 ; i < k ; i++){
            for(int j = 0 ; j < houses.size() ; j++){
                if(i == 0){
                    vector<int> temp;
                    for(int x = 0 ; x <= j ; x++){
                        temp.push_back(houses[x]);
                    }
                    int median = 0;
                    if(temp.size() % 2)
                        median = temp[temp.size() / 2];
                    else
                        median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2;
                    int value = 0;
                    for(int x = 0 ; x < temp.size() ; x++){
                        value += abs(temp[x] - median);
                    }
                    dp[j][i] = value;
                } else {
                    int finalValue = INT_MAX;
                    if(j <= i)
                        dp[j][i] = 0;
                    else{
                        vector<int> temp;
                        for(int x = 0 ; x <= j ; x++){
                            temp.push_back(houses[x]);
                        }
                        reverse(temp.begin(),temp.end());
                        temp.pop_back();
                        int s = temp.size();
                        for(int x = 0 ; x < s ; x++){
                            int median = 0;
                            if(temp.size() % 2)
                                median = temp[temp.size() / 2];
                            else
                                median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2;
                            int value = 0;
                            for(int y = 0 ; y < temp.size() ; y++){
                                value += abs(temp[y] - median);
                            }
                            finalValue = min(finalValue,value + dp[x][i - 1]);
                            temp.pop_back();
                        }
                        dp[j][i] = finalValue;
                    }
                }
                cout << dp[j][i] << " ";
            }
            cout << endl;
        }
        return dp[houses.size() - 1][k - 1];
    }
};
