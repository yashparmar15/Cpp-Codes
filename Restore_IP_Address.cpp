/*Given a string s containing only digits. Return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single points and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

0 <= s.length <= 3000
s consists of digits only.*/


class Solution {
public:
    
    void backtrack(string s , vector<string> &ans , vector<int> temp , int index , int len){
        if(temp.size() == 4 and len == s.size()){
            string t = "";
            for(int i = 0 ; i < temp.size() - 1 ; i++){
                t = t + to_string(temp[i]) + ".";
            }
            t = t + to_string(temp[temp.size() - 1]);
            ans.push_back(t);
            return;
        }
        if(s.size() == len)
            return;
        if(temp.size() >= 4)
            return;
        int num = 0;
        int x;
        if(index + 3 < s.size())
            x = index + 3;
        else
            x = s.size();
        for(int i = index ; i < x ; i++){
            num = num * 10 + int(s[i]) - 48;
            if(num <= 255){
                temp.push_back(num);
                backtrack(s,ans,temp,i + 1,len + (to_string(num)).size());
                temp.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> temp;
        int len = 0;
        backtrack(s,ans,temp,0,len);
        return ans;
    }
};
