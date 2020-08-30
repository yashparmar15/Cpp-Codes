/*Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"*/


class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        string sp = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= '0' and s[i] <= '9'){
                int x = 0;
                while(i < s.size() and s[i] >= '0' and s[i] <= '9')
                    x = x * 10 + int(s[i++]) - 48;
                i--;
                num.push(x);
            }
            else
                if(s[i] == ']'){
                    sp += s[i];
                    sp += to_string(num.top());
                    num.pop();
                }
                else sp += s[i];
        }
        stack<string> stk;
        for(int i = 0 ; i < sp.size() ; i++){
            if(isalpha(sp[i])){
                string temp = "";
                while(i < sp.size() and isalpha(sp[i]))
                    temp += sp[i++];
                i--;
                stk.push(temp);
            } else {
                if(sp[i] == '[')
                    stk.push("[");
                else{
                    if(sp[i] == ']'){
                        int x = 0;
                        int j = i + 1;
                        while(j < sp.size() and sp[j] >= '0' and sp[j] <= '9')
                            x = x * 10 + int(sp[j++]) - 48;
                        i = j - 1;
                        string temp = "";
                        while(stk.top() != "["){
                            temp = stk.top() + temp;
                            stk.pop();
                        }
                        stk.pop();
                        string req = "";
                        for(int k = 0 ; k < x ; k++)
                            req += temp;
                        stk.push(req);
                    }
                }
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
