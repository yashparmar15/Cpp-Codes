/*On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

Example 1:

Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
Example 2:

Input: target = "code"
Output: "RR!DDRR!UUL!R!"
 

Constraints:

1 <= target.length <= 100
target consists only of English lowercase letters.*/



class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0 , y = 0;
        string ans = "";
        for(int i = 0 ; i < target.size() ; i++){
            int num = int(target[i]) - 97;
            int rx = num / 5 , ry = num % 5;
            if(i != 0 and target[i] == target[i - 1])
                ans = ans + "!";
            else {
                if(target[i] == 'z'){
                    if(ry > y){
                        for(int j = 0 ; j < ry - y ; j++){
                            ans = ans + "R";
                        }
                    } else {
                        for(int j = 0 ; j <  y - ry ; j++){
                            ans = ans + "L";
                        }
                    }
                    if(rx > x){
                        for(int j = 0 ; j < rx - x ; j++){
                            ans = ans + "D";
                        }
                    } else {
                        for(int j = 0 ; j < x - rx ; j++){
                            ans = ans + "U";
                        }
                    }
                } else {
                    if(rx > x){
                        for(int j = 0 ; j < rx - x ; j++){
                            ans = ans + "D";
                        }
                    } else {
                        for(int j = 0 ; j < x - rx ; j++){
                            ans = ans + "U";
                        }
                    }
                    if(ry > y){
                        for(int j = 0 ; j < ry - y ; j++){
                            ans = ans + "R";
                        }
                    } else {
                        for(int j = 0 ; j <  y - ry ; j++){
                            ans = ans + "L";
                        }
                    }
                }
                ans = ans + "!";
                x = rx;
                y = ry;
            }
        }
        return ans;
    }
};
