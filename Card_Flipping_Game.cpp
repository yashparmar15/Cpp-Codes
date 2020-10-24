/*On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).

We flip any number of cards, and after we choose one card. 

If the number X on the back of the chosen card is not on the front of any card, then this number X is good.

What is the smallest number that is good?  If no number is good, output 0.

Here, fronts[i] and backs[i] represent the number on the front and back of card i. 

A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.

Example:

Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.
 

Note:

1 <= fronts.length == backs.length <= 1000.
1 <= fronts[i] <= 2000.
1 <= backs[i] <= 2000.*/


class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans = INT_MAX;
        unordered_map<int,int> M;
        for(int i = 0 ; i < fronts.size() ; i++){
            M[fronts[i]]++;    
        }
        for(int i = 0 ; i < backs.size() ; i++){
            if(M[backs[i]] == 0) ans = min(ans,backs[i]);
            else {
                if(backs[i] == fronts[i]) continue;
                if(backs[i] < ans){
                    bool flag = true;
                    for(int j = 0 ; j < backs.size() ; j++){
                        if(j != i){
                            if(fronts[j] == backs[j] and backs[j] == backs[i]){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag) ans = backs[i];
                }
            }
        }
        for(int i = 0 ; i < backs.size() ; i++){
            M[fronts[i]]--;
            M[backs[i]]++;
            swap(backs[i],fronts[i]);
            if(M[backs[i]] == 0) ans = min(ans,backs[i]);
            else {
                if(backs[i] == fronts[i]) continue;
                if(backs[i] < ans){
                    bool flag = true;
                    for(int j = 0 ; j < backs.size() ; j++){
                        if(j != i){
                            if(fronts[j] == backs[j] and backs[j] == backs[i]){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag) ans = backs[i];
                }
            }
            swap(backs[i],fronts[i]);
            M[fronts[i]]++;
            M[backs[i]]--;
        }
        if(ans == INT_MAX) ans = 0;
        return ans;
    }
};
