/*Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.*/



class Solution {
public:
    static bool comp(pair<string,int> a , pair<string,int> b){
        if(a.second != b.second)
            return a.second > b.second;
        for(int i = 0 ; i < min(a.first.size(),b.first.size()) ; i++){
            if(a.first[i] != b.first[i])
                return a.first[i] < b.first[i];
        }
        if(a.first.size() > b.first.size())
            return 0;
        return 1;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<string,int>> v;
        unordered_map<string,int> M;
        for(int i = 0 ; i < words.size() ; i++){
            M[words[i]]++;
        }
        for(auto m : M){
            v.push_back(make_pair(m.first,m.second));
        }
        sort(v.begin(),v.end(),comp);
        for(int i = 0 ; i < k ; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
