/*Given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

 

Example 1:


Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
Example 2:


Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
Example 4:

Input: root = [100], distance = 1
Output: 0
Example 5:

Input: root = [1,1,1], distance = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 2^10].
Each node's value is between [1, 100].
1 <= distance <= 10*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> recur(TreeNode* root,int distance,int &ans){
        if(!root)
            return {0};
        if(root->left == NULL and root->right == NULL)
            return {1};
        vector<int> left = recur(root->left,distance,ans);
        vector<int> right = recur(root->right,distance,ans);
        for(auto l : left){
            for(auto r : right){
                if(l + r <= distance and l and r)
                    ans++;
            }
        }
        vector<int> res;
        for(auto l : left){
            if(l > 0 and l < distance)
                res.push_back(l + 1);
        }
        for(auto r : right){
            if(r > 0 and r < distance)
                res.push_back(r + 1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        recur(root,distance,ans);
        return ans;
    }
};
