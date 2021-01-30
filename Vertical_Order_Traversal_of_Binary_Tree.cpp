/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (x, y), its left and right children will be at positions (x - 1, y - 1) and (x + 1, y - 1) respectively.

The vertical order traversal of a binary tree is a list of non-empty reports for each unique x-coordinate from left to right. Each report is a list of all nodes at a given x-coordinate. The report should be primarily sorted by y-coordinate from highest y-coordinate to lowest. If any two nodes have the same y-coordinate in the report, the node with the smaller value should appear earlier.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: Without loss of generality, we can assume the root node is at position (0, 0):
The node with value 9 occurs at position (-1, -1).
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2).
The node with value 20 occurs at position (1, -1).
The node with value 7 occurs at position (2, -2).
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report [1,5,6], the node with value 5 comes first since 5 is smaller than 6.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000*/


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
    static bool comp(vector<int> a,vector<int> b){
        if(a[0] == b[0]) {
            if(a[1] == b[1]) return a[2] < b[2];
            else {
                return a[1] > b[1];
            }
        } else {
            return a[0] < b[0];
        }
        
    }
    void traverse(TreeNode* root,vector<vector<int>> &v,int x,int y){
        if(!root) return;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(root->val);
        v.push_back(temp);
        traverse(root->left,v,x - 1,y - 1);
        traverse(root->right,v,x + 1,y - 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        traverse(root,v,0,0);
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> ans;
        for(int i = 0 ; i < v.size() ; i++){
            vector<int> temp;
            temp.push_back(v[i][2]);
            while(i + 1 < v.size() and v[i][0] == v[i + 1][0]){
                temp.push_back(v[i + 1][2]);
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
