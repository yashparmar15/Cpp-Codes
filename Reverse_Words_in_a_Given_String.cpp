#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = a;i < b;i++)
#define ll long long 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        string ans = "";
        string word = "";
        F(i,0,s.size()){
            if(s[i] == '.'){
                ans = "." + word + ans;
                word = "";
            } else {
                word = word + s[i];
            }
        }
        ans = word + ans;
        cout << ans << "\n";
    }
}
