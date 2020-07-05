// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
// Note:
// The size of the given array will be in the range [1,1000].


int findpos(vector<int>v,int l,int r,int max_ele){
    int index=-1;
    for(int i=l;i<r;i++){
        if(v[i]>max_ele){
            index=i;
            max_ele=v[i];
        }
    }
    return index;
    
}
TreeNode*find(vector<int>v,int l,int r){
        if(l<r){
            int max_ele=INT_MIN;
            int ele_pos = findpos(v,l,r,max_ele);
            TreeNode*root=new TreeNode(v[ele_pos]);
            root->left=find(v,l,ele_pos);
            root->right=find(v,ele_pos+1,r);
            return root;
        }
    return NULL;
    }
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int l=0,r=nums.size();
        return find(nums,l,r);
        
    }
};