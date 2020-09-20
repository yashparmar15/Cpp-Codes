/*Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]*/

class Solution {
public:
    static bool comp(vector<int> a , vector<int> b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> ans;
        int i = 0;
        while(i < v.size()){
            ans.push_back(v[i]);
            while(i < v.size() and ans[ans.size() - 1][1] >= v[i][0]){
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1],v[i][1]);
                i++;
            }
        }
        return ans;
    }
};
