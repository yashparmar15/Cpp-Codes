// Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

// Input Format:
// The first line of input contains the number of test cases T. For each test case, there will be two lines of input where first line is a string representing the tree as described below: 

// The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

// For example:
 
// For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

// Second-line is an integer represents K

// Output Format:
// The output for each test case will be the minimum absolute difference of a node with a given target value K.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minDiff() that takes the root of the BST and an integer K as its input and returns the minimum absolute difference between any node value of the BST and the integer K.

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= T <= 10
// 1 <= N <= 100000

// Example:
// Input:
// 2
// 10 2 11 1 5 N N N N 3 6 N 4
// 13
// 8 1 9 N 4 N 10 3
// 9

// Output:
// 2
// 0

// Explanation:

// Testcase1:
// K=13. The node that has value nearest to K is 11. so the answer is 2
// Testcase2:
// K=9. The node that has value nearest to K is 9. so the answer is 0.

// ** For More Input/Output Examples Use 'Expected Output' option **




/*The Node structure is

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

// Return the minimum absolute difference between any tree node and the integer K
void recur(Node *root,vector<int> &temp){
    if(!root)
        return;
    temp.push_back(root->data);
    recur(root->left,temp);
    recur(root->right,temp);
}
int minDiff(Node *root, int K)
{
    //Your code here
    vector<int> temp;
    recur(root,temp);
    int ans = INT_MAX;
    for(int i = 0 ; i < temp.size() ; i++){
        ans = min(ans,abs(K - temp[i]));
    }
    return ans;
}