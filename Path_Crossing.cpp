/*Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise.

 

Example 1:



Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:



Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 10^4
path will only consist of characters in {'N', 'S', 'E', 'W}*/


class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_map<int,bool>> M;
        M[0][0] = 1;
        int x = 0,y = 0;
        for(int i = 0 ; i < path.size() ; i++){
            if(path[i] == 'N')
                y++;
            if(path[i] == 'S')
                y--;
            if(path[i] == 'E')
                x++;
            if(path[i] == 'W')
                x--;
            if(M[x][y])
                return 1;
            M[x][y] = 1;
        }
        return 0;
    }
};
