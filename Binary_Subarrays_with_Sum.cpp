/*In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.*//



class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if(A.size() == 0)
            return 0;
        if(S == 0){
            int count = 0;
            int ans = 0;
            for(int i = 0 ; i < A.size() ; i++){
                if(A[i]){
                    ans = ans + count * (count + 1) / 2;
                    count = 0;
                } else {
                    count++;
                }
            }
            if(count)
                ans = ans + count * (count + 1) / 2;
            return ans;
        }
        int ans = 0;
        int prev = 0 , after = 0 , i = 0 , count = 0,index = 0;
        for(; i < A.size() ; i++){
            if(A[i] == 1){
                count++;
                if(count == 1)
                    index = i;
            } 
            if(count == 0)
                prev++;
            if(count == S)
                break;
        }
        for(; i < A.size() ; i++){
            if(A[i] == 1){
                int j = i + 1;
                while(j < A.size() and A[j] != 1){
                    j++;
                    after++;
                }
                j--;
                i = j;
                ans = ans + (prev + 1)*(after + 1);
                after = 0;
                prev = 0;
                j = index + 1;
                while(j < A.size() and A[j] != 1){
                    prev++;
                    j++;
                }
                index = j;
            }
        }
        return ans;
    }
};
