/*You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.*/

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
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int,int> M;
        for(int i = 0 ; i < n ; i++) {
            cin >> v[i];
            M[v[i]]++;
        }
        sort(v.begin(),v.end());
        int i = 0;
        while(i < v.size() and v[i] <= 0) i++;
        if(i == v.size() or v[i] != 1) cout << 1 << endl;
        else{
            int temp = 1;
            while(1){
                if(M.find(temp) == M.end()){
                    cout << temp << endl;
                    break;
                }
                temp++;
            }
        }
    }
}
