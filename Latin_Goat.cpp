/*A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.*/


  class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> words;
        string word = "";
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] == ' '){
                words.push_back(word);
                word = "";
            } else {
                word = word + S[i];
            }
        }
        if(word.size())
            words.push_back(word);
        string ans = "";
        string a = "a" , temp = "";
        for(int i = 0 ; i < words.size() ; i++){
            char c = words[i][0];
            temp = "";
            if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
                temp = temp + words[i] + "ma" + a;
            } else {
                temp = temp + words[i].substr(1,words[i].size()) + words[i][0] + "ma" + a;
            }
            ans = ans + temp + " ";
            a = a + 'a';
        }
        ans.pop_back();
        return ans;
    }
};
