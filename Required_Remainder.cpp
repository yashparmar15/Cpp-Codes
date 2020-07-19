// You are given three integers 𝑥,𝑦 and 𝑛. Your task is to find the maximum integer 𝑘 such that 0≤𝑘≤𝑛 that 𝑘mod𝑥=𝑦, where mod is modulo operation. Many programming languages use percent operator % to implement it.

// In other words, with given 𝑥,𝑦 and 𝑛 you need to find the maximum possible integer from 0 to 𝑛 that has the remainder 𝑦 modulo 𝑥.

// You have to answer 𝑡 independent test cases. It is guaranteed that such 𝑘 exists for each test case.

// Input
// The first line of the input contains one integer 𝑡 (1≤𝑡≤5⋅104) — the number of test cases. The next 𝑡 lines contain test cases.

// The only line of the test case contains three integers 𝑥,𝑦 and 𝑛 (2≤𝑥≤109; 0≤𝑦<𝑥; 𝑦≤𝑛≤109).

// It can be shown that such 𝑘 always exists under the given constraints.

// Output
// For each test case, print the answer — maximum non-negative integer 𝑘 such that 0≤𝑘≤𝑛 and 𝑘mod𝑥=𝑦. It is guaranteed that the answer always exists.

// Example
// inputCopy
// 7
// 7 5 12345
// 5 0 4
// 10 5 15
// 17 8 54321
// 499999993 9 1000000000
// 10 5 187
// 2 0 999999999
// outputCopy
// 12339
// 0
// 15
// 54306
// 999999995
// 185
// 999999998
// Note
// In the first test case of the example, the answer is 12339=7⋅1762+5 (thus, 12339mod7=5). It is obvious that there is no greater integer not exceeding 12345 which has the remainder 5 modulo 7.





#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int x , y , n;
		cin >> x >> y >> n;
		int r = n % x;
		if(r >=	 y)
			cout << n - r + y << "\n";
		else
			cout << n - x - r + y << "\n";
	}
}