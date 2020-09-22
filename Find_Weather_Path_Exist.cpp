#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(long long int i = a;i < b;i++)
#define ll long long 
void dfs(vector<vector<int>> &v,int x,int y,bool &ans){
    if(x >= v.size() or y >= v[0].size() or x < 0 or y < 0 or v[x][y] <= 0 or ans) return;
    if(v[x][y] == 2) ans = true;
    v[x][y] = -1;
    dfs(v,x+1,y,ans);
    dfs(v,x-1,y,ans);
    dfs(v,x,y+1,ans);
    dfs(v,x,y-1,ans);
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        vector<vector<int>> v(N,vector<int>(N,0));
        int sx = 0,sy = 0;
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++){
                cin >> v[i][j];
                if(v[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        bool ans = false;
        dfs(v,sx,sy,ans);
        if(ans) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
