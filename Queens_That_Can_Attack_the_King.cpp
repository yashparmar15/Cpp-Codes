// On an 8x8 chessboard, there can be multiple Black Queens and one White King.

// Given an array of integer coordinates queens that represents the positions of the Black Queens, and a pair of coordinates king that represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.

 

// Example 1:



// Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
// Output: [[0,1],[1,0],[3,3]]
// Explanation:  
// The queen at [0,1] can attack the king cause they're in the same row. 
// The queen at [1,0] can attack the king cause they're in the same column. 
// The queen at [3,3] can attack the king cause they're in the same diagnal. 
// The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1]. 
// The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0]. 
// The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.


class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int M[8][8];
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++)
                M[i][j] = 0;
        }
        for(int i = 0 ; i < queens.size() ; i++){
            M[queens[i][0]][queens[i][1]] = 1;
        }
        M[king[0]][king[1]] = 2;
        vector<vector<int>> ans;
        for(int i = 0 ; i < queens.size() ; i++){
            int j = queens[i][0] + 1;
            int k = queens[i][1];
            while(j <= 7){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                j++;
            }
            j = queens[i][0];
            k = queens[i][1] + 1;
            while(k <= 7){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                k++;
            }
            j = queens[i][0];
            k = queens[i][1] - 1;
            while(k >= 0){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                k--;
            }
            j = queens[i][0] - 1;
            k = queens[i][1];
            while(j >= 0){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                j--;
            }
            j = queens[i][0] - 1;
            k = queens[i][1] - 1;
            while(j >= 0 and k >= 0){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                j--;
                k--;
            }
            j = queens[i][0] + 1;
            k = queens[i][1] + 1;
            while(j <= 7 and k <= 7){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                j++;
                k++;
            }
            j = queens[i][0] + 1;
            k = queens[i][1] - 1;
            while(j <= 7 and k >= 0){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                j++;
                k--;
            }
            j = queens[i][0] - 1;
            k = queens[i][1] + 1;
            while(j >= 0 and k <= 7){
                if(M[j][k] == 2){
                    vector<int> temp;
                    temp.push_back(queens[i][0]);
                    temp.push_back(queens[i][1]);
                    ans.push_back(temp);
                    break;
                }
                if(M[j][k] == 1)
                    break;
                j--;
                k++;
            }
        }
        return ans;
    }
};