/*There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be taller than the first and shorter than the second.
Can geek build the three-building recreational zone? 


Example 1:

Input:
N = 6
arr[] = {4, 7, 11, 5, 13, 2}
Output:
True
Explanation:
[4, 7, 5] fits the condition. 
Example 2:

Input:
N = 4
arr[] = {11, 11, 12, 9}
Output:
False
Explanation:
No 3 buildings fit the given condition. 

Your Task:
You don't need to read input or print anything. Complete the function recreationalSpot() which takes the array arr[] and its size N as input parameters and returns a boolean value based on whether his building selection was successful or not.
Note: The generated output will be "True" or "False".


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/


class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		int curmin = arr[0],curmax = arr[0];
		for(int i = 0 ; i < n ; i++){
		    curmin = min(curmin,arr[i]);
		    curmax = max(curmax,arr[i]);
		    if(arr[i] > curmin and curmax > arr[i]){
		        return true;
		    }
		}
		return false;
	}
};
