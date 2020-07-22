// n Omkar's last class of math, he learned about the least common multiple, or 𝐿𝐶𝑀. 𝐿𝐶𝑀(𝑎,𝑏) is the smallest positive integer 𝑥 which is divisible by both 𝑎 and 𝑏.

// Omkar, having a laudably curious mind, immediately thought of a problem involving the 𝐿𝐶𝑀 operation: given an integer 𝑛, find positive integers 𝑎 and 𝑏 such that 𝑎+𝑏=𝑛 and 𝐿𝐶𝑀(𝑎,𝑏) is the minimum value possible.

// Can you help Omkar solve his ludicrously challenging math problem?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤10). Description of the test cases follows.

// Each test case consists of a single integer 𝑛 (2≤𝑛≤109).

// Output
// For each test case, output two positive integers 𝑎 and 𝑏, such that 𝑎+𝑏=𝑛 and 𝐿𝐶𝑀(𝑎,𝑏) is the minimum possible.

// Example
// inputCopy
// 3
// 4
// 6
// 9
// outputCopy
// 2 2
// 3 3
// 3 6
// Note
// For the first test case, the numbers we can choose are 1,3 or 2,2. 𝐿𝐶𝑀(1,3)=3 and 𝐿𝐶𝑀(2,2)=2, so we output 2 2.

// For the second test case, the numbers we can choose are 1,5, 2,4, or 3,3. 𝐿𝐶𝑀(1,5)=5, 𝐿𝐶𝑀(2,4)=4, and 𝐿𝐶𝑀(3,3)=3, so we output 3 3.

// For the third test case, 𝐿𝐶𝑀(3,6)=6. It can be shown that there are no other pairs of numbers which sum to 9 that have a lower 𝐿𝐶𝑀.




#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		if(n % 2 == 0)
			cout << n / 2 << " " << n / 2 << "\n";
		else{
			int ans = -1;
			for(int i = 2 ; i * i <= n ; i++){
				if((n - i) % i == 0){
					ans = max(ans,i);
				}
				if(n % (n / i) == 0){
					ans = max(ans , n / i);
				}
			}
			if(ans == -1) ans = 1;
			cout << ans << " " << n - ans << "\n";
		}
	}
}