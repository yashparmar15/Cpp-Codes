/*Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.

 

Example 1:

Input: digits = [8,1,9]
Output: "981"
Example 2:

Input: digits = [8,6,7,1,0]
Output: "8760"
Example 3:

Input: digits = [1]
Output: ""
Example 4:

Input: digits = [0,0,0,0,0,0]
Output: "0"
 

Constraints:

1 <= digits.length <= 10^4
0 <= digits[i] <= 9
The returning answer must not contain unnecessary leading zeros.*/


class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> one,two,zero;
        for(int i = 0 ; i < digits.size() ; i++){
            if(digits[i] % 3 == 0)
                zero.push_back(digits[i]);
            if(digits[i] % 3 == 1)
                one.push_back(digits[i]);
            if(digits[i] % 3 == 2)
                two.push_back(digits[i]);
        }
        sort(one.begin(),one.end());
        reverse(one.begin(),one.end());
        sort(two.begin(),two.end());
        reverse(two.begin(),two.end());
        vector<int> temp1;
        for(int i = 0 ; i < min(one.size(),two.size()) ; i++){
            temp1.push_back(one[i]);
            temp1.push_back(two[i]);
        }
        for(int i = 0 ; i < zero.size() ; i++){
            temp1.push_back(zero[i]);
        }
        if(one.size() > two.size()){
            if(one.size() >= two.size() + 3){
                for(int i = two.size() ; i < one.size() ; i += 3){
                    if(i + 2 < one.size()){
                        temp1.push_back(one[i]);
                        temp1.push_back(one[i + 1]);
                        temp1.push_back(one[i + 2]);
                    }
                }
            }
        }
        if(two.size() > one.size()){
            if(two.size() >= one.size() + 3){
                for(int i = one.size() ; i < two.size() ; i += 3){
                    if(i + 2 < two.size()){
                        temp1.push_back(two[i]);
                        temp1.push_back(two[i + 1]);
                        temp1.push_back(two[i + 2]);
                    }
                }
            }
        }
        sort(temp1.begin(),temp1.end());
        reverse(temp1.begin(),temp1.end());
        string ans2 = "";
        if(temp1.size() and temp1[0] == 0)
            return "0";
        for(int i = 0 ; i < temp1.size() ; i++){
            ans2 = ans2 + to_string(temp1[i]);
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        vector<int> temp;
        for(int i = 0 ; i < zero.size() ; i++){
            temp.push_back(zero[i]);
        }
        int count = 0;
        for(int i = one.size() - 1 ; i >= 0 ; i-= 3){
            if(i - 2 >= 0){
                temp.push_back(one[i]);
                temp.push_back(one[i - 1]);
                temp.push_back(one[i - 2]);
                count += 3;
            }
        }
        for(int i = 0 ; i < count ; i++){
            one.pop_back();
        }
        count = 0;
        for(int i = two.size() - 1 ; i >= 0 ; i-=3){
            if(i - 2 >= 0){
                temp.push_back(two[i]);
                temp.push_back(two[i - 1]);
                temp.push_back(two[i - 2]);
                count += 3;
            }
        }
        for(int i = 0 ; i < count ; i++){
            two.pop_back();
        }
        reverse(two.begin(),two.end());
        reverse(one.begin(),one.end());
        for(int i = 0 ; i < min(one.size(),two.size()) ; i++){
            temp.push_back(one[i]);
            temp.push_back(two[i]);
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        string ans1 = "";
        if(temp.size() and temp[0] == 0)
            return "0";
        for(int i = 0 ; i < temp.size() ; i++){
            ans1 = ans1 + to_string(temp[i]);
        }
        cout << ans1 << " " << ans2 << endl;
        if(ans1.size() > ans2.size())
            return ans1;
        else
            return ans2;
    }
};
