/*Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

Example 1:

Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: arr[0] = 1 and arr[arr[0]]
= 0.Also, arr[1] = 0 and arr[arr[1]] = 1.
So, rearranging elements, we get array 
as, 0 1.
Example 2:

Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1
Explanation: arr[0] = 4 and arr[arr[0]] 
= 3. Also, arr[1] = 0 and arr[arr[1]] 
= 4 and so on. So, rearranging elements,
we get array as 3 4 2 0 1.
Your Task:
The task is to complete the function arrange() which arranges the elements in the array. The printing is done automatically done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 107
0 <= Arr[i] < N*/


void arrange(long long arr[], int n) {
    // Your code here
    //  4           0           2           1           3
    //  30000004
    for(int i = 0 ; i < n ; i++){
        if(arr[arr[i]] > 100000000){
            arr[i] = (arr[arr[i]] % 100000000) * 100000000 + arr[i];
        } else {
            arr[i] = arr[arr[i]] * 100000000 + arr[i];
        }
    }
    for(int i = 0 ; i < n ; i++){
        arr[i] = arr[i] / 100000000;
        if(arr[i] == 100000000) arr[i] = 0;
    }
}
