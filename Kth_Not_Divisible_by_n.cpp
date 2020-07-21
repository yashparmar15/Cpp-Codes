
// You are given two positive integers 𝑛 and 𝑘. Print the 𝑘-th positive integer that is not divisible by 𝑛.

// For example, if 𝑛=3, and 𝑘=7, then all numbers that are not divisible by 3 are: 1,2,4,5,7,8,10,11,13…. The 7-th number among them is 10.

// Input
// The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases in the input. Next, 𝑡 test cases are given, one per line.

// Each test case is two positive integers 𝑛 (2≤𝑛≤109) and 𝑘 (1≤𝑘≤109).

// Output
// For each test case print the 𝑘-th positive integer that is not divisible by 𝑛.

// Example
// inputCopy
// 6
// 3 7
// 4 12
// 2 1000000000
// 7 97
// 1000000000 1000000000
// 2 1
// outputCopy
// 10
// 15
// 1999999999
// 113
// 1000000001
// 1


#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , k;
		cin >> n >> k;
		if(k % (n - 1) == 0)
			cout << k + k / (n - 1) - 1 << "\n";
		else
			cout << k + k / (n - 1) << "\n";
	}
}