class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        unordered_map<int,unordered_map<int,int>> M;
        for(int i = 0 ; i < points.size() ; i++){
            int x = points[i][0],y = points[i][1];
            M[x][y] = 1;
            v.push_back(make_pair(x,y));
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < v.size() ; i++){
            if(M[v[i].first][v[i].second] and M[v[i].first].size() > 1 )
            for(int j = i + 1 ; j < v.size() ; j++){
                int x1 = v[i].first,x2 = v[j].first;
                int y1 = v[i].second,y2 = v[j].second;
                if(x1 != x2 and y1 != y2 and M[x1][y2] and M[x2][y1]){
                    ans = min(ans,abs((x1 - x2) * (y1 - y2)));
                }
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};
