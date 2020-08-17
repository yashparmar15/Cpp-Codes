/*Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */
 
 
 class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int result = 0;
        unordered_map<int, int> umap;
        for(int i=0; i<p.size() ; i++){
            for(int j=0 ; j<p.size() ; j++){
                int d = pow(p[j][1] - p[i][1], 2) + pow(p[j][0] - p[i][0], 2);
                result += 2 * umap[d]++;
            }
            umap.clear();
        }
        return result; 
    }
};
