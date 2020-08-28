/*We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 

Note: The length of the input array will not exceed 20,000.*/


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> M;
        for(int i = 0 ; i < nums.size() ; i++)
            M[nums[i]]++;
        int ans = 0;
        for(auto m : M){
            if(M.find(m.first + 1) != M.end())
                ans = max(ans,m.second + M[m.first + 1]);
            if(M.find(m.first - 1) != M.end())
                ans = max(ans,m.second + M[m.first - 1]);
        }
        return ans;
    }
};
