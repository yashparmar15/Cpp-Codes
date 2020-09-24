/*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> d(wordList.begin(), wordList.end());
        if(d.count(endWord) == 0) return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty()){
            res++;
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                auto curr = q.front();
                if(curr == endWord) return res;
                q.pop();
                for(int j = 0; j < curr.size(); j++){
                    auto tmp = curr[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        curr[j] = c;
                        if(d.count(curr) != 0){
                            d.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = tmp;
                }
            }
        }
        return 0;
    }
};
