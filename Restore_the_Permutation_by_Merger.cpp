/*A permutation of length 𝑛 is a sequence of integers from 1 to 𝑛 of length 𝑛 containing each number exactly once. For example, [1], [4,3,5,1,2], [3,2,1] are permutations, and [1,1], [0,1], [2,2,1,4] are not.

There was a permutation 𝑝[1…𝑛]. It was merged with itself. In other words, let's take two instances of 𝑝 and insert elements of the second 𝑝 into the first maintaining relative order of elements. The result is a sequence of the length 2𝑛.

For example, if 𝑝=[3,1,2] some possible results are: [3,1,2,3,1,2], [3,3,1,1,2,2], [3,1,3,1,2,2]. The following sequences are not possible results of a merging: [1,3,2,1,2,3], [3,1,2,3,2,1], [3,3,1,2,2,1].

For example, if 𝑝=[2,1] the possible results are: [2,2,1,1], [2,1,2,1]. The following sequences are not possible results of a merging: [1,1,2,2], [2,1,1,2], [1,2,2,1].

Your task is to restore the permutation 𝑝 by the given resulting sequence 𝑎. It is guaranteed that the answer exists and is unique.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤400) — the number of test cases. Then 𝑡 test cases follow.

The first line of the test case contains one integer 𝑛 (1≤𝑛≤50) — the length of permutation. The second line of the test case contains 2𝑛 integers 𝑎1,𝑎2,…,𝑎2𝑛 (1≤𝑎𝑖≤𝑛), where 𝑎𝑖 is the 𝑖-th element of 𝑎. It is guaranteed that the array 𝑎 represents the result of merging of some permutation 𝑝 with the same permutation 𝑝.

Output
For each test case, print the answer: 𝑛 integers 𝑝1,𝑝2,…,𝑝𝑛 (1≤𝑝𝑖≤𝑛), representing the initial permutation. It is guaranteed that the answer exists and is unique.

Example
inputCopy
5
2
1 1 2 2
4
1 3 1 4 3 4 2 2
5
1 2 1 2 3 4 3 5 4 5
3
1 2 3 1 2 3
4
2 3 2 4 1 3 4 1
outputCopy
1 2 
1 3 4 2 
1 2 3 4 5 
1 2 3 
2 3 4 1 
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n ;
		cin >> n;
		vector<int> v;
		unordered_map<int,int> M;
		for(int i = 0 ; i < 2*n ; i++){
			int temp;
			cin >> temp;
			M[temp]++;
			if(M[temp] == 1)
				v.push_back(temp);
		}
		for(int i = 0 ; i < n - 1 ; i++){
			cout << v[i] << " ";
		}
		cout << v[n - 1] << "\n";
	}
}
