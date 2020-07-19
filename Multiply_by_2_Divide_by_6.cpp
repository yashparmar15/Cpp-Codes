// You are given an integer 𝑛. In one move, you can either multiply 𝑛 by two or divide 𝑛 by 6 (if it is divisible by 6 without the remainder).

// Your task is to find the minimum number of moves needed to obtain 1 from 𝑛 or determine if it's impossible to do that.

// You have to answer 𝑡 independent test cases.

// Input
// The first line of the input contains one integer 𝑡 (1≤𝑡≤2⋅104) — the number of test cases. Then 𝑡 test cases follow.

// The only line of the test case contains one integer 𝑛 (1≤𝑛≤109).

// Output
// For each test case, print the answer — the minimum number of moves needed to obtain 1 from 𝑛 if it's possible to do that or -1 if it's impossible to obtain 1 from 𝑛.

// Example
// inputCopy
// 7
// 1
// 2
// 3
// 12
// 12345
// 15116544
// 387420489
// outputCopy
// 0
// -1
// 2
// -1
// -1
// 12
// 36
// Note
// Consider the sixth test case of the example. The answer can be obtained by the following sequence of moves from the given integer 15116544:

// Divide by 6 and get 2519424;
// divide by 6 and get 419904;
// divide by 6 and get 69984;
// divide by 6 and get 11664;
// multiply by 2 and get 23328;
// divide by 6 and get 3888;
// divide by 6 and get 648;
// divide by 6 and get 108;
// multiply by 2 and get 216;
// divide by 6 and get 36;
// divide by 6 and get 6;
// divide by 6 and get 1.


#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		bool notpossible = false;
		int count = 0;
		while(n != 1){
			if(n % 3 == 0 and n % 2 != 0){
				n = n * 2;
				count++;
			} else {
				if(n % 3){
					notpossible = true;
					break;
				} else {
					n = n / 6;
					count++;
				}
			}
		} 
		if(notpossible)
			cout << -1 << endl;
		else
			cout << count << endl;
	}

}