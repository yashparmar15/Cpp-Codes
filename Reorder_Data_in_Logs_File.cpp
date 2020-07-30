/*You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.*/


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>> let;
        vector<string> dig;
        for(int i = 0 ; i < logs.size() ; i++){
            bool space = false;
            int index = 0;
            for(int j = 0 ; j < logs[i].size() ; j++){
                if(logs[i][j] == ' '){
                    space = true;
                    index = j;
                }
                else{
                    if(space == true){
                        if(int(logs[i][j]) >= 48 and int(logs[i][j]) <= 57)
                            dig.push_back(logs[i]);
                        else
                            let.push_back(make_pair(logs[i].substr(j,logs[i].size()),logs[i].substr(0,j))); 
                        break;
                    }
                }
            }
        }
        sort(let.begin(),let.end());
        for(int i = 0 ; i < let.size() ; i++){
            logs[i] = let[i].second + let[i].first;
        }  
        for(int i = 0 ; i < dig.size() ; i++){
            logs[let.size() + i] = dig[i];
        } 
        return logs;
    }
};
