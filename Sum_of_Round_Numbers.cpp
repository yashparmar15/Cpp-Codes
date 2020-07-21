// A positive (strictly greater than zero) integer is called round if it is of the form d00...0. In other words, a positive integer is round if all its digits except the leftmost (most significant) are equal to zero. In particular, all numbers from 1 to 9 (inclusive) are round.

// For example, the following numbers are round: 4000, 1, 9, 800, 90. The following numbers are not round: 110, 707, 222, 1001.

// You are given a positive integer 𝑛 (1≤𝑛≤104). Represent the number 𝑛 as a sum of round numbers using the minimum number of summands (addends). In other words, you need to represent the given number 𝑛 as a sum of the least number of terms, each of which is a round number.

// Input
// The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases in the input. Then 𝑡 test cases follow.

// Each test case is a line containing an integer 𝑛 (1≤𝑛≤104).

// Output
// Print 𝑡 answers to the test cases. Each answer must begin with an integer 𝑘 — the minimum number of summands. Next, 𝑘 terms must follow, each of which is a round number, and their sum is 𝑛. The terms can be printed in any order. If there are several answers, print any of them.

// Example
// inputCopy
// 5
// 5009
// 7
// 9876
// 10000
// 10
// outputCopy
// 2
// 5000 9
// 1
// 7 
// 4
// 800 70 6 9000 
// 1
// 10000 
// 1
// 10 


#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n ;
		cin >> n;
		int p = 10;
		int count = 1;
		vector<int> ans;
		while(n > 0){
			int num = n % p;
			if(num != 0)
				ans.push_back(num * count);	
			n = n / 10;
			count = count*10;
		}
		cout << ans.size() << "\n";
		for(int i = 0 ; i < ans.size() - 1 ; i++){
			cout << ans[i] << " ";
		}
		cout << ans[ans.size() - 1] << "\n";
	}
}