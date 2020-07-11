// Given a date string in the form Day Month Year, where:

// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
// Year is in the range [1900, 2100].
// Convert the date string to the format YYYY-MM-DD, where:

// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.
 

// Example 1:

// Input: date = "20th Oct 2052"
// Output: "2052-10-20"
// Example 2:

// Input: date = "6th Jun 1933"
// Output: "1933-06-06"
// Example 3:

// Input: date = "26th May 1960"
// Output: "1960-05-26"
 

// Constraints:

// The given dates are guaranteed to be valid, so no error handling is necessary.


class Solution {
public:
    string reformatDate(string date) {
        string year = "";
        for(int i = date.size() - 1 ; i >= date.size() - 4 ; i--){
            year = date[i] + year;
        }
        string day = "";
        int i = 0;
        while(int(date[i]) >= 48 and int(date[i]) <= 57){
            day = day + date[i];
            i++;
        }
        int count = 0;
        string month = "";
        for(int i = 0 ; i < date.size() ; i++){
            if(date[i] == ' ')
                count++;
            if(count == 1 and date[i] != ' ')
                month = month + date[i];
            if(count == 2)
                break;
        }
        string m = "";
        if(month == "Jan")
            m  = "01";
        if(month == "Feb")
            m  = "02";
        if(month == "Mar")
            m  = "03";
        if(month == "Apr")
            m  = "04";
        if(month == "May")
            m  = "05";
        if(month == "Jun")
            m  = "06";
        if(month == "Jul")
            m  = "07";
        if(month == "Aug")
            m  = "08";
        if(month == "Sep")
            m  = "09";
        if(month == "Oct")
            m  = "10";
        if(month == "Nov")
            m  = "11";
        if(month == "Dec")
            m  = "12";
        if(day.size() == 1)
            day = "0"+day;
        return year+"-"+m+"-"+day;
        
    }
};