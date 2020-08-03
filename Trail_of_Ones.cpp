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
        if(n == 0)
            cout << 0 << endl;
        else{
            if(n == 1)
                cout << 1 << endl;
            else{
                vector<long long> dp(n+1,0);
                dp[1] = 0;
                dp[2] = 1;
                for(int i = 3 ; i <= n ; i++){
                    dp[i] = dp[i - 1] + dp[i - 2] + pow(2,i - 2);
                }
                cout << dp[n] << endl;
            }
        }
    }
}
