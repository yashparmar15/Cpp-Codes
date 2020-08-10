/*Pasha is a strange guy. He has a string of length N. He wants to perform 2 types of queries on the string.
Type 1- Rotate the string by K character from the end.
Type 2- Print the Character at the I'th index of the resulting string at that Instant.

Now, Pasha wants to perform the 2 types of queries, But he is too lazy to do it himself.
So, you need to help him.
Input:
The first line contains an integer T-denoting the test cases.
The first line of each test cases contains two integers- N (Length of the string) and Q(Number of queries),
The second line contains the String.
Then Each of the next Q lines contains Typ of the query and K or I.
Output:
For each query of Type 2, Output the character at the I'th index in a new line.
Constraints:
1<=T<=10
1<=N<=100000
1<=Q<=10000
1<=TYP<=2
1<=K<=1000000000
0<=I
Example:
Sample Input:
1
7 5
abcdefg
1 2
2 0
2 6
1 4
2 1

Sample output:
f
e
c
Explanation:
After First query String becomes -"fgabcde"
Second query returns - 'f'
Third query returns -'e'
After Fourth Query String becomes- "bcdefga"
Fifth Query returns -'c'*/


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
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        int shift = 0;
        for(int i = 0 ; i < q ; i++){
            int x,y;
            cin >> x >> y;
            if(x == 1){
                y = y % n;
                shift = shift + y;
                shift = shift % n;
            } else {
                int t = y - shift;
                if(y - shift < 0)
                    t = n + y - shift; 
                cout << s[t] << "\n";
            }
        }
    }
}
