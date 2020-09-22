/*Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.*/


class Solution {
public:
    string fractionAddition(string s) {
        vector<int> num,deno;
        vector<char> op;
        for(int i = 0 ; i < s.size() ; i++){
            int n = 0,d = 0;
            if((s[i] == '-' or s[i] == '+') and i != 0){
                op.push_back(s[i]);
                continue;
            }
            bool temp = false;
            if(i == 0 and s[i] == '-')
                i++,temp = true;
            while(s[i] >= '0' and s[i] <= '9') n = n * 10 + int(s[i++]) - 48;
            i++;
            while(i < s.size() and s[i] >= '0' and s[i] <= '9') d = d * 10 + int(s[i++]) - 48;
            i--;
            if(temp) n = -n;
            num.push_back(n);
            deno.push_back(d);
        }
        int N = num[0],D = deno[0];
        for(int i = 1 ; i < num.size() ; i++){
            if(op[i - 1] == '+'){
                N = N * deno[i] + num[i] * D;
                D = deno[i] * D;
                int gcd = __gcd(N,D);
                N = N / gcd;
                D = D / gcd;
            } else {
                N = N * deno[i] - num[i] * D;
                D = deno[i] * D;
                int gcd = __gcd(N,D);
                N = N / gcd;
                D = D / gcd;
            }
        }
        string ans = "";
        if(D < 0) ans += "-",D = -D;
        ans += to_string(N) + "/" + to_string(D);
        return ans;
    }
};
