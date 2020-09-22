class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int N = nums.size();
        int num1 = INT_MIN,count1 = 0;
        int num2 = INT_MIN,count2 = 0;
        for(int i = 0 ; i < N ; i++){
            if(count1 == 0 and nums[i] != num2){
                num1 = nums[i];
                count1++;
            } else {
                if(count2 == 0 and nums[i] != num1){
                    num2 = nums[i];
                    count2++;
                } else {
                    if(nums[i] == num1)
                        count1++;
                    else if(nums[i] == num2)
                        count2++;
                    else{
                        count1--;
                        count2--;
                    }
                }
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0 ; i < N ; i++){
            if(nums[i] == num1 and (num1 != INT_MIN or nums[i] == INT_MIN)) count1++;
            if(nums[i] == num2 and (num2 != INT_MIN or nums[i] == INT_MIN ) and num2 != num1) count2++;
        }
        if(count1 > N / 3) ans.push_back(num1);
        if(count2 > N / 3) ans.push_back(num2);
        return ans;
    }
};
