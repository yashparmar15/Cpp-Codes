/*Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 

Note:

1 <= words.length <= 2000.
1 <= words[i].length <= 7.
Each word has only lowercase letters.*/


class Solution {
public:
    static bool comp(string a,string b){
        return a.size() < b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int ans = 0;
        int count = 0;
        for(int i = 0 ; i < words.size() ; i++){
            ans = ans + words[i].size();
            count++;
            for(int j = i + 1 ; j < words.size(); j++){
                bool flag = true;
                for(int k = 0 ; k < words[i].size() ; k++){
                    if(words[i][words[i].size() - k - 1] != words[j][words[j].size() - k - 1]){
                        flag = false;
                        break;
                    }
                }
                if(flag){ 
                    ans -= words[i].size();
                    count--;
                    break;
                }
            }
        }
        return ans + count;
    }
};
