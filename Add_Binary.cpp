/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.*/



class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        string ans;
        int i = 0;
        for(; i < min(a.size(),b.size()) ; i++){
            int Sum = carry + int(a[i]) + int(b[i]) - 96;
            if(Sum == 3){
                ans = ans + "1";
                carry = 1;
            } else {
                if(Sum == 2){
                    ans = ans + "0";
                    carry = 1;
                } else {
                    if(Sum == 1)
                        ans = ans + "1";
                    else
                        ans = ans + "0";
                    carry = 0;
                }
            }
        }
        for(int j = i ; j < a.size() ; j++){
            int Sum = carry + a[j] - 48;
            if(Sum == 2){
                ans = ans + "0";
                carry = 1;
            } else {
                if(Sum == 1)
                    ans = ans + "1";
                else
                    ans = ans + "0";
                carry = 0;
            }
        }
        for(int j = i ; j < b.size() ; j++){
            int Sum = carry + b[j] - 48;
            if(Sum == 2){
                ans = ans + "0";
                carry = 1;
            } else {
                if(Sum == 1)
                    ans = ans + "1";
                else
                    ans = ans + "0";
                carry = 0;
            }
        }
        if(carry)
            ans = ans + "1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
