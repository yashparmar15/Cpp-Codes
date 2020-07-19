// Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

// What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

// Input
// The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 109).

// Output
// Write the needed number of flagstones.

// Examples
// inputCopy
// 6 6 4
// outputCopy
// 4


#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n , m , a;
	cin >> n >> m >> a;
	long long int row,column;
	if(n % a == 0)
		row = n / a;
	else
		row = n / a + 1;
	if(m % a == 0)
		column = m / a;
	else
		column = m / a + 1;
	long long int ans = row * column;
	cout << ans << "\n";
}