/*We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.*/



class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> M1,M2;
        A += " ",B += " ";
        string word = "";
        for(int i = 0 ; i < A.size() ; i++){
            if(A[i] == ' '){
                M1[word]++;
                word = "";
            } else
                word += A[i];
        }
        for(int i = 0 ; i < B.size() ; i++){
            if(B[i] == ' '){
                M2[word]++; 
                word = "";
            } else
                word += B[i];
        }
        vector<string> ans;
        for(auto m : M1)
            if(!M2[m.first] and m.second == 1) ans.push_back(m.first);
        for(auto m : M2)
            if(!M1[m.first] and m.second == 1) ans.push_back(m.first);
        return ans;
    }
};
