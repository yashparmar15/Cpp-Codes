/*Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.*/



class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0 , l = 0 , o = 0 , n = 0;
        for(int i = 0 ; i < text.size() ; i++){
            if(text[i] == 'b')
                b++;
            if(text[i] == 'a')
                a++;
            if(text[i] == 'l')
                l++;
            if(text[i] == 'o')
                o++;
            if(text[i] == 'n')
                n++;
        }
        l = l / 2;
        o = o / 2;
        return min(b,min(a,min(l,min(o,n))));
    }
};
