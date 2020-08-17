/* Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if its possible otherwise return False.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [3,3,2,2,1,1], k = 3
Output: true
Example 4:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= nums.length*/


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size() % k)
            return false;
        unordered_map<int,int> M;
        for(int i = 0 ; i < nums.size() ; i++){
            M[nums[i]]++;
        }
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(M[nums[i]] > 0){
                cout << nums[i] << endl;
                for(int j = nums[i] ; j < nums[i] + k ; j++){
                    if(M[j] <= 0)
                        return false;
                    M[j]--;
                }
                count++;
            }
            if(count == nums.size() / k)
                return true;
        }
        if(count != nums.size() / k)
            return false;
        return true;
    }
};
