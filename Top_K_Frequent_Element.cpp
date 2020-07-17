/*Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.*/


class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
    
        vector<int> num;

        for(int n:nums)
        {
            mp[n]++;
        }

        vector<pair<int, int>> vec;

        for(auto &v: mp)
            vec.push_back({v.first, v.second});       
        sort(vec.begin(), vec.end(), 
             [](const pair<char, int> &a, const pair<char, int> &b) 
                    {return a.second > b.second; });
        for(int i = 0 ; i < k ; i++)
            num.push_back(vec[i].first);

        return num;
    }
};
