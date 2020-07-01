// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]


class Solution {
public:
    void recur(int low , int high , vector<int> &ans , int num){
        if(num >= low and num <= high){
            ans.push_back(num);
        }
        if(num > high)
            return;
        for(int i = 1 ; i <= 9 ; i++){
            if(num == 0 or i == num % 10 + 1){
                num = num * 10 + i;
                recur(low,high,ans,num);
                num = num - i;
                num = num / 10;   
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int num = 0;
        recur(low,high,ans,num);
        sort(ans.begin(),ans.end());
        return ans;
    }
};