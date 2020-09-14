/*Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
 

Note:

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6*/


class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> X,Y;
        X.push_back(1);
        Y.push_back(1);
        int tx = x,ty = y;
        if(x != 1)
            while(1){
                X.push_back(x);
                x = x * tx;
                if(x > bound) break;
            }
        if(y != 1)
            while(1){
                Y.push_back(y);
                y = y * ty;
                if(y > bound) break;
            }
        unordered_map<int,int> M;
        for(int i = 0 ; i < X.size() ; i++)
            for(int j = 0 ; j < Y.size() ; j++)
                if(X[i] + Y[j] <= bound) M[X[i] + Y[j]] = 1;
        vector<int> ans;
        for(auto m : M)
            ans.push_back(m.first);
        return ans;
    }
};
