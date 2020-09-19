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


/////////////////////////////////////////////////////

class Solution {
public:
    vector<int> ans;
    void backtrack(string temp,int &low,int &high,int &lowlen,int &highlen,int index){
        if(temp.size() >= lowlen and temp.size() <= highlen){
            int num = 0;
            for(int i = 0 ; i < temp.size() ; i++)
                num = num * 10 + int(temp[i]) - 48;
            if(num >= low and num <= high)
                ans.push_back(num);
        }
        for(int i = index ; i <= 9 ; i++){
            if(temp.size() == 0)
                backtrack(temp + to_string(i),low,high,lowlen,highlen,i+1);
            else if(int(i) == int(temp[temp.size() - 1]) - 47)
                backtrack(temp + to_string(i),low,high,lowlen,highlen,i+1);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        int lowlen = to_string(low).size();
        int highlen = to_string(high).size();
        string temp = "";
        backtrack(temp,low,high,lowlen,highlen,1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
