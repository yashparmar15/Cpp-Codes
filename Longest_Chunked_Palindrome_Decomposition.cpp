/*Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:

Each a_i is a non-empty string;
Their concatenation a_1 + a_2 + ... + a_k is equal to text;
For all 1 <= i <= k,  a_i = a_{k+1 - i}.
 

Example 1:

Input: text = "ghiabcdefhelloadamhelloabcdefghi"
Output: 7
Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
Example 2:

Input: text = "merchant"
Output: 1
Explanation: We can split the string on "(merchant)".
Example 3:

Input: text = "antaprezatepzapreanta"
Output: 11
Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
Example 4:

Input: text = "aaa"
Output: 3
Explanation: We can split the string on "(a)(a)(a)".
 

Constraints:

text consists only of lowercase English characters.
1 <= text.length <= 1000
Accepted*/



class Solution {
public:
    int dp[1001][1001];
    int dfs(string &s,int start,int end){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        string t1 = "",t2 = "";
        int ii = 0;
        int temp = 0;
        for(int i = start ; i <= end ; i++){
            t1 += s[i];
            t2 = s[end - ii++] + t2;
            if(t1 == t2){
                if(i == end) temp = max(temp,1);
                else temp = max(temp,2 + dfs(s,i + 1,end - ii));
            }
        }
        return dp[start][end] = temp;
    }
    int longestDecomposition(string text) {
        memset(dp,-1,sizeof(dp));
        return dfs(text,0,text.size() - 1);
    }
};



// int res=1;
//     unordered_map<string,int> m;
//     int helper(string& s,int l,int r){
//         if(l>r) return 0;
//         if(m.count(s.substr(l,r-l+1))) return m[s.substr(l,r-l+1)];
//         for(int len=1;len<=(r-l+1)/2;len++){
//             if(s.substr(l,len)==s.substr(r-len+1,len))
//                 res=max(res,2+helper(s,l+len,r-len));
//         }
//         m[s.substr(l,r-l+1)]=res;
//         return res;
//     }
