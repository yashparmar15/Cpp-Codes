/*Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return True If you can find a way to do that or False otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
Example 4:

Input: arr = [-10,10], k = 2
Output: true
Example 5:

Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
Output: true
 

Constraints:

arr.length == n
1 <= n <= 10^5
n is even.
-10^9 <= arr[i] <= 10^9
1 <= k <= 10^5*/



class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(k == 1)
            return true;
        unordered_map<int,int> M;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] < 0){
                M[k - abs(arr[i]) % k]++;
            } else {
                M[arr[i] % k]++;
            }
        }
        for(auto m : M){
            cout << m.first << " " << m.second << " " << M[k - m.first] << endl;
            if(m.first == 0 or m.first == k){
                if(M[k]){
                    m.second = m.second - M[k];
                }
                if(m.second < 0)
                    return false;
                if(m.second % 2)
                    return false;
            }
            else{
                if(m.second != M[k - m.first])
                    return false;
            }
        }
        return true;
    }
};
