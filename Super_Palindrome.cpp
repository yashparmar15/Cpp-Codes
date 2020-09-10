/*Let's say a positive integer is a superpalindrome if it is a palindrome, and it is also the square of a palindrome.

Now, given two positive integers L and R (represented as strings), return the number of superpalindromes in the inclusive range [L, R].

 

Example 1:

Input: L = "4", R = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
 

Note:

1 <= len(L) <= 18
1 <= len(R) <= 18
L and R are strings representing integers in the range [1, 10^18).
int(L) <= int(R)*/


class Solution {
public:
    long long int r = 0, l = 0;
    unordered_map<string,int> M;
    bool check(string s){
        long long int num = 0;
        for(int i = 0 ; i < s.size() ; i++)
            num = num * 10 + s[i] - 48;
        if(num > 1e9) return 0;
        num = num * num;
        if(num >= l and num <= r){
            string temp1 = to_string(num);
            string temp2 = temp1;
            reverse(temp2.begin(),temp2.end());
            if(temp1 == temp2) {
                M[temp1]++;
                if(M[temp1] == 1)
                    return 1;
            }
            return 0;
        }
        return false;
    }
    int superpalindromesInRange(string L, string R) {
        for(int i = 0 ; i < L.size() ; i++)
            l = l * 10 + L[i] - 48;
        for(int i = 0 ; i < R.size() ; i++)
            r = r * 10 + R[i] - 48;
        long long int sl = sqrt(l);
        long long int sr = sqrt(r);
        if(sl * sl != l) sl += 1;
        if(sr * sr != r) sr += 1;
        int ans = 0;
        string temp;
        int i = 1;
        for(; i <= 32000 ; i++){
            temp = to_string(i);
            string t = temp;
            reverse(t.begin(),t.end());
            if(temp == t and check(temp)) ans++;
            if(check(temp + t)) ans++;
            temp.pop_back();
            if(temp.size() and check(temp + t)) ans++;
        }
        return ans;
    }
};
