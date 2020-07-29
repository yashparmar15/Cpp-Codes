class Solution {
public:
    static bool comp(pair<int,pair<int,int>> x , pair<int,pair<int,int>> y){
        return x.first < y.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0 ; i < points.size() ; i++){
            v.push_back(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1],make_pair(points[i][0],points[i][1])));                  }
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> ans;
        for(int i = 0 ; i < K ; i++){
            vector<int> temp;
            temp.push_back(v[i].second.first);
            temp.push_back(v[i].second.second);
            ans.push_back(temp);
        }
        return ans;
    }
};
