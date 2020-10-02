/*Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"*/

class Solution {
public:
    string originalDigits(string s) {
        int n=s.length();
        if(!n)return "";
        int num[]={0,2,4,6,8,1,3,5,7,9};
        string word[]={"zero","two","four","six","eight","one","three","five","seven","nine"};
        char hint[]={'z','w','u','x','g','o','h','f','s','i'};
        vector<int> cnt(26,0);
        string ans="";
        for(auto it:s)cnt[it-'a']++;
        for(int i=0;i<=9;i++){
            int idx=hint[i]-'a';
            int count=cnt[idx];
            for(int j=0;j<word[i].length();j++)
                cnt[word[i][j]-'a']-=count;
            while(count--)
                ans+=to_string(num[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
