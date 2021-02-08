int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    vector<int> temp;
    Node* t = head;
    while(t != NULL){
        temp.push_back(t->data);
        t = t->next;
    }
    sort(temp.begin(),temp.end());
    int ans = 0;
    for(int i = 0 ; i < temp.size() - 2 ; i++){
        int start = i + 1,end = temp.size() - 1;
        while(start < end){
            int s = temp[i] + temp[start] + temp[end];
            if(s == x) ans++,start++,end--;
            else if(s > x) end--;
            else start++;
        }
    }
    return ans;
} 
