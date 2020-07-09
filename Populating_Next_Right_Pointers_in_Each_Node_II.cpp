// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

 

// Follow up:

// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

// Example 1:



// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

// Constraints:

// The number of nodes in the given tree is less than 6000.
// -100 <= node.val <= 100


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> q;
        q.push(root);
        int s = q.size();
        while(!q.empty()){
            s = q.size();
            vector<Node*> temp;
            while(s--){
                Node* t = q.front();
                q.pop();
                temp.push_back(t);
                if(t->left != NULL)
                    q.push(t->left);
                if(t->right != NULL)
                    q.push(t->right);
            }
            for(int i = 0 ; i < temp.size() - 1 ; i++){
                temp[i]->next = temp[i + 1];
            }
            temp[temp.size() - 1]->next = NULL;
        }
        return root;
    }
};
