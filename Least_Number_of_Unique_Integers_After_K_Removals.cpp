/*Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length*/


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> M;
        for(int i = 0 ; i < arr.size() ; i++){
            M[arr[i]]++;
        }
        vector<int> v;
        for(auto m : M){
            v.push_back(m.second);
        }
        sort(v.begin(),v.end());
        int count = 0;
        for(int i = 0 ; i < v.size() ; i++){
            count += v[i];
            v[i] = 0;
            if(count == k)
                break;
            if(count > k){
                v[i] = 1;
                break;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i])
                ans++;
        }
        return ans;
    }
};
