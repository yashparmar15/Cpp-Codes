// You are given two arrays of integers 𝑎1,…,𝑎𝑛 and 𝑏1,…,𝑏𝑚.

// Your task is to find a non-empty array 𝑐1,…,𝑐𝑘 that is a subsequence of 𝑎1,…,𝑎𝑛, and also a subsequence of 𝑏1,…,𝑏𝑚. If there are multiple answers, find one of the smallest possible length. If there are still multiple of the smallest possible length, find any. If there are no such arrays, you should report about it.

// A sequence 𝑎 is a subsequence of a sequence 𝑏 if 𝑎 can be obtained from 𝑏 by deletion of several (possibly, zero) elements. For example, [3,1] is a subsequence of [3,2,1] and [4,3,1], but not a subsequence of [1,3,3,7] and [3,10,4].

// Input
// The first line contains a single integer 𝑡 (1≤𝑡≤1000)  — the number of test cases. Next 3𝑡 lines contain descriptions of test cases.

// The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛,𝑚≤1000)  — the lengths of the two arrays.

// The second line of each test case contains 𝑛 integers 𝑎1,…,𝑎𝑛 (1≤𝑎𝑖≤1000)  — the elements of the first array.

// The third line of each test case contains 𝑚 integers 𝑏1,…,𝑏𝑚 (1≤𝑏𝑖≤1000)  — the elements of the second array.

// It is guaranteed that the sum of 𝑛 and the sum of 𝑚 across all test cases does not exceed 1000 (∑𝑖=1𝑡𝑛𝑖,∑𝑖=1𝑡𝑚𝑖≤1000).

// Output
// For each test case, output "YES" if a solution exists, or "NO" otherwise.

// If the answer is "YES", on the next line output an integer 𝑘 (1≤𝑘≤1000)  — the length of the array, followed by 𝑘 integers 𝑐1,…,𝑐𝑘 (1≤𝑐𝑖≤1000)  — the elements of the array.

// If there are multiple solutions with the smallest possible 𝑘, output any.

// Example
// inputCopy
// 5
// 4 5
// 10 8 6 4
// 1 2 3 4 5
// 1 1
// 3
// 3
// 1 1
// 3
// 2
// 5 3
// 1000 2 2 2 3
// 3 1 5
// 5 5
// 1 2 3 4 5
// 1 2 3 4 5
// outputCopy
// YES
// 1 4
// YES
// 1 3
// NO
// YES
// 1 3
// YES
// 1 2
// Note
// In the first test case, [4] is a subsequence of [10,8,6,4] and [1,2,3,4,5]. This array has length 1, it is the smallest possible length of a subsequence of both 𝑎 and 𝑏.

// In the third test case, no non-empty subsequences of both [3] and [2] exist, so the answer is "NO".


#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , m;
		cin >> n >> m;
		unordered_map<int,int> M;
		int temp;
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			M[temp] = 1;
		}
		int ans = -1;
		for(int i = 0 ; i < m ; i++){
			cin >> temp;
			if(M[temp])
				ans = temp;
		}
		if(ans == -1)
			cout << "NO\n";
		else
			cout << "YES\n1 " << ans << "\n";
	}
}