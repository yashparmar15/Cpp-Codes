/*A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".*/


class Solution {
public:
    unordered_map<string,int> M;
    void backtrack(int num,vector<string> &ans,string temp,int x,int h,int m,vector<int> hour,vector<int> min,int hi,int mi){
        if(x == num){
            M[temp]++;
            return;
        }
        for(int i = hi ; i < hour.size() ; i++){
            if(h + hour[i] <= 11 and hour[i] != -1){
                int f = hour[i];
                h = h + hour[i];
                temp = to_string(h) + ":";
                if(m <= 9)
                    temp = temp + "0" + to_string(m);
                else
                    temp = temp + to_string(m);
                hour[i] = -1;
                backtrack(num,ans,temp,x + 1,h,m,hour,min,i+1,mi);
                hour[i] = f;
                h = h - hour[i];
            }
        } 
        for(int i = mi ; i < min.size() ; i++){
            if(m + min[i] <= 59 and min[i] != -1){
                int f = min[i];
                m = m + min[i];
                temp = to_string(h) + ":";
                if(m <= 9)
                    temp = temp + "0" + to_string(m);
                else
                    temp = temp + to_string(m);
                min[i] = -1;
                backtrack(num,ans,temp,x + 1,h,m,hour,min,hi,i+1);
                min[i] = f;
                m = m - min[i];
            }
        } 
    }
    vector<string> readBinaryWatch(int num) {
        if(num == 0)
            return {"0:00"};
        vector<string> ans;
        string temp = "";
        int x = 0;
        int h = 0,m = 0;
        vector<int> hour = {1,2,4,8};
        vector<int> min = {1,2,4,8,16,32};
        backtrack(num,ans,temp,x,h,m,hour,min,0,0);
        for(auto m : M)
            ans.push_back(m.first);
        return ans;
    }
};
