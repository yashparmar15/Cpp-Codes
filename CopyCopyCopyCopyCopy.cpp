#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		set<int> s;
		int temp;
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			s.insert(temp);
		}
		cout << s.size() << endl;
	}
}