/* Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.*/


#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(long long int i = a;i < b;i++)
#define ll long long 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n ;
        vector<ll> v;
        F(i,0,n){
            ll temp;
            cin >> temp;
            v.push_back(temp);
        }
        ll k;
        cin >> k;
        sort(v.begin(),v.end());
        cout << v[k - 1] << "\n";
    }
}
