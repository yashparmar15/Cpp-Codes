/*In a list of songs, the i-th song has a duration of time[i] seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Note:

1 <= time.length <= 60000
1 <= time[i] <= 500*/



class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> M;
        for(int i = 0 ; i < time.size() ; i++){
            M[time[i] % 60]++;
        }
        int ans = 0;
        for(auto m : M){
            if(m.first == 0 or m.first == 30){
                ans = ans + m.second * (m.second - 1) / 2;
            } else {
                ans = ans + m.second * (M[60 - m.first]);
                M[m.first] = 0;
                M[60 - m.first] = 0;
            }
        }
        return ans;
    }
};
