/*Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 104*/


class Solution {
public:
    static bool comp(pair<int,int> a , pair<int,int> b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<pair<int,int>> v;
        for(int i = 0 ; i < arr.size() ; i++){
            v.push_back(make_pair(abs(x - arr[i]),arr[i]));
        }
        sort(v.begin(),v.end(),comp);
        for(int i = 0 ; i < k ; i++){
            ans.push_back(v[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
