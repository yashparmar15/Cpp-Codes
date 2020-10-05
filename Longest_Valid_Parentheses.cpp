class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int opening = 0;
        int closing = 0;
        int len = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(')
                opening++;
            else
                closing++;
            if(closing > opening){
                closing = 0;
                opening = 0;
            }
            if(closing == opening){
                len = closing + opening;
                if(len > maxLen){
                    maxLen = len;
                }
            }
        }
        opening = 0;
        closing = 0;
        for(int i = s.length() - 1 ; i >= 0 ; i--){
            if(s[i] == '(')
                opening++;
            else
                closing++;
            if(closing < opening){
                opening = 0;
                closing = 0;
            }
            if(closing == opening){
                len = closing + opening;
                if(len > maxLen){
                    maxLen = len;
                }
            }
        }
        return maxLen;
        
    }
};
