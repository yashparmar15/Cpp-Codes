/*Given an integer array of size  N . You have to find sum of bit differences in all pairs that can be formed from array elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Example 1:

Input: N = 2, arr[] = {1, 2}
Output: 4
Explanation: All possible pairs are [(1,1) (1,2) 
(2,1) (2,2)] their respective Bit differences 
are 0 ,  2 , 2 , 0

Example 2:

Input: N = 5, arr[] = {3, 5, 2, 5, 2}
Output: 36
Your Task:  
You don't need to read input or print anything. Complete the function sumBitDiff() which takes the array a[] and size of array N as input parameters and returns the answer

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ arr[i] ≤ 108*/


class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
        // Your code goes here
        //  011 //  322
        //  101     233    
        //  010
        //  101
        //  010
        //  110  323  343
        vector<int> zero(50,0),one(50,0);
        for(int i = 0 ; i < n ; i++){
            int num = arr[i];
            int index = 0;
            while(num > 0){
                int temp = num % 2;
                if(temp) one[index]++;
                else zero[index]++;
                index++;
                num = num / 2;
            }
        }
        long long int ans = 0;
        for(int i = 0 ; i < 50 ; i++){
            if(one[i] == 0 and zero[i] == 0) break;
            // cout << one[i] << " " << zero[i] << endl;
            ans += one[i] * (n - one[i]);
        }
        return ans * 2;
    } 
};
