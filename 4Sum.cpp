/*Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        map<vector<int>,int> M;
        int N = v.size();
        int leftmost = 0;
        int rightmost = 1;
        sort(v.begin(),v.end());
        for(leftmost = 0 ; leftmost < N - 2 ; leftmost++){
            for(rightmost = leftmost + 1 ; rightmost < N - 2 ; rightmost ++){
                int left = rightmost + 1;
                int right = N - 1;
                int Sum2 = v[leftmost] + v[rightmost];
                while(left < right){
                    int Sum = v[leftmost] + v[rightmost] + v[left] + v[right];
                    if(Sum == target){
                        vector<int> a;
                        a.push_back(v[leftmost]);
                        a.push_back(v[rightmost]);
                        a.push_back(v[left]);
                        a.push_back(v[right]);
                        sort(a.begin(),a.end());
                        if(M.count(a) == 0){
                            ans.push_back(a);
                            M[a] = 1;
                        }
                    }
                    if(Sum > target){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
