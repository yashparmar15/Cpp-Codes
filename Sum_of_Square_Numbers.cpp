/*Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
 

Example 2:

Input: 3
Output: False*/


class Solution {
public:
    bool judgeSquareSum(int n) {
        if(n==0)
            return true;
        for(long i=1;i*i<=n;i++)
        {
            long a = n-i*i;
            long b = sqrt(a);
            if(b*b==a)
                return true;
        }
        return false;
    }
};
