#include<bits/stdc++.h>

using namespace std;

void helper(int i, string s, string ans)
{
    if(i==s.size())
    {
        cout << ans << " ";
        return;
    }
    if(s[i]=='?')
    {
        helper(i+1, s, ans + '0');
        helper(i+1, s, ans+'1');
    }
    else
    {
        helper(i+1, s, ans+s[i]);
    }
}



int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        string s;
        cin >> s;
        
        string ans;
        
        helper(0, s, ans);
        
        cout << endl;
    }
}
