/*Lucy lives in house number X. She has a list of N house numbers in the society. Distance between houses can be determined by studying the difference between house numbers. Help her find out K's closest neighbors.
Note: If two houses are equidistant and Lucy has to pick only one, the house with the smaller house number is given preference.

Example 1:

Input:
N = 4, X = 0, K = 4
a[] = {-21, 21, 4, -12, 20}, 
Output:
-21 -12 4 20
Explanation:
The closest neighbour is house
number 4. Followed by -12 and 20. -21 and 21 
are both equal distance from X=0. Therefore, 
Lucy can only pick 1. Based on the given 
condition she picks -21 as it is the smaller 
of the two. 
Example 2:

Input:
N = 6, X = 5, K = 3 
a[] = {10, 2, 14, 4, 7, 6},
Output:
4 6 7 
Your Task:  
You don't need to read input or print anything. Complete the function  Kclosest() which takes the array arr[], size of array N, X, and K as input parameters, and returns the list of numbers

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ K ≤ N ≤ 105 
-104 ≤ X, arr[i] ≤ 104*/


class Solution{
    public:
    static bool Compare(pair<int,int> a,pair<int,int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        // Your code goes here 
        std:;priority_queue<pair<int,int>,std::vector<pair<int,int>>,std::function<bool(pair<int,int>, pair<int,int>)>> pq(Compare);
        for(int i = 0 ; i < arr.size() ; i++){
            pq.push(make_pair(arr[i],abs(arr[i] - x)));
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }  
};
