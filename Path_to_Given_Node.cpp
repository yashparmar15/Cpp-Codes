/*Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
1 <= N <= 105

1 <= Data Values of Each Node <= N

1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [1]*/
 
 
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void recur(vector<int> &ans,TreeNode* root , int B , vector<int> temp){
    if(!root){
        return;
    }
    if(root->val == B){
        for(int i = 0 ; i < temp.size() ; i++){
            ans.push_back(temp[i]);
        }
        ans.push_back(root->val);
        return;
    }
    temp.push_back(root->val);
    recur(ans,root->left,B,temp);
    recur(ans,root->right,B,temp);
    temp.pop_back();
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(!A)
        return ans;
    vector<int> temp;
    recur(ans,A,B,temp);
    return ans;
}
