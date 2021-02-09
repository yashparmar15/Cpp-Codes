/*Given a string S and an integer K, the task is to reduce the string by applying the following operation:
Choose a group of K consecutive identical characters and remove them. The operation can be performed any number of times until it is no longer possible.

Example 1:

Input:
K = 2
S = "geeksforgeeks"
Output:
gksforgks
Explanation:
Modified String after each step: 
"geegsforgeeks" -> "gksforgks"
Example 2:

Input:
K = 2
S = "geegsforgeeeks" 
Output:
sforgeks
Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"
Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String() which takes integer K and string S as input parameters and returns the reduced string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)*/


class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k == 1) return "";
        stack<pair<char,int>> stk;
        for(int i = 0 ; i < s.size() ; i++){
            if(stk.empty()){
                stk.push(make_pair(s[i],1));
            } else {
                if(s[i] == stk.top().first){
                    int num = stk.top().second + 1;
                    stk.pop();
                    if(num != k){
                        stk.push(make_pair(s[i],num));
                    }
                } else {
                    stk.push(make_pair(s[i],1));
                }
            }
        }
        string ans = "";
        while(!stk.empty()){
            char c = stk.top().first;
            int num = stk.top().second;
            while(num--){
                ans += c;
            }
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};
