// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:  

// 1 is typically treated as an ugly number.
// n does not exceed 1690.

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        vector<int> H(primes.size(),0);
        vector<int> next;
        for(int i = 0 ; i < primes.size() ; i++){
            next.push_back(primes[i]);
        }
        int next_ugly = 1;
        vector<int> ugly;
        ugly.push_back(1);
        if(n == 1)
            return 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < primes.size() ; j++){
                if(j == 0){
                    next_ugly = next[j];
                }
                else{
                    next_ugly = min(next_ugly , next[j]);
                }
            }
            ugly.push_back(next_ugly);
            for(int j = 0 ; j < primes.size() ; j++){
                if(next_ugly == next[j]){
                    H[j]++;
                    next[j] = ugly[H[j]]*primes[j];
                }
            }
        }
        return ugly[ugly.size() - 1];
    }
};