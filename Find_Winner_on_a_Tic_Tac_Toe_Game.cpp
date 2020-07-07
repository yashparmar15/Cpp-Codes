// Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

// Here are the rules of Tic-Tac-Toe:

// Players take turns placing characters into empty squares (" ").
// The first player A always places "X" characters, while the second player B always places "O" characters.
// "X" and "O" characters are always placed into empty squares, never on filled ones.
// The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
// Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

// Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

// You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.



class Solution {
public:
    void check(string &ans,vector<vector<int>> grid){
        for(int i = 0 ; i < 3 ; i++){
            if(grid[i][0] == grid[i][1] and grid[i][1] == grid[i][2]){
                if(grid[i][0] == 1)
                    ans = "A";
                if(grid[i][0] == 2)
                    ans = "B";
            }
        }
        for(int i = 0 ; i < 3 ; i++){
            if(grid[0][i] == grid[1][i] and grid[1][i] == grid[2][i]){
                if(grid[0][i] == 1)
                    ans = "A";
                if(grid[0][i] == 2)
                    ans = "B";
            }
        }
        if(grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2]){
            if(grid[0][0] == 1)
                ans = "A";
            if(grid[0][0] == 2)
                ans = "B";
        }
        if(grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0]){
            if(grid[0][2] == 1)
                ans = "A";
            if(grid[0][2] == 2)
                ans = "B";
        }
        
    }
    string tictactoe(vector<vector<int>>& moves) {
        if(moves.size() <= 4)
            return "Pending";
        vector<vector<int>> grid;
        for(int i = 0 ; i < 3 ; i++){
            vector<int> temp;
            for(int j = 0 ; j < 3 ; j++){
                temp.push_back(0);
            }
            grid.push_back(temp);
        }
        int turn = 1;
        string ans = "";
        for(int i = 0 ; i < moves.size() ; i++){
            grid[moves[i][0]][moves[i][1]] = turn;
            if(turn == 1)
                turn = 2;
            else
                turn = 1;
            if(i > 3){
                ans = "";
                check(ans,grid);
                if(ans == "A")
                    return ans;
                if(ans == "B")
                    return ans;
            }
        }
        if(moves.size() == 9)
            return "Draw";
        return "Pending";
    }
};