/*You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False*/

class Solution {
public:
    bool checkRecord(string s) {
        int A = 0 , L = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'A')
                A++,L = 0;
            if(A == 2)
                return 0;
            if(s[i] == 'L')
                L++;
            if(s[i] == 'P')
                L = 0;
            if(L == 3)
                return 0;
        }
        return 1;
    }
};
