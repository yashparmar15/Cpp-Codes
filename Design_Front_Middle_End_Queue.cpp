/*Design a queue that supports push and pop operations in the front, middle, and back.

Implement the FrontMiddleBack class:

FrontMiddleBack() Initializes the queue.
void pushFront(int val) Adds val to the front of the queue.
void pushMiddle(int val) Adds val to the middle of the queue.
void pushBack(int val) Adds val to the back of the queue.
int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 

Example 1:

Input:
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
Output:
[null, null, null, null, null, 1, 3, 4, 2, -1]

Explanation:
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)
 

Constraints:

1 <= val <= 109
At most 1000 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.*/



class FrontMiddleBackQueue {
public:
    vector<int> arr;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        reverse(arr.begin(),arr.end());
        arr.push_back(val);
        reverse(arr.begin(),arr.end());
    }
    
    void pushMiddle(int val) {
        int n = arr.size();
        if(n == 0) pushBack(val);
        if(n == 1) pushFront(val);
        if(n <= 1) return;
        int mid = n / 2 - 1;
        arr.push_back(val);
        for(int i = arr.size() - 1 ; i > mid + 1 ; i--)
            swap(arr[i],arr[i - 1]);
    }
    
    void pushBack(int val) {
        arr.push_back(val);
    }
    
    int popFront() {
        if(arr.size() == 0) return -1;
        reverse(arr.begin(),arr.end());
        int ans = arr.back();
        arr.pop_back();
        reverse(arr.begin(),arr.end());
        return ans;
    }
    
    int popMiddle() {
        for(int i = 0 ; i < arr.size() ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        if(arr.size() == 0) return -1;
        if(arr.size() == 1) return popBack();
        if(arr.size() == 2) return popFront();
        vector<int> temp;
        int n = arr.size();
        int mid;
        if(n % 2) mid = n / 2;
        else mid = n / 2 - 1;
        for(int i = n - 1 ; i > mid ; i--){
            temp.push_back(arr.back());
            arr.pop_back();
        }
        int ans = arr.back();
        arr.pop_back();
        reverse(temp.begin(),temp.end());
        for(int i = 0 ; i < temp.size() ; i++)
            arr.push_back(temp[i]);
        return ans;
    }
    
    int popBack() {
        if(arr.size() == 0) return -1;
        int ans = arr.back();
        arr.pop_back();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
