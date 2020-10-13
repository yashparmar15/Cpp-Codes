class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        string ar = a,br = b;
        reverse(ar.begin(),ar.end());
        reverse(br.begin(),br.end());
        if(ar == a or br == b or a[0] == br[0] or b[0] == ar[0]) return true;
        return false;
    }
};
