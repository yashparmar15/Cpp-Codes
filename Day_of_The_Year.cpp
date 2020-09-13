/*Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.*/


class Solution {
public:
    int dayOfYear(string date) {
        int year = 0;
        for(int i = 0 ; i < 4 ; i++)
            year = year * 10 + int(date[i]) - 48;
        int month = 0;
        for(int i = 5 ; i < 7 ; i++)
            month = month * 10 + int(date[i]) - 48;
        int day = 0;
        for(int i = 8 ; i < 10 ; i++)
            day = day * 10 + int(date[i]) - 48;
        bool isLeap = false;
        if(year % 4 == 0){
            if(year % 100 != 0) isLeap = true;
            else if(year % 400 == 0) isLeap = true;
        }
        int ans = 0;
        for(int i = 1 ; i <= month ; i++){
            if(i == 2){
                if(i == month) ans += day;
                else if(isLeap) ans += 29;
                else ans += 28;
            }
            if(i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12){
                if(i == month) ans += day;
                else ans += 31;
            }
            if(i == 4 or i == 6 or i == 9 or i == 11){
                if(i == month) ans += day;
                else ans += 30;
            }
        }
        return ans;
    }
};
