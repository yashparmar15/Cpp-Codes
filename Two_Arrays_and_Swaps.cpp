#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n,k;
		int temp;
		cin >> n >> k;
		vector<int> a,b;
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			a.push_back(temp);
		}
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			b.push_back(temp);
		}
		sort(b.begin(),b.end());
		reverse(b.begin(),b.end());
		sort(a.begin(),a.end());
		int i = 0;
		int ans = 0;
		while(i < k){
			ans = ans + max(b[i],a[i]);
			i++;
		}
		
		reverse(a.begin(),a.end());
		int j = 0;
		while(i < n){
			ans = ans + a[j];
			i++;
			j++;
		}
		cout << ans << "\n";
	}
}