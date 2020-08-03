void printOddNodes(Node *root)
{
    if(!root){
        cout << "\n";
        return;
    }
    queue<Node*> q;
    int s;
    q.push(root);
    s = q.size();
    bool odd = true;
    while(!q.empty()){
        s = q.size();
        while(s--){
            Node* t = q.front();
            if(odd)
                cout << t->data << " ";
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        odd = !odd;
    }
    cout << endl;
}
