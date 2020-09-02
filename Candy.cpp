/*There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.*/
             
             
             
class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        vector<int> left(n),right(n);
        for(int i = 0 ; i < v.size() ; i++){
            if(i - 1 >= 0 and v[i] > v[i - 1]) left[i] = left[i - 1] + 1;
            else left[i] = 1;
            int j = n - i - 1;
            if(j + 1 < n and v[j] > v[j + 1]) right[j] = right[j + 1] + 1;
            else right[j] = 1;
        }
        for(int i = 0 ; i < n ; i++)
            ans = ans + max(left[i],right[i]);
        return ans;
    }
};
