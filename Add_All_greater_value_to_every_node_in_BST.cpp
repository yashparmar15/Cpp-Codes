// Given a BST, modify it so that all greater values in the given BST are added to every node.

// Input Format:

// The first line of input contains the number of test cases T. Each test case contains a string representing the tree as described below: 

// The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

// For example:
 
// For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

// Output:
// Print the inorder traversal of the modified BST.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function modify() which takes one argument: root of the BST. The function should contain the logic to modify the BST so that in the modified BST, every node has a value equal to the sum of its value in the original BST and values of all the elements larger than it in the original BST. Return the root of the modified BST.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1<=T<=10
// 1<=N<=100000

// Example:
// Input:
// 2
// 50 30 70 20 40 60 80
// 2 1 5 N N 4 7

// Output:
// 350 330 300 260 210 150 80
// 19 18 16 12 7
// Explanation:

//               50
//            /      \
//          30        70
//         /   \      /  \
//       20    40    60   80 

// The above tree should be modified to following 

//               260
//            /      \
//          330        150
//         /   \       /  \
//       350   300    210   80



/*
Node structure is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// modify the BST and return its root
void recur(Node *root , int &sum){
    if(!root)
        return;
    recur(root->right,sum);
    sum = sum + root->data;
    root->data = sum;
    recur(root->left,sum);
}
Node* modify(Node *root)
{
    // Your code here
    int sum = 0;
    recur(root,sum);
    return root;
}