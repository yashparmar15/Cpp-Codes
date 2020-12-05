/*We sampled integers between 0 and 255, and stored the results in an array count:  count[k] is the number of integers we sampled equal to k.

Return the minimum, maximum, mean, median, and mode of the sample respectively, as an array of floating point numbers.  The mode is guaranteed to be unique.

(Recall that the median of a sample is:

The middle element, if the elements of the sample were sorted and the number of elements is odd;
The average of the middle two elements, if the elements of the sample were sorted and the number of elements is even.)
 

Example 1:

Input: count = [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: [1.00000,3.00000,2.37500,2.50000,3.00000]
Example 2:

Input: count = [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Output: [1.00000,4.00000,2.18182,2.00000,1.00000]
 

Constraints:

count.length == 256
1 <= sum(count) <= 10^9
The mode of the sample that count represents is unique.
Answers within 10^-5 of the true value will be accepted as correct.*/


class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        for(int i = 0 ; i < count.size() ; i++){
            if(count[i]) {
                ans.push_back(i);
                break;
            }
        }
        for(int i = count.size() - 1 ; i >= 0 ; i--){
            if(count[i]){
                ans.push_back(i);
                break;
            }
        }
        double sum = 0;
        int size = 0;
        for(int i = 0 ; i < count.size() ; i++){
            sum += count[i] * i;
            size += count[i];
        }
        ans.push_back(sum / size);
        if(size % 2){
            int median = size / 2 + 1;
            int till = 0;
            for(int i = 0 ; i < count.size() ; i++){
                if(till + count[i] >= median){
                    ans.push_back(i);
                    break;
                }
                till += count[i];
            }
        } else {
            int value = size / 2;
            double median = 0;
            int till = 0;
            for(int i = 0 ; i < count.size() ; i++){
                if(till + count[i] >= value){
                    median += i;
                    break;
                }
                till += count[i];
            }
            till = 0;
            value++;
            for(int i = 0 ; i < count.size() ; i++){
                if(till + count[i] >= value){
                    median += i;
                    break;
                }
                till += count[i];
            }
            ans.push_back(median / 2);
        }
        int mode = 0;
        int value = 0;
        for(int i = 0 ; i < count.size() ; i++){
            if(count[i] > value){
                value = count[i];
                mode = i;
            }
        }
        ans.push_back(mode);
        return ans;
    }
};
