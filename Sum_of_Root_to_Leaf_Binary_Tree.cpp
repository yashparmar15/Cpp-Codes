// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

// Return the sum of these numbers.

 

// Example 1:



// Input: [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

// Note:

// The number of nodes in the tree is between 1 and 1000.
// node.val is 0 or 1.
// The answer will not exceed 2^31 - 1.



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
    int answer(TreeNode *root, int sum)
    {
        if(root->left==NULL and root->right==NULL)
            return sum = (sum*2)+root->val;
        else
        {
            sum = (sum*2)+root->val;
            if(root->left ==NULL and root->right!=NULL)
                return answer(root->right,sum);
            else if(root->left!=NULL and root->right==NULL)
                return answer(root->left,sum);
            else
            return answer(root->left,sum)+answer(root->right,sum);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return answer(root,0);
    }
};



/////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int ans = 0;
    void recur(TreeNode* root, string temp){
        if(!root) return;
        temp += to_string(root->val);
        if(!root->left and !root->right){
            int num = 0;
            for(int i = temp.size() - 1 ; i >= 0 ; i--)
                num = num + (pow(2,temp.size() - 1 - i)) * (int(temp[i]) - 48);
            ans += num;
            return;
        }
        recur(root->left,temp);
        recur(root->right,temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        string temp = "";
        recur(root,temp);
        return ans;
    }
};
