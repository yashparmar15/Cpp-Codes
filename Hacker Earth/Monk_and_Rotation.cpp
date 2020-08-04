
#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n,k;
		cin >> n >> k;
		vector<int> v;
		vector<int> ans;
		int temp;
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			v.push_back(temp);
		}
		k = k % n;
		for(int i = n - k ; i < n ; i++){
			ans.push_back(v[i]);
		}
		for(int i = 0 ; i < n - k ; i++){
			ans.push_back(v[i]);
		}
		for(int i = 0 ; i < ans.size() ; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}
