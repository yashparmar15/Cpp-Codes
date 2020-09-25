/*Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.*/



class Solution {
public:
    static int compare(string i1, string i2)
    {
        return stoll(i1+i2)>stoll(i2+i1);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>temp; string ans;
        for(int i = 0; i < nums.size(); i++) temp.push_back(to_string(nums[i]));
        sort(temp.begin(),temp.end(),compare);
        for(auto x:temp) ans+=x;
        if(ans[0]=='0') ans="0";
        return ans;
    }
};
