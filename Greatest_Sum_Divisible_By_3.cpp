class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> one,two;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 3 == 1) one.push_back(nums[i]);
            if(nums[i] % 3 == 2) two.push_back(nums[i]);
            ans += nums[i];
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        if(ans % 3 == 0) return ans;
        if(ans % 3 == 1) {
            if(two.size() < 2) return ans - one[0];
            return ans - min(one[0],two[0] + two[1]);
        }
        if(one.size() < 2) return ans - two[0];
        return ans - min(two[0],one[1] + one[0]);
    }
};
