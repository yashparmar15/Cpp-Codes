/*Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
 

Constraints:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
0 <= i <= j <= nums.length - 1*/



class NumArray {
public:
    vector<int> nums;
    vector<int> v;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int cur = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            cur = cur + nums[i];
            v.push_back(cur);
        }
    }
    
    void update(int i, int val) {
        int prev = nums[i];
        nums[i] = val;
        for(int k = i ; k < nums.size() ; k++){
            v[k] = v[k] + val - prev;
        }
    }
    
    int sumRange(int i, int j) {
        return v[j] - v[i] + nums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
