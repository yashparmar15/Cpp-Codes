/*You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.*/



class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double ans=0;
        for(int i=0;i<p.size()-2;i++){
            for(int j=i+1;j<p.size()-1;j++){
                for(int k=j+1;k<p.size();k++){
                    int x1=p[i][0];
                    int x2=p[j][0];
                    int x3=p[k][0];
                    int y1=p[i][1];
                    int y2=p[j][1];
                    int y3=p[k][1];
                    ans = max(ans,0.5*(abs(x1*(y2-y3) - x2*(y1-y3) + x3*(y1-y2)))) ;
                }
            }
        }
        return ans;
    }
};
