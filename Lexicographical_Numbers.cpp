/*Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.*/



class Solution {
public:
    vector<int> v;
    // static bool comp(int &a,int &b){
    //     string s1 = to_string(a);
    //     string s2 = to_string(b);
    //     return s1 < s2;
    // }
    void backtrack(int num,int &n){
        if(num > n) return;
        v.push_back(num);
        for(int i = 0 ; i <= 9 ; i++){
            backtrack(num * 10 + i,n);
        }
    }
    vector<int> lexicalOrder(int &n) {
        // vector<int> v;
        // for(int i = 1 ; i <= n ; i++)
        //     v.push_back(i);
        // sort(v.begin(),v.end(),comp);
        // return v;
        for(int i = 1 ; i <= 9 ; i++)
            backtrack(i,n);
        return v;
    }
};
