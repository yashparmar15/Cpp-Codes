// You are given a permutation 𝑝1,𝑝2,…,𝑝𝑛. Recall that sequence of 𝑛 integers is called a permutation if it contains all integers from 1 to 𝑛 exactly once.

// Find three indices 𝑖, 𝑗 and 𝑘 such that:

// 1≤𝑖<𝑗<𝑘≤𝑛;
// 𝑝𝑖<𝑝𝑗 and 𝑝𝑗>𝑝𝑘.
// Or say that there are no such indices.
// Input
// The first line contains a single integer 𝑇 (1≤𝑇≤200) — the number of test cases.

// Next 2𝑇 lines contain test cases — two lines per test case. The first line of each test case contains the single integer 𝑛 (3≤𝑛≤1000) — the length of the permutation 𝑝.

// The second line contains 𝑛 integers 𝑝1,𝑝2,…,𝑝𝑛 (1≤𝑝𝑖≤𝑛; 𝑝𝑖≠𝑝𝑗 if 𝑖≠𝑗) — the permutation 𝑝.

// Output
// For each test case:

// if there are such indices 𝑖, 𝑗 and 𝑘, print YES (case insensitive) and the indices themselves;
// if there are no such indices, print NO (case insensitive).
// If there are multiple valid triples of indices, print any of them.

// Example
// inputCopy
// 3
// 4
// 2 1 4 3
// 6
// 4 6 1 2 5 3
// 5
// 5 3 1 2 4
// outputCopy
// YES
// 2 3 4
// YES
// 3 5 6
// NO



#include<bits/stdc++.h>
using namespace std;;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int> v;
		int temp;
		for(int i = 0 ; i < n ; i++){
			cin >> temp;
			v.push_back(temp);
		}
		vector<pair<int,int>> left,right;
		int min_so_far = v[0];
		int index = 0;
		for(int i = 0 ; i < n ; i++){
			if(v[i] < min_so_far){
				left.push_back(make_pair(v[i],i));
				min_so_far = v[i];
				index = i;
			} else {
				left.push_back(make_pair(min_so_far,index));
			}
		}
		min_so_far = v[n - 1];
		index = n - 1;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(v[i] < min_so_far){
				right.push_back(make_pair(v[i],i));
				min_so_far = v[i];
				index = i;
			} else {
				right.push_back(make_pair(min_so_far,index));
			}
		}
		reverse(right.begin(),right.end());
		bool notfound = true;
		for(int i = 0 ; i < n ; i++){
			if(v[i] > left[i].first and v[i] > right[i].first){
				cout << "YES\n";
				cout << left[i].second + 1 << " " << i + 1 << " " << right[i].second + 1 << "\n";
				notfound = false;
				break;
			}
		}
		if(notfound)
			cout << "NO\n";
	}
}