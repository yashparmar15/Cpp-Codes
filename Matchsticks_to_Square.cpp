/*Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.*/


class Solution {
public:
    bool ans = false;
    void dfs(vector<long long int> &temp,vector<int> &nums,int index,long long int &req){
        if(ans) return;
        if(index == nums.size()){
            if(temp[0] == temp[1] and temp[1] == temp[2] and temp[2] == temp[3]) ans = true;
            return;
        }
        for(int i = 0 ; i < 4 ; i++){
            if(temp[i] + nums[index] <= req){
                temp[i] += nums[index];
                dfs(temp,nums,index + 1,req);
                if(ans) return;
                temp[i] -= nums[index];
            }
        }
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size() == 0) return false;
        long long int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
            sum += nums[i];
        if(sum % 4 != 0) return false;
        vector<long long int> temp(4,0);
        sum = sum / 4;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        dfs(temp,nums,0,sum);
        return ans;
    }
};
