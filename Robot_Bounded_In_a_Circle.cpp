/*On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}*/



class Solution {
public:
    bool isRobotBounded(string s) {
        int n = s.size();
        s += s;
        s += s;
        int x = 0,y = 0;
        int dir = 1;
        vector<pair<int,int>> v;
        bool flag = false;
        bool ans = true;
        int len = 0;
        bool g = false;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'G'){
                if(dir == 1) y++;
                if(dir == 2) x++;
                if(dir == 3) y--;
                if(dir == 4) x--;
                g = true;
            } 
            if(s[i] == 'L'){
                dir = dir - 1;
                if(dir == 0) dir = 4;
            }
            if(s[i] == 'R'){
                dir = dir + 1;
                if(dir == 5) dir = 1;
            }
            if(!flag)
                v.push_back(make_pair(x,y));
            if(flag){
                auto temp = v[(i - len) % len];
                if(temp.first != x && temp.second != y)
                    ans = false;
            }
            if(x == 0 and y == 0){
                if(i == s.size() - 1 or i == n - 1)
                    return true;
                if(g){
                    flag = true;
                    len = v.size();
                }
            }
        }
        if(!flag) return false;
        return ans;
    }
};
