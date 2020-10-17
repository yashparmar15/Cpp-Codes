/*All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.*/



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        unordered_map<string,int> M;
        for(int i = 0 ; i <= s.size() - 10 ; i++){
            string temp = "";
            for(int j = i ; j < i + 10 ; j++)
                temp += s[j];
            M[temp]++;
        }
        vector<string> ans;
        for(auto m : M){
            if(m.second > 1) ans.push_back(m.first);
        }
        return ans;
    }
};
