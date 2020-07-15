/* Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1)
            return true;
        while(n != 0)
        {
            if(n == 2)
                return true;
            if(n % 2 != 0 && n != 1)
                return false;
            n/=2;
        }
        return false;
    }
};
