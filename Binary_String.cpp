// Given a binary string S. The task is to count the number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Each test case consist of an integer 'N' denoting the string length and next line is followed by a binary string.

// Output:
// For each testcase, in a new line, print the number of substring starting and ending with 1 in a separate line.

// User Task:
// The task is to complete the function binarySubstring() which takes the length of binary string and a binary string as input parameter and counts the number of substrings starting and ending with 1 and returns the count.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ |S| ≤ 104

// Example:
// Input:
// 2
// 4
// 1111
// 5
// 01101
// Output:
// 6
// 3

// Example:
// Testcase 1: There are 6 substrings from the given string. They are 11, 11, 11, 111, 111, 1111.
// Testcase 2: There 3 substrings from the given string. They are 11, 101, 1101.



long binarySubstring(int n, string a){
    
    // Your code here
    long long int ans;
    int count = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] == '1')
            count++;
    }
    ans = (count - 1)*count / 2;
    return ans;
}