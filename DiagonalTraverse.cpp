/*Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.*/


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
        vector<int> temp;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i].first % 2 == 0){
                if(temp.size()){
                    reverse(temp.begin(),temp.end());
                    for(int j = 0 ; j < temp.size() ; j++){
                        ans.push_back(temp[j]);
                    }
                }
                temp.clear();
                ans.push_back(v[i].second.second);
            }
            else{
                temp.push_back(v[i].second.second);
            }
        }
        if(temp.size()){
            reverse(temp.begin(),temp.end());
            for(int j = 0 ; j < temp.size() ; j++){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};
