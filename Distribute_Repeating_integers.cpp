/*You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

The ith customer gets exactly quantity[i] integers,
The integers the ith customer gets are all equal, and
Every customer is satisfied.
Return true if it is possible to distribute nums according to the above conditions.

 

Example 1:

Input: nums = [1,2,3,4], quantity = [2]
Output: false
Explanation: The 0th customer cannot be given two different integers.
Example 2:

Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
Example 3:

Input: nums = [1,1,2,2], quantity = [2,2]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
Example 4:

Input: nums = [1,1,2,3], quantity = [2,2]
Output: false
Explanation: Although the 0th customer could be given [1,1], the 1st customer cannot be satisfied.
Example 5:

Input: nums = [1,1,1,1,1], quantity = [2,3]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [1,1,1].
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= 1000
m == quantity.length
1 <= m <= 10
1 <= quantity[i] <= 105
There are at most 50 unique values in nums.*/


class Solution {
public:
    bool dfs(vector<int> &v,vector<int> &s,int count){
        if(count == s.size()) return true;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] >= s[count]){
                v[i] -= s[count];
                if(dfs(v,s,count + 1)) return true;
                v[i] += s[count];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> M;
        for(auto n : nums) M[n]++;
        vector<int> v;
        for(int i = 0 ; i < quantity.size() ; i++){
            for(auto m : M){
                if(m.second == quantity[i]){
                    M[m.first] = 0;
                    quantity[i] = -1;
                    break;
                }
            }
        }
        vector<int> s;
        for(int i = 0 ; i < quantity.size() ; i++){
            if(quantity[i] != -1) s.push_back(quantity[i]);
        }
        for(auto m : M) {
            if(m.second)
                v.push_back(m.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        return dfs(v,s,0);
    }
};
