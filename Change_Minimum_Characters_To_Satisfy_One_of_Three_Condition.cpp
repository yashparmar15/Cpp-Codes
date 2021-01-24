/*You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

Your goal is to satisfy one of the following three conditions:

Every letter in a is strictly less than every letter in b in the alphabet.
Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.
Return the minimum number of operations needed to achieve your goal.

 

Example 1:

Input: a = "aba", b = "caa"
Output: 2
Explanation: Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).
Example 2:

Input: a = "dabadd", b = "cda"
Output: 3
Explanation: The best way is to make condition 1 true by changing b to "eee".
 

Constraints:

1 <= a.length, b.length <= 105
a and b consist only of lowercase letters.*/


class Solution {
public:
    int minCharacters(string a, string b) {
        int H1[26],H2[26];
        memset(H1,0,sizeof(H1));
        memset(H2,0,sizeof(H2));
        for(int i = 0 ; i < a.size() ; i++)
            H1[a[i] - 'a']++;
        for(int j = 0 ; j < b.size() ; j++)
            H2[b[j] - 'a']++;
        int ans;
        int maxx = 0;
        int choice1 = 0;
        for(int i = 0 ; i < 26 ; i++)
            maxx = max(maxx,H1[i]);
        choice1 = a.size() - maxx;
        maxx = 0;
        for(int i = 0 ; i < 26 ; i++)
            maxx = max(maxx,H2[i]);
        choice1 += b.size() - maxx;
        ans = choice1;
        if(!H1[25]){
            int index = 27;
            for(int i = 1 ; i < 26 ; i++){
                if(H2[i]) {
                    index = i;
                    break;
                }
            }
            int temp = 0;
            int num = H2[0];
            // cout << index << " " << num << endl;
            for(int i = index ; i < 26 ; i++){
                temp = 0;
                for(int j = i ; j < 26 ; j++){
                    temp += H1[j];
                }
                // cout << temp + num << " " << i << endl;
                ans = min(ans,temp + num);
                num += H2[i];
            }
        }
        if(!H2[25]){
            int index = 27;
            for(int i = 1 ; i < 26 ; i++){
                if(H1[i]) {
                    index = i;
                    break;
                }
            }
            int temp = 0;
            int num = H1[0];
            for(int i = index ; i < 26 ; i++){
                temp = 0;
                for(int j = i ; j < 26 ; j++){
                    temp += H2[j];
                }
                ans = min(ans,temp + num);
                num += H1[i];
            }
        }
        return ans;
    }
};

