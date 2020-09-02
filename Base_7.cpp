/*Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].*/



class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool neg = false;
        if(num < 0) neg = true;
        num = abs(num);
        string ans = "";
        while(num){
            ans = to_string(num % 7) + ans;
            num = num / 7;
        }
        if(neg) ans = "-" + ans;
        return ans;
    }
};
