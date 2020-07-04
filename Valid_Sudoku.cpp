// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// A partially filled sudoku which is valid.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// Example 1:

// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
// Example 2:

// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being 
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
// The given board contain only digits 1-9 and the character '.'.
// The given board size is always 9x9.



bool row(vector<vector<char>>& board)
{
				// Check all rows valid or not
    
    for(int i=0;i<9;i++)
    {
    vector<int> rows(9,1);
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
                continue;
            rows[board[i][j]-'1']--;
            if(rows[board[i][j]-'1']<0)
            {
                // cout<<board[i][j]<<i<<j;
             
                return false;}
        }
    }
    return true;
    
}

bool col(vector<vector<char>>& board)
{
    // Check all columns valid or not
    for(int i=0;i<9;i++)
    {
        vector<int> cols(9,1);
        for(int j=0;j<9;j++)
        {
            if(board[j][i]=='.')
                continue;
            cols[board[j][i]-'1']--;
            if(cols[board[j][i]-'1']<0)
                return false;
        }
    }
    return true;
    
}

class Solution {
public:
    
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool l=row(board);
        bool m=col(board);
        // cout<<l<<m;
        if(l==false || m==false)
            return false;
        
        int a=0,b=0;
        for(int i=0;i<9;i++)
        {
            
            vector<int> check(9,1);
			
			// Checking sub- matrix of 3x3  
			// a & b here are staring points of those 9 sub-matrix
            for(int r=a;r<a+3;r++)
            {
                for(int c=b;c<b+3;c++)
                {
                    if(board[r][c]=='.')
                        continue;
                    
                    // cout<<check[board[r][c]-'1'];
                    check[board[r][c]-'1']--;
                    if(check[board[r][c]-'1']<0)
                    {
                        // cout<<board[r][c]<<r<<c;
                        return false;
                    }
                }
                
            }
            // cout<<"\n";
            
            b+=3;
            if(b==9)
            {
                b=0;
                a+=3;
            }
            
        }
        return true;
    }
};