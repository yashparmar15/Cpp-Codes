#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc;
	cin >> tc;
	while(tc--){
	    int n,k,d;
	    cin >> n >> k >> d;
	    int s = 0;
	    int temp;
	    for(int i = 0 ; i < n ; i++){
	        cin >> temp;
	        s += temp;
	    }
	    int ans = s / k;
	    ans = min(ans,d);
	    cout << ans << endl;
	}
	return 0;
}
