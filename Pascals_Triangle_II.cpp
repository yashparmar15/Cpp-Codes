/*Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]*/



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> temp;
        for(int i = 0 ; i <= rowIndex ; i++){
            vector<int> t;
            for(int j = 0 ; j <= i ; j++){
                if(j == 0 or j == i)
                    t.push_back(1);
                else{
                    t.push_back(temp[temp.size() - 1][j - 1] + temp[temp.size() - 1][j]);
                }
            }
            temp.push_back(t);
        }
        return temp[rowIndex];
    }
};
