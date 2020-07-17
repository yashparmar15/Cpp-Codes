/*Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.*/



class Solution {
public:
    string reformat(string s) {
        vector<char> alpha;
        vector<char> nume;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= '0' and s[i] <= '9')
                nume.push_back(s[i]);
            else
                alpha.push_back(s[i]);
        }
        if(alpha.size() > nume.size() + 1 or nume.size() > alpha.size() + 1)
            return "";
        string ans = "";
        if(alpha.size() > nume.size()){
            int i = 0 , j = 0;
            bool flag = true;
            while(i < alpha.size() or j < nume.size()){
                if(flag){
                    ans = ans + alpha[i];
                    i++;
                    flag = false;
                } else {
                    ans = ans + nume[j];
                    j++;
                    flag = true;
                }
            }
        } else {
            int i = 0 , j = 0;
            bool flag = true;
            while(i < alpha.size() or j < nume.size()){
                if(flag){
                    ans = ans + nume[j];
                    j++;
                    flag = false;
                } else {
                    ans = ans + alpha[i];
                    i++;
                    flag = true;
                }
            }
        }
        return ans;
    }
};
