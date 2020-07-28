/*You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
 

Note:

1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.*/


class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> flowersInGarden(n, -1);
        vector<vector<int>> graph(n);
        
        for(auto p: paths){
            graph[p[0] - 1].push_back(p[1] - 1);
            graph[p[1] - 1].push_back(p[0] - 1);
        }
        
        for(int garden = 0; garden < n; garden++){ // plant flower in each garden
            vector<bool> used(5, false);
            // get flower to be planted for each garden
            int flower = getFlower(graph[garden], flowersInGarden, used);
            if(flower != -1){
                flowersInGarden[garden] = flower;
                used[flower] = true; // or used[flowersInGarden[garden]]
            }
            
        }
        return flowersInGarden;
    }
private:
    int getFlower(vector<int> &adjG, vector<int> &flowersInGarden, vector<bool> &used){
      
        for(int flower = 1; flower <= 4; flower++){
            if(used[flower]) continue;
            bool isPlanted = false;
            for(auto g: adjG){
                if(flowersInGarden[g] != -1 && flowersInGarden[g] == flower){
                    isPlanted = true;
                    break;
                }
            }
            if(!isPlanted){
                return flower;
            }
        }
        return -1; // exhausted check for all flowers
    }
};
