/*Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].*/

class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
    string reorganizeString(string S) {
        vector<pair<char,int>> H; 
        for(int i = 0 ; i < 26 ; i++)
            H.push_back(make_pair(char(i + 'a'),0));
        for(int i = 0 ; i < S.size() ; i++)
            H[int(S[i]) - 97].second++;
        sort(H.begin(),H.end(),comp);
        int count = 0;
        string ans = "";
        while(ans.size() != S.size()){
            bool flag = true;
            for(int i = 0 ; i < 26 ; i++){
                if(ans.size() == 0 and H[i].second){
                    ans += H[i].first;
                    H[i].second--;
                    flag = false;
                    break;
                }
                else{
                    if(H[i].first != ans[ans.size() - 1] and H[i].second){
                        ans += H[i].first;
                        H[i].second--;
                        flag = false;
                        break;
                    }
                }
            }
            sort(H.begin(),H.end(),comp);
            if(flag) return "";
        }
        return ans;
    }
};
