/*Given two binary trees T1 and T2, you have to find minimum number of insertions to be done in T1 to make it structurally identical to T2. Return -1 if not possible.

Notes

Assume insertions are done in a normal fashion in the BSTs.
Assume while inserting, if the value of a node v is equal to value being inserted, we insert it in left subtree of node v.
You can insert any positive or negative integer.
Example :

Input 1: 

T1:       10
         / \
        9   20

T2:       5
         / \
        2   7
       /
      1

If you insert 8 into T1, it will be structurally identical to T2. Hence answer is 1.


Input 2: 

T1:       10
         / \
        9   20

T2:       5
           \
            7

You cannot make T1 and T2 structurally identical. Hence answer is -1.*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void recur(TreeNode* root , int &count){
    if(!root)
        return;
    count++;
    recur(root->left,count);
    recur(root->right,count);
}
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    int countA = 0;
    recur(A,countA);
    int countB = 0;
    recur(B,countB);
    if(countB < countA)
        return -1;
    return countB - countA;
}
