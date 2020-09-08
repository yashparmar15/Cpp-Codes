/*A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.*/



class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,bool> M;
        for(int i = 0 ; i < obstacles.size() ; i++)
            M[make_pair(obstacles[i][0],obstacles[i][1])] = 1;
        int ans = 0;
        int x = 0, y = 0;
        bool up = true,down = false,left = false,right = false;
        for(int i = 0 ; i < commands.size() ; i++){
            if(commands[i] == -1){
                if(up) {right = 1; up = 0;}
                else if(down) {left = 1; down = 0;}
                else if(left) {left = 0; up = 1;}
                else {right = 0; down = 1;}
            } 
            if(commands[i] == -2){
                if(up) {left = 1; up = 0;}
                else if(down) {right = 1; down = 0;}
                else if(left) {left = 0; down = 1;}
                else {right = 0; up = 1;}
            }
            if(commands[i] >= 1){
                if(up)
                    for(int j = 0 ; j < commands[i] ; j++){
                        if(M[make_pair(x,y+1)])
                            break;
                        y++;
                    }
                if(down)
                    for(int j = 0 ; j < commands[i] ; j++){
                        if(M[make_pair(x,y-1)])
                            break;
                        y--;
                    }
                if(left)
                    for(int j = 0 ; j < commands[i] ; j++){
                        if(M[make_pair(x-1,y)])
                            break;
                        x--;
                    }
                if(right)
                    for(int j = 0 ; j < commands[i] ; j++){
                        if(M[make_pair(x+1,y)])
                            break;
                        x++;
                    }
            }
            ans = max(ans,x * x + y * y);
        }
        return ans;
    }
};
