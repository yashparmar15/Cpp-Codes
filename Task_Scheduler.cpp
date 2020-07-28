/*You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].*/



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> H(26,0);
        for(int i = 0 ; i < tasks.size() ; i++){
            H[int(tasks[i]) - 65]++;
        }
        sort(H.begin(),H.end());
        reverse(H.begin(),H.end());
        int S = tasks.size();
        int ans = 0;
        int k = 0;
        vector<int> v;
        while(S){
            sort(H.begin(),H.end());
            reverse(H.begin(),H.end());
            int x = 0;
            int i = 0;
            while(i <= n){
                bool temp = true;
                while(x < 26){
                    if(H[x] != 0){
                        H[x]--;
                        i++;
                        x++;
                        S--;
                        v.push_back(1);
                        temp = false;
                        ans++;
                        break;
                    }
                    x++;
                }
                if(temp){
                    v.push_back(0);
                    ans++;i++;
                }
                
            }
        }
        // for(int i = 0 ; i < v.size() ; i++){
        //     cout << v[i] << " ";
        // }
        // cout << v.size() << endl;
        int t = v.size() - 1;
        while(v[t] == 0){
            v.pop_back();
            t--;
        }
        return v.size();
    }
};
