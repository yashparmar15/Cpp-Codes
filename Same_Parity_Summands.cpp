// You are given two positive integers 𝑛 (1≤𝑛≤109) and 𝑘 (1≤𝑘≤100). Represent the number 𝑛 as the sum of 𝑘 positive integers of the same parity (have the same remainder when divided by 2).

// In other words, find 𝑎1,𝑎2,…,𝑎𝑘 such that all 𝑎𝑖>0, 𝑛=𝑎1+𝑎2+…+𝑎𝑘 and either all 𝑎𝑖 are even or all 𝑎𝑖 are odd at the same time.

// If such a representation does not exist, then report it.

// Input
// The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases in the input. Next, 𝑡 test cases are given, one per line.

// Each test case is two positive integers 𝑛 (1≤𝑛≤109) and 𝑘 (1≤𝑘≤100).

// Output
// For each test case print:

// YES and the required values 𝑎𝑖, if the answer exists (if there are several answers, print any of them);
// NO if the answer does not exist.
// The letters in the words YES and NO can be printed in any case.

// Example
// inputCopy
// 8
// 10 3
// 100 4
// 8 7
// 97 2
// 8 8
// 3 10
// 5 3
// 1000000000 9
// outputCopy
// YES
// 4 2 4
// YES
// 55 5 5 35
// NO
// NO
// YES
// 1 1 1 1 1 1 1 1
// NO
// YES
// 3 1 1
// YES
// 111111110 111111110 111111110 111111110 111111110 111111110 111111110 111111110 111111120


#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , k;
		cin >> n >> k;
		bool exist = true;
		if((n - k + 1) % 2 == 1 and n - k + 1 > 0){
			cout << "YES\n";
			for(int i = 0 ; i < k - 1 ; i++)
				cout <<"1 ";
			cout << (n - k + 1) << "\n";
		} else {
			if((n - 2*k + 2) % 2 == 0 and n - 2*k + 2 > 0){
				cout << "YES\n";
				for(int i = 0 ; i < k - 1 ; i++)
					cout <<"2 ";
				cout << (n - 2*k + 2) << "\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}