class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> flowersInGarden(n, -1);
        vector<vector<int>> graph(n);
        
        for(auto p: paths){
            graph[p[0] - 1].push_back(p[1] - 1);
            graph[p[1] - 1].push_back(p[0] - 1);
        }
        
        for(int garden = 0; garden < n; garden++){ 
            vector<bool> used(5, false);
            int flower = getFlower(graph[garden], flowersInGarden, used);
            if(flower != -1){
                flowersInGarden[garden] = flower;
                used[flower] = true; 
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
        return -1; 
    }
};
