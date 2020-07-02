// Write an algorithm to determine if a number n is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Return True if n is a happy number, and False if not.

// Example: 

// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1


class Solution {
public:
    bool isHappy(int n) {
        while(1){
            string s = to_string(n);
            // cout<<s<<" ";
            if(s.size() == 1){          //5 25 29 85 
                if(s[0] == '1')         //4 16 37
                    return 1;           //3 9 81 65 61 37 58  
                                        //6 36 45 41 17 50 25 
                                        //8 
                if(s[0] <= '6' or s[0] == '9')
                    return 0;
            }
            n = 0;
            for(int i = 0 ; i < s.size() ; i++){
                int a = int(s[i]) - 48;
                n = n + a*a; 
            }
        }
    }
};