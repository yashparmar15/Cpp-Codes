/*Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

 



 
Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
 

Note:

You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.*/


class Solution {
public:
    vector<int> lineNo = {
		  // 0 - top row, 1 - middle row, 2 - bottom row
          1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2  
        };
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for(auto& s:words){
            if(inOneLine(s)){
                result.push_back(s);
            }
        }
        return result;
    }
    bool inOneLine(string str){
        int line = lineNo[ tolower(str[0]) - 'a' ];
        for(int i=1;i<str.size();i++){
            if(lineNo[tolower(str[i]) - 'a'] != line)
                return false;
        }
        return true;
    }
};
