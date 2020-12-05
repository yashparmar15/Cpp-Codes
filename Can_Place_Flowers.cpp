/*You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length*/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int count = 0;
        if(v.size() == 1 and v[0] == 0) count++;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] == 0){
                if(i == 0){
                    if(i + 1 < v.size() and v[i + 1] != 1) {
                        count++;
                        v[i] = 1;
                    }
                } else {
                    if(i == v.size() - 1){
                        if(i - 1 >= 0 and v[i - 1] != 1) {
                            count++;
                            v[i] = 1;
                        }
                    } else {
                        if(v[i + 1] == 0 and v[i - 1] == 0){
                            count++;
                            v[i] = 1;
                        }
                    }
                }
            }
        }
        return n <= count;
    }
};
