/*Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length*/


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prev = 0,after = 0,i = 0,count = 0,index = 0,ans = 0;
        for(; i < nums.size() ; i++){
            if(count == 0 and nums[i] % 2 == 0)
                prev++;
            if(nums[i] % 2){
                count++;
                if(count == 1)
                    index = i;
            }
            if(count == k)
                break;
        }
        for(; i < nums.size() ; i++){
            if(nums[i] % 2){
                i++;
                while(i < nums.size() and nums[i] % 2 == 0){
                    after++;
                    i++;
                }
                i--;
                ans = ans + (prev + 1)*(after + 1);
                after = 0;
                prev = 0;
                int j = index + 1;
                for(;j < nums.size() and nums[j] % 2 != 1 ; j++){
                    prev++;
                }
                index = j;
            } else {
                after++;
            }
        }
        return ans;
    }
};
