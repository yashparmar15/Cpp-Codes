/*Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9*/


class Solution {
public:
    string res = "";
    void recur(vector<int>temp,int &ans,vector<int> &A){
        if(temp.size() == 4){
            int t = 0;
            for(int i = 0 ; i < temp.size() ; i++){
                t = t * 10 + temp[i];
            }
            if(t > ans){
                res = "";
                for(int i = 0 ; i < temp.size() ; i++){
                    res = res + to_string(temp[i]);
                    if(i == 1)
                        res = res + ":";
                }
            }
        }
        for(int i = 0 ; i < A.size() ; i++){
            if(A[i] != -1){
                if(temp.size() == 0 and A[i] >= 0 and A[i] <= 2){
                    temp.push_back(A[i]);
                    int t = A[i];
                    A[i] = -1;
                    recur(temp,ans,A);
                    A[i] = t;
                    temp.pop_back();
                } else {
                    if(temp.size() == 1){
                        if(temp[0] == 2){
                            if(A[i] >= 0 and A[i] <= 3){
                                temp.push_back(A[i]);
                                int t = A[i];
                                A[i] = -1;
                                recur(temp,ans,A);
                                A[i] = t;
                                temp.pop_back();
                            }
                        } else {
                            temp.push_back(A[i]);
                            int t = A[i];
                            A[i] = -1;
                            recur(temp,ans,A);
                            A[i] = t;
                            temp.pop_back();
                        }
                    } else {
                        if(temp.size() == 2 and A[i] >= 0 and A[i] <= 5){
                            temp.push_back(A[i]);
                            int t = A[i];
                            A[i] = -1;
                            recur(temp,ans,A);
                            A[i] = t;
                            temp.pop_back();
                        } else {
                            if(temp.size() == 3){
                                temp.push_back(A[i]);
                                int t = A[i];
                                A[i] = -1;
                                recur(temp,ans,A);
                                A[i] = t;
                                temp.pop_back();
                            }
                        }
                    }
                }
            }  
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        if(A[0] > 2)
            return "";
        int ans = INT_MIN;
        vector<int> temp;
        recur(temp,ans,A);
        return res;
    }
};
