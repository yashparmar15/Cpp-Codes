#include<bits/stdc++.h>
using namespace std;


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int x , y , z;
		cin >> x >> y >> z;
		if(x == y and x == z)
			cout << "YES\n" << x << " " << x << " " << x << "\n"; 
		else{
			if(x != y and y != z and x != z)
				cout << "NO\n";
			else{
				if(y == z)
					if(x > z)
						cout << "NO\n";
					else
						cout << "YES\n" << x << " " << x << " " << y << "\n";
				else 
					if(x == y)
						if(z > y)
							cout << "NO\n";
						else
							cout << "YES\n" << x << " " << z << " " << z << "\n";
					else 
						if(x == z)
							if(y > x)
								cout << "NO\n";
							else
								cout << "YES\n" << y << " " << x << " " << y << "\n";
			}

		}
	}
}

// x == y == z
// x == y != z

