/*Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false
 

Constraints:

1 <= n <= 107*/


class Solution {
public:
    bool ans = false;
    void recur(vector<int> &v,int &n,int sum,int index){
        if(ans) return;
        if(sum == n) {
            ans = true;
            return;
        }
        if(index == v.size() or sum > n) return;
        recur(v,n,sum + v[index],index + 1);
        recur(v,n,sum,index + 1);
    }
    bool checkPowersOfThree(int n) {
        vector<int> v;
        int i = 1;
        while(i <= n){
            v.push_back(i);
            i = i * 3;
        }
        recur(v,n,0,0);
        return ans;
    }
};
