class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> next(nums2.size(),-1);
        stack<int> s;
        unordered_map<int,int> M;
        for(int i = 0 ; i < nums2.size() ; i++){
            M[nums2[i]] = i;
            while(!s.empty() and nums2[s.top()] < nums2[i]){
                next[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> ans;
        for(int i = 0 ; i < nums1.size() ; i++)
            ans.push_back(next[M[nums1[i]]]);
        return ans;
    }
};
