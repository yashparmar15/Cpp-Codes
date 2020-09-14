/*Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).

The returned string must have no leading zeroes, unless the string is "0".

 

Example 1:

Input: 2
Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
Example 2:

Input: 3
Output: "111"
Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
Example 3:

Input: 4
Output: "100"
Explantion: (-2) ^ 2 = 4
 

Note:

0 <= N <= 10^9*/


class Solution {
public:
    string baseNeg2(int N) {
        if(N == 0) return "0";
        string ans = "";
        while(N){
            ans = to_string(abs(N % 2)) + ans;
            if(abs(N) % 2){
                if(N < 0) N = N / -2 + 1;
                else N = N / -2;
            } else {
                N = N / -2;
            }
        }
        return ans;
    }
};
