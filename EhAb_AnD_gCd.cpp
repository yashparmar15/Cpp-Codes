/*You are given a positive integer 𝑥. Find any such 2 positive integers 𝑎 and 𝑏 such that 𝐺𝐶𝐷(𝑎,𝑏)+𝐿𝐶𝑀(𝑎,𝑏)=𝑥.

As a reminder, 𝐺𝐶𝐷(𝑎,𝑏) is the greatest integer that divides both 𝑎 and 𝑏. Similarly, 𝐿𝐶𝑀(𝑎,𝑏) is the smallest integer such that both 𝑎 and 𝑏 divide it.

It's guaranteed that the solution always exists. If there are several such pairs (𝑎,𝑏), you can output any of them.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤100)  — the number of testcases.

Each testcase consists of one line containing a single integer, 𝑥 (2≤𝑥≤109).

Output
For each testcase, output a pair of positive integers 𝑎 and 𝑏 (1≤𝑎,𝑏≤109) such that 𝐺𝐶𝐷(𝑎,𝑏)+𝐿𝐶𝑀(𝑎,𝑏)=𝑥. It's guaranteed that the solution always exists. If there are several such pairs (𝑎,𝑏), you can output any of them.

Example
inputCopy
2
2
14
outputCopy
1 1
6 4
Note
In the first testcase of the sample, 𝐺𝐶𝐷(1,1)+𝐿𝐶𝑀(1,1)=1+1=2.

In the second testcase of the sample, 𝐺𝐶𝐷(6,4)+𝐿𝐶𝑀(6,4)=2+12=14.*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        cout << "1 " << n - 1 << "\n";
    }
}
