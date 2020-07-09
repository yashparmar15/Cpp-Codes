// Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

// Example 1:

// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
// Example 2:

// Input: 

//           1
//          /  
//         3    
//        / \       
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
// Example 3:

// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
// Example 4:

// Input: 

//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


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
    int widthOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<TreeNode*>> v;
        queue<TreeNode*> q;
        if(root == NULL)
            return 0;
        q.push(root);
        int count = 0;
        int s = q.size();
        int st = s;
        while(!q.empty()){
            if(count >= st-1 and  count > 8)
                break;
            if(count == st)
                break;
            s = q.size();
            st = s;
            count = 0;
            vector<TreeNode*>t;
            while(s--){
                TreeNode* temp = q.front();
                t.push_back(temp);
                q.pop();
                TreeNode* New = new TreeNode(INT_MIN);
                if(temp->left)
                    q.push(temp->left);
                else
                    q.push(New);
                if(temp->right)
                    q.push(temp->right);
                else
                    q.push(New);
                if(temp->val == INT_MIN)
                    count++;
            }
            
            v.push_back(t);
        }
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++){
            int x = 0;
            int y = v[i].size() - 1;
            while(x < v[i].size() and v[i][x]->val == INT_MIN)
                x++;
            while(y >= 0 and v[i][y]->val == INT_MIN)
                y--;
            ans = max(y-x+1,ans);
        }
        return ans;
    }
};


