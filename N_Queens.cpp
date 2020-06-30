// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.


class Solution {
public:
    bool check(int i , int j , vector<pair<int,int>> positions){
        bool flag = true;
        for(int k = 0 ; k < positions.size() ; k++){
            int a = positions[k].first;
            int b = positions[k].second;
            if((a == i) or (b == j) or ((a + b) == (i + j)) or ((a - b) == (i - j))){
                return false;
            }
        }
        return true;
    }
    void recur(int n , vector<pair<int,int>> positions , vector<vector<string>> &ans , int count){
        if(count >= n){
            
            vector<string> sol;
            for(int i = 0 ; i < n ; i++){
                string temp;
                for(int j = 0 ; j < n ; j++){
                    bool flag = 0;
                    for(int k = 0 ; k < positions.size() ; k++){
                        if(positions[k].first == i and positions[k].second == j){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag)
                        temp = temp + "Q";
                    else
                        temp = temp + ".";
                }
                sol.push_back(temp);
            }
            ans.push_back(sol);
            return;
        }

            for(int j = 0 ; j < n ; j++){
                if(check(count,j,positions)){
                    positions.push_back(make_pair(count,j));
                    recur(n,positions,ans,count + 1);
                    positions.pop_back();
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<pair<int,int>> positions;
        int count = 0;
        recur(n,positions,ans,count);
        return ans;
    }
};