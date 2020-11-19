/*Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

 

Example 1:

Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
Example 2:

Input: arr1 = [0], arr2 = [0]
Output: [0]
Example 3:

Input: arr1 = [0], arr2 = [1]
Output: [1]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
arr1[i] and arr2[i] are 0 or 1
arr1 and arr2 have no leading zeros*/


class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        //  1   1   1   1   1
        //  1   0   1
        //  0   0   0   0   1
        //  11
        //  1 -- 1
        //  2 -- 110
        //  3 -- 1101
        int carry = 0;
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        int end = min(arr1.size(),arr2.size());
        vector<int> ans;
        for(int i = 0 ; i < end ; i++){
            int num = carry + arr1[i] + arr2[i];
            switch(num){
                case 0: {
                    ans.push_back(0);
                    carry = 0;
                    break;
                }
                case 1: {
                    ans.push_back(1);
                    carry = 0;
                    break;
                }
                case 2: {
                    ans.push_back(0);
                    carry = -1;
                    break;
                }
                case -1: {
                    ans.push_back(1);
                    carry = 1;
                    break;
                }
                case 3: {
                    ans.push_back(1);
                    carry = -1;
                    break;
                }
                case -2: {
                    ans.push_back(0);
                    carry = 1;
                    break;
                }
            }
        }
        for(int i = end ; i < arr1.size() ; i++){
            int num = carry + arr1[i];
            switch(num){
                case 0: {
                    ans.push_back(0);
                    carry = 0;
                    break;
                }
                case 1: {
                    ans.push_back(1);
                    carry = 0;
                    break;
                }
                case 2: {
                    ans.push_back(0);
                    carry = -1;
                    break;
                }
                case -1: {
                    ans.push_back(1);
                    carry = 1;
                    break;
                }
                case 3: {
                    ans.push_back(1);
                    carry = -1;
                    break;
                }
                case -2: {
                    ans.push_back(0);
                    carry = 1;
                    break;
                }
            }
        }
        for(int i = end ; i < arr2.size() ; i++){
            int num = carry + arr2[i];
            switch(num){
                case 0: {
                    ans.push_back(0);
                    carry = 0;
                    break;
                }
                case 1: {
                    ans.push_back(1);
                    carry = 0;
                    break;
                }
                case 2: {
                    ans.push_back(0);
                    carry = -1;
                    break;
                }
                case -1: {
                    ans.push_back(1);
                    carry = 1;
                    break;
                }
                case 3: {
                    ans.push_back(1);
                    carry = -1;
                    break;
                }
                case -2: {
                    ans.push_back(0);
                    carry = 1;
                    break;
                }
            }
        }
        if(carry == -1){
            ans.push_back(1);
            ans.push_back(1);
        }
        if(carry == -2){
            ans.push_back(0);
            ans.push_back(1);
        }
        if(carry == 1)
            ans.push_back(1);
        while(ans.size() and ans.back() == 0)
            ans.pop_back();
        if(ans.size() == 0) ans.push_back(0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
