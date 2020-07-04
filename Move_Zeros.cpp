// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.



class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int Zero = 0;
        for(int i = 0; i < v.size() ; i++){
            if(v[i] == 0){
                Zero ++;
            }
            else{
                v[i - Zero] = v[i];
            }
        }
        for(int i = v.size() - Zero ; i < v.size() ; i++){
            v[i] = 0;
        }
    }
};