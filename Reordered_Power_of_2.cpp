/*Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9*/


class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> store;
        int p=1;
        while(p<=1000000000)
        {
            store.push_back(p);
            p*=2;
        }
        store.push_back(p);
        for(auto it:store){
            string s1=to_string(n),s2=to_string(it);
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1==s2)
                return true;
        }
        return false;
    }
};
