/*Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
 

Example 1:



Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:



Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]
Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.*//



class Solution {
public:
    static bool comp(pair<int,pair<int,int>> a , pair<int,pair<int,int>> b){
        if(a.first == b.first)
            return a.second.first < b.second.first;
        return a.first < b.first;
            
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[i].size() ; j++){
                v.push_back(make_pair(i + j,make_pair(j,nums[i][j])));
            }
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i = 0 ; i < v.size() ; i++){
            ans.push_back(v[i].second.second);
        }
        return ans;
    }
};
