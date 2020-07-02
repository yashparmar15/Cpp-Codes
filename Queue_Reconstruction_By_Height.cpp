// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

 
// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]




class Solution {
public:
    static bool comp(vector<int> x , vector<int> y){
        if(x[0] == y[0])
            return x[1] < y[1];
        return x[0] < y[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>> ans;
        vector<int> temp = {-1,-1};
        for(int i = 0 ; i < people.size() ; i++){
            ans.push_back(temp);
        }
        for(int i = 0 ; i < people.size() ; i++){
            int count = 0;
            for(int j = 0 ; j < people.size() ; j++){
                if(ans[j][0] == -1 and ans[j][1] == -1 or ans[j][0] >= people[i][0] )
                    count++;
                if(count == people[i][1] + 1 and ans[j][0] == -1 and ans[j][1] == -1){
                    ans[j] = people[i];
                    break;
                }
            }
        }
        return ans;
    }
};