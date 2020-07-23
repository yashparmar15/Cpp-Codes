/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?*/



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            Xor = Xor ^ nums[i];
        }
        int x = 1;
        for(int i = 1 ; i < 32 ; i++){
            if((x & Xor) == x) break;
            x = x << 1;
        }
        int num1 = 0 , num2 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if((nums[i] & x) == x) num1 = num1 ^ nums[i];
            else num2 = num2 ^ nums[i];
        }
        return {num1,num2};
    }
};
