/*Cupid wants to strike maximum houses in Geek Land on Valentine's Day. The houses in Geek Land are arranged in the form of a binary tree. Cupid is standing at target node initially. 
Find the sum of all nodes within a maximum distance k from target node. The target node should be included in the sum.


Example 1:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 9, K = 1
Output:
22
Explanation:
Nodes within distance 1 from 9 are 9, 5, 7, 1  
Example 2:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 40, K = 2
Output:
113
Explanation:
Nodes within distance 2 from 40 are 40, 19, 50, 4

Your Task:
You don't need to read input or print anything. Complete the function sum_at_distK() which takes the root of the tree, target, and K  as input parameter and returns the sum of all nodes within a max distance of k from the target


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N, Node Value ≤ 105
1 ≤ K ≤ 20*/


class Solution{

   public:
    
    unordered_map<Node*,Node*>um; // to store the parent of each node
    
    // it returns the refence to target node
    Node* storeparent(Node*root,int target)
    {
        Node*t; //for target node
        if (root==NULL)
          return t;
          
        um[root]=NULL; // parent of root is null
        
        //standard BFS implementation
        
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            
          Node*p=q.front();
          
          if (p->data==target)
          {
              t=p;// here we have found our target node
          }
        
        if (p->right)// if right child exist
        {
            um[p->right]=p;// set parent of right chlid of p as p
            q.push(p->right);
            
        }
        if (p->left)
        {
            um[p->left]=p;// set parent of left chlid of p as p
            q.push(p->left);
        }
        
        q.pop();
        
        }
        return t;// return this target node
    }
    
    int sum_at_distK(Node* root, int target, int k)
    {
        
         //store parent of each node and get reference to target node
         Node*t=storeparent(root,target);
        
         if (t==NULL) // if target node is not present
           return 0;
         
         long long int sum=0; // sum of all the nodes upto level=k
         
         //BFS implementation
         
         queue<Node*>q;
         
         set<Node*>s;
         
         q.push(t);
         s.insert(t);
         //sum+=t->data;
         int level=0;
         
         while(!q.empty() and level<=k)
         {
             int size=q.size();
             
             for (int i=0;i<size;i++)
             {Node*f=q.front();
             sum+=f->data;
             
             if (f->right && s.find(f->right)==s.end() )
             {
                 q.push(f->right);
                 s.insert(f->right);
             }
             
             if (f->left && s.find(f->left)==s.end())
             {
                 q.push(f->left);
                  s.insert(f->left);
                
             }
             if (um[f] && s.find(um[f])==s.end())// for parent of f
             {
                 q.push(um[f]);
                  s.insert(um[f]);
                 //sum+=um[f]->data;
             }
             q.pop();
             }
             level++;// now we will move to next level
         }
         
         
         
         return sum;// sum of all the nodes till level k
         
    }



};
