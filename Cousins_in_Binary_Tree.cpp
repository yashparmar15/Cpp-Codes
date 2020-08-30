/*Problem Description

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
1 <= N <= 105

1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



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

 [6, 7]
Output 2:

 []


Example Explanation
Explanation 1:

 Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
 Remember Node 4 is sibling of Node 5 and do not need to return this.
Explanation 2:

 Since Node 1 is the root so it doesn't have any cousin so we will return an empty array*/
 
 
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(!A)
        return ans;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int s = q.size();
        vector<pair<int,int>> v;
        bool flag = false;
        int num = 0;
        while(s--){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                v.push_back(make_pair(temp->val,temp->left->val));
                if(temp->left->val == B){
                    flag = true;
                    num = temp->val;
                }
                q.push(temp->left);
            }
            if(temp->right){
                v.push_back(make_pair(temp->val,temp->right->val));
                if(temp->right->val == B){
                    flag = true;
                    num = temp->val;
                }
                q.push(temp->right);
            }
        }
        if(flag){
            for(int i = 0 ; i < v.size() ; i++){
                if(v[i].first != num){
                    ans.push_back(v[i].second);
                }
            }
            return ans;
        }
    }
    return ans;
}
