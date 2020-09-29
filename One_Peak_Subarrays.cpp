/*Given an array A of N integers, and Q queries. A subarray is a one peak subarray if there exist an index K such that, A[i] <= A[i+1] ... <= A[k] >= A[k+1] >= A[k+2] ... >= A[j-1] >= A[j]. Each query consists of two integers start_index and end_index. Write an efficient program to find if the range in given query is a one peak subarray.
Note: A corner element in the subarray can be a peak if the other elements satisfy the condition.
Input

First line contains a single integer N.
Second line contains N space separated integers A[i].
Third line contains a single integer Q.
Q lines follow, in each of the lines, there are two space separated integers start_index and end_index of a query.
Output

For each query, print 1 if the range is a one peak subarray in a new line. Otherwise, print 0 in a new line.
Constraints

3 <= N <= 3*10^5
-10^9 <= A[i] <= 10^9
1 <= Q <= 1000
0 <= L < R <= N-1
(R - L) >= 2
Sample Input 
Sample Output 
Show Hint 1
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0 ; i < N ; i++) cin >> v[i];
    int Q;
    cin >> Q;
    vector<int> temp(N);
    temp[0] = 0;
    bool inc = true;
    if(v[1] <= v[0]) inc = false;
    int start = 0;
    temp[1] = 0;
    for(int i = 1 ; i < N ; i++){
        start = i - 1;
        while(i < N and v[i] >= v[i - 1]){
            temp[i] = start;
            i++;
        } 
        while(i < N and v[i] <= v[i - 1]){
            temp[i] = start;
            i++;
        }
        i--;
    }
    // for(int i = 0 ; i < N ; i++)
    //     cout << temp[i] << " " ;
    // cout << endl;
    for(int i = 0 ; i < Q ; i++){
        int x,y;
        cin >> x >> y;
        if(temp[y] <= x) cout << "1" << endl;
        else cout << "0" << endl;
    }
}
