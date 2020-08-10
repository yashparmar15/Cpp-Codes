/*Arya has a string, S, of uppercase English letters. She writes down the string S on a paper K times.
She wants to calculate the occurence of a specific letter in the first N characters of the final string.

Input:

First line of input contains a single integer T denoting the number of test cases.
The first line of each test case contains a string S.
The second line contains 2 space-separated integers K and N, and an uppercase English letter C whose occurence needs to be counted.

Output:

For each test case, print the required answer in a new line.


Constraints:

1 <= T <= 150
1 <= |S| <= 500
1 <= K <= 10^5
1 <= N <= |S|*K


Example:

Input : 
2
ABA
3 7 B
BHD
4 6 E
Output : 
2
0

Explaination : 
Case 1 : Final string - ABAABAABA
Case 2 : Final string - BHDBHDBHDBHD

Example 2 :
Input : 
1
MMM
2 4 M
Output :
4

Explaination : 
Case 1 : Final string - MMMMMM*/


#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(long long int i = a;i < b;i++)
#define ll long long 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        int k,n;
        char c;
        cin >> k >> n >> c;
        int count = 0;
        F(i,0,s.size())
            if(s[i] == c)
                count++;
        int ans = count * (n / s.size());
        count = n % s.size();
        F(i,0,count)
            if(s[i] == c)
                ans++;
        cout << ans << "\n";
    }
}
