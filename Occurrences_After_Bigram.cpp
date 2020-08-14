/*Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Note:

1 <= text.length <= 1000
text consists of space separated words, where each word consists of lowercase English letters.
1 <= first.length, second.length <= 10*/



class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        string word = "";
        vector<string> t;
        for(int i = 0 ; i < text.size() ; i++){
            if(text[i] == ' '){
                t.push_back(word);
                word = "";
            } else {
                word = word + text[i];
            }
        }
        if(word.size())
            t.push_back(word);
        for(int i = 0 ; i < t.size() - 2 ; i++){
            if(t[i] == first and t[i + 1] == second)
                ans.push_back(t[i + 2]);
        }
        return ans;
    }
};
