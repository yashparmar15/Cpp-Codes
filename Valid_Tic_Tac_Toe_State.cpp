/*A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.*/


class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        int cx=cnt(b,'X'),co=cnt(b,'O');
        bool wx=win(b,'X'),wo=win(b,'O');
        if (wx && wo) return false;
        if (wx) return cx==co+1;
        if (wo) return cx==co;
        return cx==co+1 || cx==co;
    }
private:
    int cnt(vector<string>& b, char c){
        int res=0;
        for (auto& s: b) res+=count(s.begin(),s.end(),c);
        return res;
    }
    bool win(vector<string>& b, char c){
        for (int i=0; i<3; ++i) if (b[i][0]==c && b[i][1]==c && b[i][2]==c) return true;
        for (int j=0; j<3; ++j) if (b[0][j]==c && b[1][j]==c && b[2][j]==c) return true;
        return (b[0][0]==c && b[1][1]==c && b[2][2]==c)
            || (b[2][0]==c && b[1][1]==c && b[0][2]==c);
    }
};
