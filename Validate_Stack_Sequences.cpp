/*Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.*/



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() == 0)
            return 1;
        bool flag = true;
        stack<int> s;
        int first = 0,second = 0;
        while(1){
            while(first < pushed.size() and pushed[first] != popped[second]){
                s.push(pushed[first]);
                first++;
            }
            if(first >= pushed.size())
                return false;
            if(pushed[first] == popped[second]){
                s.push(pushed[first]);
                while(second < popped.size() and !s.empty() and s.top() == popped[second]){
                    s.pop();
                    second++;
                    if(s.empty() and second >= popped.size() - 1 and first >= pushed.size() - 1)
                        return true;
                }
                first++;
            } else return false;
            
            if(s.empty() and second >= popped.size() - 1)
                return true;
        }
        return true;
    }
};
