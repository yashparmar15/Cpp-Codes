/*Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.
 

Constraints:

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length*/

class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size() % k)
            return false;
        unordered_map<int,int> M;
        for(int i = 0 ; i < nums.size() ; i++){
            M[nums[i]]++;
        }
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(M[nums[i]] > 0){
                cout << nums[i] << endl;
                for(int j = nums[i] ; j < nums[i] + k ; j++){
                    if(M[j] <= 0)
                        return false;
                    M[j]--;
                }
                count++;
            }
            if(count == nums.size() / k)
                return true;
        }
        if(count != nums.size() / k)
            return false;
        return true;
    }
};

