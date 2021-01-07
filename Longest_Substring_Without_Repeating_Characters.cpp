class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int H[256];
        memset(H,0,sizeof(H));
        int prev = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int num = int(s[i]);
            H[num]++;
            if(H[num] == 1)
                ans = max(ans,i + 1 - prev);
            else {
                while(prev < i and H[num] != 1){
                    H[int(s[prev])]--;
                    prev++;
                }
            }
        }
        return ans;
    }
};
