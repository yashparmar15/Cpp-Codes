/*Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

 

Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
Example 2:

Input: arr = [2,3,5], target = 10
Output: 5
Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5*/


class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int cur_sum = 0;
        int index = 0;
        int ans = 0;
        int Min = INT_MAX;
        for(int i = 0 ; i <= 100000 ; i++){
            int num = 0;
            if(index < arr.size() and arr[index] == i){
                while(index < arr.size() and arr[index] == i){
                    cur_sum += i;
                    index++;
                }
                index--;
                num = cur_sum + (arr.size() - index - 1) * arr[index];
                index++;
            } else {
                num = cur_sum + i * (arr.size() - index);
            }
            if(abs(num - target) < Min){
                Min = abs(num - target);
                ans = i;
            }
        }
        return ans;
    }
};
