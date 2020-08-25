/*Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
2
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
8 4
2 6 7 5 2 6 8 4 
2 6 4 5
Output:
2 2 1 1 8 8 3 5 6 7 9
2 2 6 6 4 5 7 8

Explanation:
Testcase 1: After sorting the resulted output is 2 2 1 1 8 8 3 5 6 7 9.
Testcase 2: After sorting the resulted output is 2 2 6 6 4 5 7 8.*/


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
        int n,m;
        cin >> n >> m;
        int temp;
        unordered_map<int,int> M;
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            M[temp]++;
        }
        for(int j = 0 ; j < m ; j++){
            cin >> temp;
            for(int i = 0 ; i < M[temp] ; i++){
                cout << temp << " ";
            }
            M[temp] = 0;
        }
        vector<int> arr;
        for(auto m : M){
            if(m.second > 0){
                for(int i = 0 ; i < m.second ; i++){
                    arr.push_back(m.first);
                }
            }
        }
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < arr.size() ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
