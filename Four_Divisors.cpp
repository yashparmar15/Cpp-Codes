/*Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
 

Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5*/


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0, sum, cnt;
        for(auto &num: nums) {
            sum = 0;
            cnt = 0;
            for(int j=1; j*j<=num; j++) {
                if (num%j==0) {
                    if (num/j == j) {
                        sum += j;
                        cnt++;
                    } else {
                        sum += j + (num/j);
                        cnt += 2;
                    }
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};
