// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
 

// Now given N, how many beautiful arrangements can you construct?

// Example 1:

// Input: 2
// Output: 2
// Explanation: 

// The first beautiful arrangement is [1, 2]:

// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

// The second beautiful arrangement is [2, 1]:

// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.


class Solution {
public:
    void recur(int N , vector<int> &temp , int &ans , int index){
        if(index == N + 1){
            ans++;
            return;
        }
        for(int i = 1 ; i <= N ; i++){
            if((index % i == 0 or i % index == 0) and !temp[i]){
                temp[i] = true;
                recur(N,temp,ans,index + 1);
                temp[i] = false;
            }
        }
    }
    int countArrangement(int N) {
        int ans = 0;
        vector<int> temp(N + 1, false);
        recur(N,temp,ans,1);
        return ans;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    bool check(vector<int> temp,int x){
        for(int i = 0 ; i < temp.size() ; i++){
            if(temp[i] == x)
                return false;
        }
        return 1;
    }
    void recur(int N , vector<int> temp , int &ans){
        if(temp.size() == N){
            ans++;
            return;
        }
        for(int i = 1 ; i <= N ; i++){
            if(((temp.size()+1) % i == 0 or i % (temp.size()+1) == 0) and check(temp,i)){
                temp.push_back(i);
                recur(N,temp,ans);
                temp.pop_back();
            }
        }
    }
    int countArrangement(int N) {
        int ans = 0;
        vector<int> temp;
        recur(N,temp,ans);
        return ans;
    }
};