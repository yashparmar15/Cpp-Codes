/*Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will the same.

 

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
Example 3:

Input: houses = [1,5], heaters = [2]
Output: 3
 

Constraints:

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109*/



class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = INT_MIN;
        std::vector<int>::iterator low1,low2;
        sort(begin(heaters), end(heaters));
        for(int i = 0 ; i < houses.size() ; i++){
            low1 = std::lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int index1 = low1 - heaters.begin();
            low2 = std::upper_bound(heaters.begin(), heaters.end(), houses[i]);
            int index2 = low2 - heaters.begin();
            if(index2 == heaters.size()) index2--;
            if(index1 == heaters.size()) index1--;
            int val = INT_MAX;
            val = min(val,abs(heaters[index1] - houses[i]));
            val = min(val,abs(heaters[index2] - houses[i]));
            if(index1 + 1 < heaters.size())
                val = min(val,abs(heaters[index1 + 1] - houses[i]));
            if(index2 + 1 < heaters.size())
                val = min(val,abs(heaters[index2 + 1] - houses[i]));
            if(index1 - 1 >= 0)
                val = min(val,abs(heaters[index1 - 1] - houses[i]));
            if(index2 - 1 >= 0)
                val = min(val,abs(heaters[index2 - 1] - houses[i]));
            ans = max(ans,val);
        }
        return ans;
    }
};
