// Given two integers A and B, return any string S such that:

// S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
// The substring 'aaa' does not occur in S;
// The substring 'bbb' does not occur in S.
 

// Example 1:

// Input: A = 1, B = 2
// Output: "abb"
// Explanation: "abb", "bab" and "bba" are all correct answers.
// Example 2:

// Input: A = 4, B = 1
// Output: "aabaa"




class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int a=0,b=0;
        int sz=A+B;
        string ans="";
        for(int i=0;i<sz;i++)
            if((A>=B or b==2) and a!=2 and A!=0)
                ans+='a',a++,A--,b=0;
            else
                ans+='b',b++,a=0,B--;
        return ans;
    }
};