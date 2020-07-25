/*In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].
Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].
Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].
Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.
 

Note:

1 <= tree.length <= 40000
0 <= tree[i] < tree.length*/



class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int c1 = 0 , c2 = 0;
        int q1 = -1 , q2 = -1;
        int ans = 0;
        for(int i = 0 ; i < tree.size() ; i++){
            if(q1 == -1){
                q1 = tree[i];
                c1++;
            } else {
                if(q2 == -1 and tree[i] != q1){
                    q2 = tree[i];
                    c2++;
                } else {
                    if(tree[i] == q1){
                        c1++;
                    } else {
                        if(tree[i] == q2){
                            c2++;
                        } else {
                            if(tree[i - 1] == q1){
                                c1 = 0;
                                int j = i - 1;
                                while(j >= 0 and tree[j] == tree[i - 1]){
                                    c1++;
                                    j--;
                                }
                                q2 = tree[i];
                                c2 = 1;
                            } else {
                                c2 = 0;
                                int j = i - 1;
                                while(j >= 0 and tree[j] == tree[i - 1]){
                                    c2++;
                                    j--;
                                }
                                q1 = tree[i];
                                c1 = 1;
                            }
                        }
                    }
                }
            }
            // cout << "q1 " << q1 << " c1 " << c1 << " q2 " << q2 << " c2 " << c2 << endl;
            ans = max(ans , c1 + c2);
        }
        return ans;
    }
};
