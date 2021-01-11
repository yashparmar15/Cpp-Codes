/*You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.*/


class Solution {
public:
    int maximumGain(string &s, int &x, int &y) {
        stack<pair<int,int>> stk;
        bool flag = x > y;
        int ans = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            bool temp = true;
            if(flag and s[i] == 'b'){
                if(!stk.empty() and stk.top().first == 'a'){
                    s[stk.top().second] = '-';
                    stk.pop();
                    ans += x;
                    temp = false;
                    s[i] = '-';
                }
            }
            if(!flag and s[i] == 'a'){
                if(!stk.empty() and stk.top().first == 'b'){
                    s[stk.top().second] = '-';
                    stk.pop();
                    ans += y;
                    temp = false;
                    s[i] = '-';
                }
            }
            if(temp) stk.push(make_pair(s[i],i));
        }
        while(!stk.empty()) stk.pop();
        for(int i = 0 ; i < s.size() ; i++){
            bool temp = true;
            if(s[i] == 'b'){
                if(!stk.empty() and stk.top().first == 'a'){
                    stk.pop();
                    ans += x;
                    temp = false;
                }
            }
            if(s[i] == 'a'){
                if(!stk.empty() and stk.top().first == 'b'){
                    stk.pop();
                    ans += y;
                    temp = false;
                }
            }
            if(temp and s[i] != '-') stk.push(make_pair(s[i],i));
        }
        return ans;
    }
};
