/*Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.*/



class Solution {
public:
    int convert(string a){
        return (int(a[0]) - 48) * 10 + int(a[1]) -48;
    }
    int find(string a , string b){
        int h1 = convert(a.substr(0,2)),m1 = convert(a.substr(3,2));
        int h2 = convert(b.substr(0,2)),m2 = convert(b.substr(3,2));
        int num1 = (h2 - h1) * 60 + m2 - m1;
        int num2 = (h1 + 23 - h2) * 60 + m1 + 60 - m2;
        return min(num1,num2);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans = INT_MAX;
        int num;
        for(int i = 0 ; i < timePoints.size() - 1 ; i++){
            num = find(timePoints[i],timePoints[i + 1]);
            ans = min(ans,num);
        }
        num = find(timePoints[0],timePoints[timePoints.size() - 1]); 
        ans = min(ans,num);
        return ans;
    }
};
