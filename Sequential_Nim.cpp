// There are 𝑛 piles of stones, where the 𝑖-th pile has 𝑎𝑖 stones. Two people play a game, where they take alternating turns removing stones.

// In a move, a player may remove a positive number of stones from the first non-empty pile (the pile with the minimal index, that has at least one stone). The first player who cannot make a move (because all piles are empty) loses the game. If both players play optimally, determine the winner of the game.

// Input
// The first line contains a single integer 𝑡 (1≤𝑡≤1000)  — the number of test cases. Next 2𝑡 lines contain descriptions of test cases.

// The first line of each test case contains a single integer 𝑛 (1≤𝑛≤105)  — the number of piles.

// The second line of each test case contains 𝑛 integers 𝑎1,…,𝑎𝑛 (1≤𝑎𝑖≤109)  — 𝑎𝑖 is equal to the number of stones in the 𝑖-th pile.

// It is guaranteed that the sum of 𝑛 for all test cases does not exceed 105.

// Output
// For each test case, if the player who makes the first move will win, output "First". Otherwise, output "Second".

// Example
// inputCopy
// 7
// 3
// 2 5 4
// 8
// 1 1 1 1 1 1 1 1
// 6
// 1 2 3 4 5 6
// 6
// 1 1 2 1 2 2
// 1
// 1000000000
// 5
// 1 2 2 1 1
// 3
// 1 1 1
// outputCopy
// First
// Second
// Second
// First
// First
// Second
// First
// Note
// In the first test case, the first player will win the game. His winning strategy is:

// The first player should take the stones from the first pile. He will take 1 stone. The numbers of stones in piles will be [1,5,4].
// The second player should take the stones from the first pile. He will take 1 stone because he can't take any other number of stones. The numbers of stones in piles will be [0,5,4].
// The first player should take the stones from the second pile because the first pile is empty. He will take 4 stones. The numbers of stones in piles will be [0,1,4].
// The second player should take the stones from the second pile because the first pile is empty. He will take 1 stone because he can't take any other number of stones. The numbers of stones in piles will be [0,0,4].
// The first player should take the stones from the third pile because the first and second piles are empty. He will take 4 stones. The numbers of stones in piles will be [0,0,0].



#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		int temp;
		vector<int> v;
		int count1 = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			v.push_back(temp);
			if(temp == 1)
				count1++;
		}
		if(count1 == n){
			if(count1 % 2 == 0)
				cout << "Second\n";
			else
				cout << "First\n";
		} else {
			int i = 0;
			while(v[i] == 1){
				i++;
			}
			if(i % 2 == 1)
				cout << "Second\n";
			else
				cout << "First\n";
		}

	}
}