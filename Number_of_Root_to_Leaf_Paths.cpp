// Given a binary tree, you need to find the number of all root to leaf paths along with their path lengths.

// Input Format:
// The task is to complete the method which takes one argument, root of binary tree. The node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

// Output Format:
// The function should print the answer in the form of pairs in a single line for a test case. A pair consists of path length then number of paths corresponding to that path length separated by space. Print pairs in increasing order of path lengths and all pairs are separated by symbol of "$".

// Your Task:
// Your task is to complete the function pathCounts that prints the number of all root to leaf paths along with their path length separated by space.

// Constraints:
// 1 <= T <= 30
// 1 <= Number of nodes <= 100
// 1 <= Data of a node <= 1000

// Example(To be used only for expected output):
// Input:
// 2
// 2
// 3 2 L 3 4 R
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R
// Output:
// 2 2 $
// 2 1 $3 2 $

// Explanation :
// Testcase1:
// There are 2 root to leaf paths of length 2.    

// Testcase2:
// There is 1 root to leaf paths of length 2 and 2 root to leaf paths of length 3.

// ** For More Input/Output Examples Use 'Expected Output' option **



/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
void recur(Node *root , vector<int> temp,unordered_map<int,int> &M){
    if(!root)
        return;
    if(!root->left and !root->right){
        M[temp.size() + 1]++;
        return;
    }
    temp.push_back(root->data);
    recur(root->left,temp,M);
    recur(root->right,temp,M);
    temp.pop_back();
}

void pathCounts(Node *root)
{
    vector<int> temp;
    unordered_map<int,int> M;
    recur(root,temp,M);
    for(auto t:M){
        cout << t.first <<" "<<t.second <<" $";
    }
}