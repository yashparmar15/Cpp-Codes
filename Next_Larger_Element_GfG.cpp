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
        vector<long long int> v(n);
        for(int i = 0 ; i < n ; i++) cin >> v[i];
        stack<long long int> s;
        vector<long long int> ans(n,-1);
        for(int i = 0 ; i < n ; i++){
            while(!s.empty() and v[s.top()] < v[i]){
                ans[s.top()] = v[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0 ; i < n ; i++) cout << ans[i] << " ";
        cout << endl;
    }
}
