/*We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
 

Constraints:

1 <= hours.length <= 10000
0 <= hours[i] <= 16*/



class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> M;
        int cur_sum = 0;
        int ans = 0;
        M[0] = -1;
        for(int i = 0 ; i < hours.size() ; i++){
            hours[i] = hours[i] > 8 ? 1 : -1;
            cur_sum += hours[i];
            if(cur_sum > 0) ans = max(ans,i + 1);
            if(M.find(cur_sum) == M.end())
                M[cur_sum] = i;
            if(M.find(cur_sum - 1) != M.end())
                ans = max(ans,i - M[cur_sum - 1]);
        }
        return ans; 
    }
};
