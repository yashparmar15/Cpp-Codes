/*You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
Example 3:

Input: nums = [[10,10],[11,11]]
Output: [10,11]
Example 4:

Input: nums = [[10],[11]]
Output: [10,11]
Example 5:

Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
Output: [1,7]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.*/


class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.first < b.first;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        for(int i = 0 ; i < nums.size() ; i++)
            for(int j = 0 ; j < nums[i].size() ; j++)
                v.push_back(make_pair(nums[i][j],i + 1));
        sort(v.begin(),v.end(),comp);
        vector<int> ans(2,0);
        unordered_map<int,int> M;
        int count = 0;
        int req = nums.size() * (nums.size() + 1) / 2;
        int prev = 0;
        int range = INT_MAX;
        for(int i = 0 ; i < v.size() ; i++){
            if(M.find(v[i].second) == M.end())
                count += v[i].second;
            M[v[i].second]++;
            if(count == req){
                int j = prev;
                for( ; j < i ; j++){
                    if(M[v[j].second] == 1)
                        break;
                    else
                        M[v[j].second]--;
                }
                if(v[i].first - v[j].first < range){
                    ans[0] = v[j].first;
                    ans[1] = v[i].first;
                    range = v[i].first - v[j].first;
                }
                prev = j;
            }
            
        }
        return ans;
    }
};
