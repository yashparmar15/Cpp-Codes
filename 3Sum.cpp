// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        map<vector<int>,int> M;
        int N = v.size();
        sort(v.begin(),v.end());
        for(int i = 0 ; i < N - 2 ; i++){
            if(i == 0 or v[i] != v[i-1]){
                int left = i + 1;
                int right = N - 1;
                while(left < right){
                    int Sum = v[i] + v[right] + v[left];
                    if(Sum == 0){
                        vector<int> a;
                        a.push_back(v[i]);
                        a.push_back(v[left]);
                        a.push_back(v[right]);
                        if(M.count(a) == 0){
                            ans.push_back(a);
                            M[a] = 1;
                        }
                        
                    }
                    if(Sum > 0){
                        right --;
                    }
                    else{
                        left ++;
                    }
                }
            }
        }
        return ans;
    }
};