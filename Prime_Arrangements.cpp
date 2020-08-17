/*Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
Example 2:

Input: n = 100
Output: 682289015
 

Constraints:

1 <= n <= 100*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    bool isPrime(int n){
        if(n == 0 || n == 1)    return 0;
        if(n == 2 || n == 3)    return 1;
        if(n % 2 == 0 || n % 3 == 0)    return 0;
        for(int i = 5;i * i <= n;i+=6){
            if(n % i == 0 || n % (i + 2) == 0)  return 0;
        }
        return 1;
    }
    
    int fact(int n){
        long long val = 1;
        for(int i = 1;i <= n;i++){
            val = ((val % MOD) * (i % MOD)) % MOD;
        }
        return (val % MOD);
    }
    
    int numPrimeArrangements(int n) {
        long long primes = 0;
        for(int i = 1;i<=n;i++){
            primes += isPrime(i);
        }
        long long intPrimes = n - primes;
        primes = fact(primes)%MOD;
        intPrimes = fact(intPrimes) % MOD;
        
        return (primes * intPrimes) % MOD;
    }
};
