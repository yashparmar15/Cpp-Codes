// Print a binary tree in an m*n 2D string array following these rules:

// The row number m should be equal to the height of the given binary tree.
// The column number n should always be an odd number.
// The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
// Each unused space should contain an empty string "".
// Print the subtrees following the same rules.
// Example 1:
// Input:
//      1
//     /
//    2
// Output:
// [["", "1", ""],
//  ["2", "", ""]]
// Example 2:
// Input:
//      1
//     / \
//    2   3
//     \
//      4
// Output:
// [["", "", "", "1", "", "", ""],
//  ["", "2", "", "", "", "3", ""],
//  ["", "", "4", "", "", "", ""]]
// Example 3:
// Input:
//       1
//      / \
//     2   5
//    / 
//   3 
//  / 
// 4 
// Output:

// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
//  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
//  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
//  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
// Note: The height of binary tree is in the range of [1, 10].




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
    int Height(TreeNode* root){
        if(!root)
            return 0;
        int left = Height(root->left);
        int right = Height(root->right);
        return max(left,right) + 1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ans;
        int height = Height(root);
        if(!root)
            return ans;
        vector<vector<int>> temp;
        queue<TreeNode*> q;
        q.push(root);
        int s = q.size();
        int countNULL = 0 , sdash = s;
        long long int Power = 1;
        while(height--){
            Power = Power * 2;
        }
        int len = Power - 1;
        Power = Power / 2;
        while(!q.empty()){
            if(countNULL == sdash)
                break;
            countNULL = 0;
            s = q.size();
            sdash = s;
            vector<int> t;
            while(s--){
                TreeNode* flag = q.front();
                TreeNode* dummy = new TreeNode(INT_MIN);
                q.pop();
                t.push_back(flag->val);
                if(flag->left)
                    q.push(flag->left);
                else
                    q.push(dummy);
                if(flag->right)
                    q.push(flag->right);
                else
                    q.push(dummy);
                if(flag->val == INT_MIN)
                    countNULL++;
            }
            vector<string> tdash;
            int count = 0;
            for(int i = 0 ; i < Power - 1 ; i++){
                tdash.push_back("");
            }
            for(int i = 0 ; i < t.size() ; i++){
                if(t[i] == INT_MIN)
                    tdash.push_back("");
                else
                    tdash.push_back(to_string(t[i]));
                if(i != t.size() - 1)
                    for(int i = 0 ; i < 2 * Power - 1 ; i++){
                        tdash.push_back("");
                    }
            }
            for(int i = 0 ; i < Power - 1 ; i++){
                tdash.push_back("");
            }
            if(countNULL == sdash)
                break;
            Power = Power / 2;
            ans.push_back(tdash);
        }
        return ans;
    }
};