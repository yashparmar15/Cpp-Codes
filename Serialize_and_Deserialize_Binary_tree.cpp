/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int check = 2;
        while(!q.empty()){
            int s = q.size();
            int count = 0;
            while(s--){
                auto temp = q.front();
                q.pop();
                if(temp->val == 10000)
                    ans = ans + "a ";
                else
                    ans = ans + to_string(temp->val) + " ";
                if(temp->left)
                    q.push(temp->left);
                else {
                    q.push(new TreeNode(10000));
                    count++;
                }
                if(temp->right)
                    q.push(temp->right);
                else {
                    q.push(new TreeNode(10000));
                    count++;
                }
            }
            if(count == check) break;
            check = check * 2;
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        vector<int> v;
        int num = 0;
        bool flag = false;
        for(int i = 0 ; i < data.size() ; i++){
            if(data[i] == 'a'){
                v.push_back(10000);
                i++;
                continue;
            } else {
                if(data[i] == '-') flag = true;
                else if(data[i] == ' '){
                    if(flag) num = -num;
                    v.push_back(num);
                    num = 0;
                    flag = false;
                } else {
                    num = num * 10 + int(data[i]) - 48;
                }
            }
        }
        queue<TreeNode*> q;
        TreeNode* ans = NULL;
        if(v[0] == 10000) return NULL;
        for(int i = 0 ; i < v.size() ; i++){
            if(ans == NULL) {
                ans = new TreeNode(v[i]);
                q.push(ans);
            } else {
                auto temp = q.front();
                q.pop();
                if(temp->val != 10000){
                    if(v[i] == 10000){
                        q.push(new TreeNode(v[i]));
                    } else {
                        temp->left = new TreeNode(v[i]);
                        q.push(temp->left);
                    }
                    i++;
                    if(v[i] == 10000){
                        q.push(new TreeNode(v[i]));
                    } else {
                        temp->right = new TreeNode(v[i]);
                        q.push(temp->right);
                    }
                } else {
                    q.push(new TreeNode(v[i++]));
                    q.push(new TreeNode(v[i]));
                }
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
