// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

// Example:

// Input: 2
// Output: 91 
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
//              excluding 11,22,33,44,55,66,77,88,99


class Solution {
public:
    void recur(vector<bool> &temp , int &count , int n , vector<int> v){
        if(v.size() >= n)
            return;
        for(int i = 0 ; i <= 9 ; i++){
            if(v.size() == 0 and i == 0) continue;
            if(!temp[i]){
                count++;
                temp[i] = 1;
                v.push_back(i);
                recur(temp,count,n,v);
                temp[i] = 0;
                v.pop_back();
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int count = 1;
        vector<bool> temp(10,false);
        vector<int> v;
        recur(temp,count,n,v);
        return count;
    }
};